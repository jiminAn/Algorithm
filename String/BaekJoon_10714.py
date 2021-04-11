n = int(input())

for i in range(n):
    s = input().lower()
    palindrome_flag = True
    len_s = len(s)

    for j in range(int(len_s/2)):
        if s[j] != s[len_s - j - 1]:
            palindrome_flag = False
            break
    if palindrome_flag:
        print('Yes')
    else:
        print('No')
