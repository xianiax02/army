#MATRIX ADDITION

def createmat(m,n):
    mat=[]
    for i in range(m):
        #row=[]
        #for i in range(n):
            #row.append(input().split())
        #row.append(input().split())
        mat.append(list(map(int,input().split())))
    return mat


def addmat(mat1,mat2):
    result=[]
    for i in range(len(mat1)): #같은 열만큼 행을 더해야함
        resultrow=[]
        for j in range(len(mat1[i])):
            resultrow.append(mat1[i][j]+mat2[i][j])
        result.append(resultrow)
    return result

def printmat(mat):
    for i in range(len(mat)):
        for j in range(len(mat[i])):
            print(mat[i][j],end=' ')
        print('\n',end='')

def findmax(mat):
    maxnum=0
    for i in mat:
        maxnum=max(maxnum,max(i))
    return maxnum

mat1=createmat()

    

        
