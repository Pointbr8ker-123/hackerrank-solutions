def print_consec(n):
    output = ""
    for i in range(1, n+1):
        output += str(i)
        
    return output


if __name__ == '__main__':
    n = int(input())
    print(print_consec(n))
