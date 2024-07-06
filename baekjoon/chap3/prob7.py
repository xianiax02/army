import sys
test=int(input())
for i in range(test):
    a,b=map(int,sys.stdin.readline().split(" "))
    print("Case #{0}: ".format(i+1),end='')
    print(a+b)

    
