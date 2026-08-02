def validate_code(code: str) -> str:
    special_symbols = ['!', '@', '#', '$', '%', '&']

    # Rule 2 - Check for invalid conditions first
    if any(c.isspace() for c in code):
        return "INVALID"
    
    if code[0] in special_symbols or code[-1] in special_symbols:
        return "INVALID"

    # Count special symbols
    special_count = sum(1 for c in code if c in special_symbols)
    if special_count != 1:
        return "INVALID"
    
    # Rule 1 - Basic valid structure
    if not code[0].isalpha():
        return "INVALID"
    
    if len(code) < 3 or not code[-1].isdigit() or not code[-2].isdigit():
        return "INVALID"
    
    # If it passed all checks, it's valid
    # Now check for HIGH SECURITY
    last_two_digits_sum = int(code[-1]) + int(code[-2])
    if last_two_digits_sum % 3 == 0:
        return "HIGH SECURITY"
    
    return "VALID"
