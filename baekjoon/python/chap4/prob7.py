import sys
students=[]
for i in range(30):
    students.append(i+1)
for i in range(28):
    num=sys.stdin.readline()
    students.remove(int(num))
for i in range(2):
    print(students[i])
    
