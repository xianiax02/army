h,m=input().split(' ')
time=input()
h=int(h)
m=int(m)
time=int(time)
def adjust(h,m,time):
    m2=m+time
    if (m2>=60):
        h2=h+m2//60
        m2=m2%60
        if (h2>=24):
            h2=h2%24
            print(h2,m2)
        else:
            print(h2,m2)
        
    else:
        print(h,m2)

adjust(h,m,time)
