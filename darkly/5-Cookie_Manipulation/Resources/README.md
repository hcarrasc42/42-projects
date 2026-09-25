# Cookie Manipulation

## Vulnerability
The authorization cookie uses a predictable, unsigned MD5 hash that can be easily forged.

## Exploitation
1. Open DevTools → Application → Cookies
2. Find cookie: `I_am_admin=68934a3e9455fa72420237eb05902327`
3. Identify hash: MD5("false") = `68934a3e9455fa72420237eb05902327`
4. Compute: MD5("true") = `b326b5062b2f0e69046810717534cb09`
5. Replace cookie value with `b326b5062b2f0e69046810717534cb09`
6. Reload page → admin access granted, flag revealed

## Impact
Privilege escalation. Any user can forge admin cookies to gain unauthorized access.

## Prevention
- Use signed tokens (JWT with strong secret) or server-side sessions
- Never store authorization logic in client-controlled cookies
- Implement HMAC signatures on cookies
- Use `HttpOnly` and `Secure` cookie flags
