a,b,c=input().split(" ")
a=int(a)
b=int(b)
c=int(c)
List=sorted([a,b,c])
def score(List):
    if (List[0]==List[2]):
        return 10000+List[0]*1000
    elif ((List[0]==List[1]) or (List[1]==List[2])):
        return 1000+List[1]*100
    else:
        return List[2]*100
print(score(List))
