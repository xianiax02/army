import sys
a=[]
biggest=0
for i in range(9):
    new=int(sys.stdin.readline())
    a.append(new)
    biggest=max(new,biggest) #기존의 최댓값과 비교해야지 연속된 두 값을 비교해서 되지 않음!!

print(biggest)
print(a.index(biggest)+1)

#사실 그냥 max(a)하면 최댓값 나옴 
