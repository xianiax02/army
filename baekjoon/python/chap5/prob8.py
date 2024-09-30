word=list(input())  
totaltime=0
#A,B,C 등 문자를 어떻게 1,2..숫자로 변환할까
#A=65 몫연산자를 사용하자. 65->(65-65//3)0+2, 68->1+2

for i in range(len(word)):
    wordnum=ord(word[i])
    if wordnum<83:
        num=(wordnum-65)//3+2 #대응되는 숫자
    elif wordnum==83:
        num=7
    elif 86>=wordnum>=84:
        num=8
    elif 90>=wordnum>=87:
        num=9
    totaltime+=num
totaltime+=len(word)
print(totaltime)

     
    
