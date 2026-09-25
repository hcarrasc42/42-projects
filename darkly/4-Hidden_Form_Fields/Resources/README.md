# Hidden Form Fields Exposure

## Vulnerability
Sensitive information is stored in `<input type="hidden">` fields on the password recovery form, visible and modifiable client-side.

## Exploitation
1. Navigate to `?page=recover`
2. Open DevTools (F12) → Inspector
3. Find: `<input type="hidden" name="mail" value="webmaster@borntosec.com" maxlength="15">`
4. Change `type="hidden"` to `type="text"`
5. Modify the value of the field (enter any text)
6. Click Submit → flag revealed: `1D4855F7337C0C14B6F44946872C4EB33853F40B2D54393FBE94F49F1E19BBB0`

## Impact
Exposure of sensitive data. Attackers can read and manipulate hidden fields to bypass security logic (e.g. changing prices, user IDs, permissions).

## Prevention
- Never store sensitive data in the client (hidden fields, JS variables, unencrypted cookies)
- Process all sensitive logic server-side
- Use server-side sessions to track state
