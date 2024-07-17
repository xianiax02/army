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
    
for i in range(m):
    print(baskets[i],end=' ')


