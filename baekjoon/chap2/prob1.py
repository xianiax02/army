a,b=input().split()
a=int(a)
b=int(b)
def test(num1,num2):
    if (num1<num2):
        return '<'
    if (num1=num2):
        return '='
    else :
        return '>'
print(test(a,b))
