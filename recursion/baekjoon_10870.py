n = int(input())
f1 = 1
f2 = fn = 0

if n < 2:
    print(n)
    exit()
    
else:
    for i in range(n-1):
        fn = f1 + f2
        f2 = f1
        f1 = fn
    print(fn)
    exit()
    
