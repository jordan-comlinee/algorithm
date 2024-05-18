for t in range(1, 11):
    N, password = map(int, input().split())
    password = list(str(password))
    isSame = True
    while (isSame == True):
        for i in range(len(password)-1):
            if password[i] == password[i+1]:
                password = password[:i]+password[i+2:]
                break
            if i == len(password)-2 :
                isSame = False
    result = "".join(password)
    print(f"#{t} {int(result)}")