wordlist=list(input().upper())
#집합을 만들어서 각 요소를 카운트해보자 그 카운트를 비교하면 되지 않을까?
wordset=set(wordlist)
#이거 근데 데이터 allocation 어떻게 하는 거냐?
wordcount=[]
#일단 set은 unsubscriptable,indexing 불가
#일단 리스트로 만들고 집합으로 만들어 그리고 그 집합의 요소만큼 count한 리스트를 만들고 그 리스트의 최댓값 구해
#그리고 그 최댓값을 가지는 인덱스의 문자를 보는거지, 물론 처음에 대문자 소문자 다 통일하는 절차가 필요함 모두 대문자로 고칠 수 있도록
for i in list(wordset):
    wordcount.append(wordlist.count(i)) #각문자별 센걸 확인
maxnum=max(wordcount)
#wordcountrev=wordcount[:]
#wordcountrev.reverse()
#if wordcount.index(maxnum)+wordcountrev.index(maxnum)==len(wordcount):
#만약 문자열이 두개가 중복되는 것이 있다면 a.index와 a.reverse().index 값은 합이 len(a)가 안됨-> 아이건 wordcount가 대칭이면 안되네..
#지우고 맥시멈이 지워진 값과 다르면 유일한 거로 판정하는 방법으로 가야겠다.
result=list(wordset)[wordcount.index(maxnum)]
wordcount.remove(maxnum)
wordcount.append(0) #단어가 하나여서 wordcount 가 빈 리스트가 되는 경우를 제외
if max(wordcount)==maxnum: #여기에 빈리스트인 케이스를 추가해도 좋음 
    result='?'
print(result)
