def isCorrectPwd(decoded_pwd):
    sum = 0
    result = 0
    for i in range(0, 8) :
        if (i+1)%2 != 0:
            sum += 3*int(decoded_pwd[i])
        else:
            sum += int(decoded_pwd[i])
        result += int(decoded_pwd[i])
    if sum%10 == 0:
        return result
    else:
        return 0


number_list = ['0001101', '0011001', '0010011', '0111101', '0100011',
               '0110001', '0101111', '0111011', '0110111', '0001011']

T = int(input())

for t in range(1, T+1) :
    N, M = map(int, input().split())
    password = [list(input())[:M] for _ in range(N)]
    encoded_pwd, decoded_pwd = list(), list()

    for _ in range(N):
        if ('1' in password[_]) :
            for i in range(M-1,-1,-1) :
                if password[_][i] == '1' :
                    encoded_pwd = password[_][i-55:i+1]
                    break
    for i in range(8) :
        number = "".join(encoded_pwd[7*i:7*i+7])
        decoded_pwd.append(number_list.index(number))
    result = isCorrectPwd(decoded_pwd)
    print(f"#{t} {result}")
