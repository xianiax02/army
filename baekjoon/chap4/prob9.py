import sys
m,n=input().split()
m=int(m)
n=int(n)
baskets=[]
for i in range(m):
    baskets.append(i+1)

def partlyreverse(llist,a,b):  #llist[a] 부터 llist[b-1]까지
    temp=[]
    for i in range(a,b):
        temp.append(llist[i]) #len(temp)=b-a  temp의 인덱스 -> 0~ b-a-1
    for i in range(a,b):
        llist[i]=temp[b-i-1] #i는 a부터 시작 b-1로 끝남
    return llist    
        



for a in range(n):
    i,j=list(map(int,sys.stdin.readline().split(' ')))
    partlyreverse(baskets,i-1,j)
        
    
for i in range(m):
    print(baskets[i],end=' ')


