score=input()
def judge(year):
    if ((year%4==0) and ((year%100!=0) or (year%400==0))):
        return '1'
    else:
        return '0'
    
print(judge(int(score)))
