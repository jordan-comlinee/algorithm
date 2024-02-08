def main(n) :
    while(n != 1) :
        for i in range(2, n + 1):
            if (n % i == 0):
                n = n//i
                print(i)
                break


n = int(input())
main(n)