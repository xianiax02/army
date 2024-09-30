import sys
num=int(input())
for i in range(num):
    a,b=sys.stdin.readline().split()
    a=int(a)
    for i in b:
        print(i*a,end='')
    print()
    
    
