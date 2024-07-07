import sys
total=int(input())
mq=int(input())
result=0
for i in range(mq):
    p,q=sys.stdin.readline().split()
    p=int(p)
    q=int(q)
    result+=p*q
if (result==total):
    print('Yes')
else:
    print('No')
    
    

