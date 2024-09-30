import sys
List=[]
remainder=[]
for i in range(10):
    num=int(sys.stdin.readline())
    List.append(num)
    remainder.append(num%42)
sets=set(remainder)
print(len(sets))
    
