import sys
test=int(input())
for i in range(test):
    a,b=map(int,sys.stdin.readline().split(" "))
    print("Case #{num}: {num1} + {num2} = ".format(num=i+1,num1=a,num2=b),end='')
    print(a+b)

    
