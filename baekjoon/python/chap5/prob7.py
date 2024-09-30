#import sys
#sent=list(input())
#elliminate first and last blank if it exists
#if sent[0]==' ':
#    sent[0]='a'
#elif sent[-1]==' ':
#    sent[-1]='a'#change blanck into arbitrary word
#blanknum=sent.count(' ')
#print(blanknum+1)

sent=list(input().split(' '))
sent.sort()
sent.reverse()
try:
    wordnum=sent.index('') #' 'split으로 받아들이면 ' '은 ''이 됨 
    print(wordnum)
except:
    print(len(sent))


