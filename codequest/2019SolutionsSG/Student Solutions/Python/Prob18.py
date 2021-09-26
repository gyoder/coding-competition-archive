def square(a, b):
    return (a*a - b*b, 2*a*b)

def add(a1, b1, a2, b2):
    return (a1 + a2, b1 + b2)

def modulus(a, b):
    return (a*a + b*b)

for t in range(int(input())):
    A, B = input().split()
    a, b = float(A), float(B)
    a1, b1 = 0, 0
    if b == 0:
        print(A, end=' ')
    elif a == 0:
        print(B, 'i', sep='', end=' ')
    else:
        if b > 0:
            print(A, '+', B, 'i', end=' ', sep='')
        else:
            print(A, B, 'i', end=' ', sep='')
    for n in range(1, 52):
        a1, b1 = add(*square(a1, b1), a, b)
        #print(n, a1, b1, modulus(a1, b1))
        if modulus(a1, b1) > 10000:
            if n <= 10:
                print("RED")
                break
            elif n <= 20:
                print("ORANGE")
                break
            elif n <= 30:
                print("YELLOW")
                break
            elif n <= 40:
                print("GREEN")
                break
            elif n <= 50:
                print("BLUE")
                break
    else:
        print("BLACK")

    
