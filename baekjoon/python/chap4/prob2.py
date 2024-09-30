n,x=input().split()
n=int(n)
x=int(x)
l=list(map(int,input().split()))
result=[]
for i in range(n):
    if (l[i]<x):
        result.append(l[i])
for i in range(len(result)):
    print(result[i],end=' ')

