# Weak Authentication + Exposed Credentials

## Vulnerability
The `.htpasswd` file is publicly accessible and the password is weak (MD5 hash, easily crackable).

## Exploitation
1. Visit `/robots.txt` → reveals `/whatever` directory
2. Access `http://127.0.0.1:8080/whatever/htpasswd`
3. File contains: `root:437394baff5aa33daa618be47b75cb49`
4. Crack the MD5 hash (e.g. via crackstation.net or hashcat): `qwerty123@`
5. Visit `http://127.0.0.1:8080/admin/` → login with `root:qwerty123@`
6. Flag revealed: `d19b4823e0d5600ceed56d5e896ef328d7a2b9e7ac7e80f4fcdb9b10bcb3e7ff`

## Impact
Unauthorized access to admin areas. Full administrative control of the application.

## Prevention
- Never expose `.htpasswd` or config files publicly
- Use strong passwords with bcrypt or Argon2 (not MD5)
- Enable two-factor authentication (2FA)
- Restrict admin access by IP or VPN
