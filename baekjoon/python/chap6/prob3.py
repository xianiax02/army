number=int(input())
#변수 받아 해당 변수 칸대로 중앙정렬하는 함수(num을 전체 total의 길이로 가운데에 출력한다.)

def middlearrangeprint(symbol,num,total):
#result=[] #나중에 리스트 컴포턴트를 하나의 string으로 붙여야함(리스트 반환후 for 출력으로 해결)
    if (total%2==0): #total과 num은 홀짝 유무가 같음 해당 문제에서는 num이 반드시 홀이지만 그래도 구현해봄
        t=total//2
        n=num//2
    else: #total와 num이 모두 홀수일때
        t=(total+1)//2
        n=(num+1)//2
    print(' '*(t-n),end='')
    print(symbol*num,end='')
    print(''*(t-n))

    #num을 전체 칸 수로 중앙정렬
for i in range(number):
        middlearrangeprint('*',2*i+1,2*number-1)
for i in range(number-1):
        middlearrangeprint('*',2*(number-i-2)+1,2*number-1)
        
