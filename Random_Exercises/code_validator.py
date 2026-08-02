def validate_code(code: str) -> str:
    # Your logic here
    special_symbols = ['!', '@', '#', '$', '%', '&']
    code = code.lower()

    count = 0
    for i in code:
        if i in special_symbols:
            count += 1
    
        if not (code[0].isalpha() and code[-2:].isnumeric() and count == 1): 
            return "VALID"
        elif not (code[i].isspace()):
            return "VALID"
        elif int(code[-2]) + int(code[-1]) % 3 == 0:
            return "HIGH SECURITY"
        else:
            return "INVALID"


def main():
    print(validate_code("A7@21"))        # "HIGH SECURITY"   (Starts with letter, ends with 21, 2+1 = 3 ✔)
    print(validate_code("z$80"))         # "VALID"           (Valid, 8+0 = 8 ❌)
    print(validate_code("5@123"))        # "INVALID"         (Doesn't start with a letter ❌)
    print(validate_code("M@123!"))       # "INVALID"         (More than one special character ❌)
    print(validate_code("B@ 12"))        # "INVALID"         (Contains whitespace ❌)
    print(validate_code("@A123"))        # "INVALID"         (Starts with a special character ❌)

main()