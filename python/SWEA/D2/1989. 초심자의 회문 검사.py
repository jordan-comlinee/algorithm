t = int(input())

for _ in range(1, t+1):
    word = list(input())
    isPalindrome = 1
    for i in range(0, len(word)//2):
        if (word[i] != word[len(word)-i-1]) :
            isPalindrome = 0
    print(f"#{_} {isPalindrome}")