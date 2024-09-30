import sys
n,m=sys.stdin.readline().split(' ')
n=int(n)
m=int(m)
baskets=[]
for i in range(n):
    baskets.append(0)
for i in range(m):
    a,b,c=sys.stdin.readline().split(' ')
    a=int(a)
    b=int(b)
    c=int(c)
    for i in range(a,b+1): #여기는 2에서 5번까지라하면 닫힌 구간임을 고려하지 못
        baskets[i-1]=c
#    for i in range(len(baskets)):
 #       print(baskets[i],end=' ')
  #  print()
for i in range(len(baskets)):
    print(baskets[i],end=' ')
    

