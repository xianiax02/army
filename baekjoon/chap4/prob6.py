import sys
n,m=input().split()
n=int(n)
m=int(m)
baskets=[]
for i in range(n):
    baskets.append(i+1)

for i in range(m):
    a,b=list(map(int,sys.stdin.readline().split(' ')))
    baskets[a-1],baskets[b-1]=baskets[b-1],baskets[a-1]
#   print(i,'times')
#    for i in range(n):
#        print(baskets[i],end=' ')
for i in range(n):
    print(baskets[i],end=' ')
    
