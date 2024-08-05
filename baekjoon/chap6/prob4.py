word=input()
wordrev=[]
for i in word:
    wordrev.append(i)
wordlist=wordrev[:] #참조가 아닌 복사의 방식 사용[:]
wordrev.reverse()
result=1
for i in range(len(word)):
    if wordlist[i]!=wordrev[i]:
        result=0
print(result)
