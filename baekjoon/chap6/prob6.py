#일단 문자열에 해당 크로아티아가 존재하는지 체크, 체크하면서 2개짜리 카운트
#와 3개짜리 카운트를 분리해서 2개까지 카운트만큼 갯수를 뺴고, 3개짜리만큼 2개씩 빼자
#크로아티아 리스트
clist=['c=','c-','d-','lj','nj','s=','dz=','z=']
sentence=input()
#count2=0
#count3=0
a=sentence[:]
for i in clist: #아...이러면 2개있을 경우를 못센다 #그럼 그냥 크로아티아 문자를 생판 모르는 문자로 바꿔서 그 문자를 세자
    if i in sentence: #또,,, z=와 dz=가 문제다... z=는 따로 빼서 해보자 아니지 'dz='를 최우선으로 하면 된다 리스트 순서고치자
        a=a.replace(i,'*')


result=len(a)
print(result)
        
    
