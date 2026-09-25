# XSS - Comment Form

## Vulnerability
The comment form does not sanitize user input. Injecting special characters (like `"`) causes the site to execute unexpected code and reveal the flag.

## Exploitation
1. Navigate to `?page=feedback`
2. In the **Name** field enter: `<script>alert()</script>`
3. Fill in any value for the Message field
4. Click Send → flag revealed

## Impact
An attacker could inject malicious JavaScript that executes in other users' browsers (stored XSS), enabling session hijacking, credential theft, or defacement.

## Prevention
- Validate and sanitize all user input server-side
- Escape special HTML characters (`<`, `>`, `"`, `'`, `&`)
- Implement Content Security Policy (CSP) headers
- Use a library like DOMPurify for output encoding
