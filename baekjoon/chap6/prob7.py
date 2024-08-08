def judge(word,alphabet): #해당 알파벳이 단어에서 그룹단어의 요소를 충족시키는지 체크
    indexlist=[i for i, char in enumerate(word) if char==alphabet]
#    for i in range(len(word)):
 #       if word[i]==alphabet:
  #          indexlist.append(i)
    
    for i in range(len(indexlist)-1):
        if (indexlist[i]+1!=indexlist[i+1]):
             return False  #return 써서 바로 탈출
        return True
#check weather it is group word
def check(word): #결국 그룹단어냐 아니냐의 핵심은 같은 단어가 서로 떨어져있는가 아닌가
        #같은 단어를 체크한 후 그 단어의 인덱스를 모두 확인해서 그 단어가 서로 인접해 있지 않음을 증명
    doubled=set()
    for i in range(len(word)):
        if word.count(word[i])>=2:
            doubled.add(word[i]) #doubled에는 중복되는 단어들만 모이게 됨
            #이미 처음부터 set으로 만들면 필요없음 doubled=list(set(doubled)) #중복되는 거 하나씩 만 만들기

    for char in doubled:
        if not judge(word,char):
            return False
        #a=judge(i,word)
        #if a==True:
         #   result=True
        #else:
         #   result=False
          #  break #하나라도 아니라면 바로 탈출
        return True

num=int(input())
count=0
for i in range(num):
    a=input()
    if check(a):
        count+=1
print(count)
