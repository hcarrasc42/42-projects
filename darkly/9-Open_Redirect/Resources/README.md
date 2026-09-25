# Open Redirect

## Vulnerability
Social media links in the footer use an unvalidated `?site=` parameter that redirects to any URL.

## Exploitation
1. Inspect the footer social media links in page source
2. Observe URLs like: `?site=facebook`, `?site=twitter`
3. Modify the parameter to an arbitrary URL: `?site=https://www.instagram.com`
4. The server redirects without validation, revealing the flag

## Impact
Attackers can redirect victims to phishing sites while abusing the legitimate domain's trust (e.g. in emails or messages).

## Prevention
- Validate redirect targets against a whitelist of allowed domains
- Use internal route identifiers instead of full URLs in parameters
- Reject or ignore the `site` parameter for external domains
