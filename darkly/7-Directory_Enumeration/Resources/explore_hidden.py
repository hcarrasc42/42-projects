#!/usr/bin/env python3

import requests
from bs4 import BeautifulSoup
from urllib.parse import urljoin
import re

BASE_URL = "http://127.0.0.1:8080/.hidden/"
visited = set()
found_flags = []

def explore_directory(url, depth=0):
    """Explora recursivamente directorios buscando archivos"""
    
    # Limitar profundidad
    if depth > 15:
        return
    
    # Evitar visitar la misma URL dos veces
    if url in visited:
        return
    
    visited.add(url)
    print(f"{'  ' * depth}[*] Explorando: {url}")
    
    try:
        response = requests.get(url, timeout=5)
        
        if response.status_code != 200:
            return
        
        soup = BeautifulSoup(response.text, 'html.parser')
        
        # Buscar todos los enlaces
        for link in soup.find_all('a'):
            href = link.get('href')
            
            if not href or href in ['..', '../', '/', '.']:
                continue
            
            # Construir URL completa
            full_url = urljoin(url, href)
            
            # Si termina en /, es un directorio
            if href.endswith('/'):
                explore_directory(full_url, depth + 1)
            else:
                # Es un archivo
                print(f"{'  ' * depth}[+] Archivo: {full_url}")
                check_file(full_url, depth)
    
    except Exception as e:
        print(f"{'  ' * depth}[!] Error en {url}: {e}")

def check_file(url, depth):
    """Verifica si un archivo contiene información interesante"""
    try:
        response = requests.get(url, timeout=5)
        content = response.text
        
        # Buscar patrones de flags o hashes
        if re.search(r'flag|[a-f0-9]{32,}', content, re.IGNORECASE):
            print(f"{'  ' * depth}    [!!!] POSIBLE FLAG ENCONTRADA")
            print(f"{'  ' * depth}    URL: {url}")
            print(f"{'  ' * depth}    Contenido: {content[:200]}")
            print(f"{'  ' * depth}    ---")
            found_flags.append({'url': url, 'content': content})
    
    except Exception as e:
        print(f"{'  ' * depth}    [!] Error leyendo archivo: {e}")

if __name__ == "__main__":
    print("=" * 60)
    print("Explorando el directorio .hidden recursivamente...")
    print("=" * 60)
    
    explore_directory(BASE_URL)
    
    print("\n" + "=" * 60)
    print(f"Exploración completada. Archivos visitados: {len(visited)}")
    
    if found_flags:
        print(f"\n[!] Se encontraron {len(found_flags)} posibles flags:")
        for i, flag_info in enumerate(found_flags, 1):
            print(f"\n{i}. URL: {flag_info['url']}")
            print(f"   Contenido: {flag_info['content']}")
    else:
        print("\n[!] No se encontraron flags evidentes")
    
    print("=" * 60)