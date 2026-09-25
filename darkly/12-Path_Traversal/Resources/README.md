# Path Traversal / Local File Inclusion (LFI)

## Vulnerability
The `?page=` parameter is used to load files without sanitizing the path, allowing directory traversal.

## Exploitation
1. The site loads pages via `?page=<name>`
2. Use `../` sequences to traverse up to the filesystem root
3. Payload: `?page=../../../../../../../etc/passwd`
4. The server reads and returns `/etc/passwd`, revealing the flag

## Impact
An attacker can read any file accessible to the web server process: config files, SSH keys, `/etc/shadow`, application source code, credentials.

## Prevention
- Sanitize the `page` parameter: strip `../` and null bytes
- Use a whitelist of allowed page names
- Never construct file paths directly from user input
- Use `realpath()` and verify the resolved path is within the allowed directory
