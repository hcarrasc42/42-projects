# Form Value Manipulation (Survey)

## Vulnerability
The survey form uses a `<SELECT>` element with values 1-10, but the server never validates the submitted value server-side.

## Exploitation
1. Navigate to `?page=survey`
2. Open DevTools (F12) → Inspector
3. Find a `<option value="10">` element in the SELECT
4. Change the value attribute to an out-of-range number: `value="99999999"`
5. Select that option → form submits automatically with the manipulated value
6. Server accepts it without validation and returns the flag

## Impact
Attackers can bypass any client-side business logic: manipulate prices, quantities, ratings, vote counts, etc.

## Prevention
- Always validate input server-side, regardless of client-side constraints
- Verify submitted values are within the allowed range
- Never trust any data coming from the client
