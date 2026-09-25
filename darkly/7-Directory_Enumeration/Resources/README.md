# Directory Enumeration + Information Disclosure

## Vulnerability
The `/.hidden/` directory is publicly accessible with directory listing enabled, containing thousands of files spread across nested subdirectories.

## Exploitation
1. Visit `/robots.txt` → reveals `/.hidden/`
2. The directory contains 26 subdirectories, each with more subdirectories and `README` files
3. Run the recursive script to find the README with unique content:
   ```
   cd Directory_Enumeration/Resources/
   python3 explore_hidden.py
   ```
4. Only one README has different content:
   - URL: `/.hidden/whtccjokayshttvxycsvykxcfm/igeemtxnvexvxezqwntmzjltkt/lmpanswobhwcozdqixbowvbrhw/README`
   - Content: "Hey, here is your flag : d5eec3ec36cf80dce44a896f961c1831a05526ec215693c8f2c39543497d4466"

## Impact
Exposure of sensitive files. Information disclosure that can aid further attacks.

## Prevention
- Never list sensitive paths in `robots.txt` (it acts as a roadmap for attackers)
- Disable directory listing on the web server (`Options -Indexes` in Apache)
- Protect sensitive directories with authentication
