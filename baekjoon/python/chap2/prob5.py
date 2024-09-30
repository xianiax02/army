h,m=input().split(' ')
h=int(h)
m=int(m)
def adjust(h,m):
    if (m>=45):
        m2=m-45
        print(h,m2)
    else:
        if (h>=1):
            m2=m+60-45
            h2=h-1
            print(h2,m2)
        else:
            m2=m+60-45
            h2=h+24-1
            print(h2,m2)
adjust(h,m)

