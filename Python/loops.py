def square_integers(n):
    for i in range(n):
        square = i*i
        print(square)
        

if __name__ == '__main__':
    n = int(input())
    square_integers(n)