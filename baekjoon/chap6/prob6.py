def judge(word,alphabet): #해당 알파벳이 단어에서 그룹단어의 요소를 충족시키는지 체크
    indexlist=[]
    result=None
    for i in range(len(word)):
        if word[i]==alphabet:
            indexlist.append(i)
        for i in range(len(indexlist)):
            if indexlist[i]+1!=indexlist[i+1]: #이게 문제
                result=False
            else:
                result=True
        return result
#check weather it is group word
def check(word): #결국 그룹단어냐 아니냐의 핵심은 같은 단어가 서로 떨어져있는가 아닌가
        #같은 단어를 체크한 후 그 단어의 인덱스를 모두 확인해서 그 단어가 서로 인접해 있지 않음을 증명
    doubled=[]
    result=None
    for i in word:
        if word.count(i)>=2:
            doubled.append(i) #doubled에는 중복되는 단어들만 모이게 됨

    for i in doubled:
        a=judge(i,word)
        if a==True:
            result=True
        else:
            result=False
            break #하나라도 아니라면 바로 탈출
        return result

num=int(input())
count=0
for i in range(num):
    a=input()
    if check(a):
        count+=1
print(count)
