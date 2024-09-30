import sys
num=int(input())
score=[]
score.extend(list(map(int,sys.stdin.readline().split())))
maxi=max(score)
temp=0
def modify(num,maxi):
    a=num/maxi*100
    return a

for i in range(num):
    score[i]=modify(score[i],maxi) #maxi 가 아닌 max(score)로 하면 score 가 수정되면서 max(score)도 수정됨
for i in range(num):
    temp+=score[i]
average=temp/len(score)
print(average)
    
