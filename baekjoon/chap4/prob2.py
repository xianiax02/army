#처음에 변수의 갯수를 정해주니까, count하기면 되는 거잖아? 처음 변수 갯수
# 만큼 검사해서 대상 숫자가 나올때마다 count 해주면 되지 않을까 싶었는데 애초에
#정수들이 먼저 입력되어서 정수들을 저장하지 않으면 안되겠네...
#그러면 숫자열을 저장하면 되는데 숫자열을 개행문자로 구분해서 받아들이면 되겠다.
#숫자열도 len()또는 기초에 주어진 숫자로 구하거나 할 수 가 있네. 이렇게 검사하면 되겠다.
import sys
a=int(input())
b=list(map(int,sys.stdin.readline().split()))
num=int(input())
count=0
for i in range(a):
    if b[i]==num:
        count+=1

print(count)

    
