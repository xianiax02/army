import sys
m,n=input().split()
m=int(m)
n=int(n)
baskets=[]
for i in range(m):
    baskets.append(i+1)

for a in range(n):
    i,j=list(map(int,sys.stdin.readline().split(' ')))
    change=baskets[i+1:j+2]
    change.reverse()
    for k in range(i-j+1):
        baskets[k]=change[k]
    print()
    print(a,'time',end='')
    for k in range(m):
        print(baskets[k],end=' ')
    print('change')
    print(a,'time',end='')
    for k in range(m):
        print(baskets[k],end=' ')
        
    
for i in range(m):
    print(baskets[i],end=' ')


