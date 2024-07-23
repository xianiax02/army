#ascii a~z==97~122
word=input()
for i in range(97,123):
    alphabet=chr(i)
    if alphabet in word:        
        print(word.index(chr(i)),end=' ')
    else:
        print('-1',end=' ')
        
            
