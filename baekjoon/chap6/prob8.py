#우선 딕셔너리
grade={'A+':4.5,
       'A0':4.0,
       'B+':3.5,
       'B0':3.0,
       'C+':2.5,
       'C0':2.0,
       'D+':1.5,
       'D0':1.0,
       'F':0,
       } #p인 것은 예외처리 두어야 함
import sys
totalgrade=0
totalcredit=0

for i in range(20):
    #subject,credit,gradenum=sys.stdin.readline().split(' ')
    subject,credit,gradenum=input().split(' ')
    if (gradenum!='P'):
        totalgrade+=grade[gradenum]*float(credit) #성적*과목학점
        totalcredit+=float(credit)
        
finalgrade=totalgrade/totalcredit
print(finalgrade)
    
