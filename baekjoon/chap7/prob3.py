#matrix addition
#mn행렬은 list[m][n]의 2차원 행렬임
def createmat(m): #입력할 행렬의 행 수를 받으면 해당 행 만큼의 행렬을 입력받음
    matrix=[]
    for i in range(m):
        matrix.append(list(map(int,input().split(' '))))
        #row=[]
        #for i in range(n):
        #row.append(input().split(' '))
        #matrix.append(row)

    return matrix

def addmat(matrix1,matrix2):
    result=[]
    for i in range(len(matrix1)): #각 행마다
        row=[]
        for j in range(len(matrix1)):
            row.append(matrix1[i][j]+matrix2[i][j])
        result.append(row)
    return result

def printmat(mat):
    for i in range(len(mat)):
        for j in mat[i]:
            print(j,end=' ')
        print('',end='\n')
    return


#99행렬의 최댓값과 그 인덱스를 구하는 방법
#1.모두 리스트에 넣어서 max()적용
#2. maxlist를 만들어서 그 maxlist에서 최댓값 추출(maxlist는 행과 열까지 반환)
#max는 iterable object의 길이, 또는 첫 값을 기준으로 비교함에 유의;

def findmax(mat):
    maxlist=[]
    for i in range(len(mat)):
        box=[max(mat[i],i)]
        maxlist.append(box)
    maxnum, m=max(maxlist)
    n=mat[m].index(maxnum)
    m+=1
    n+=1
    return maxnum,m,n
mat=createmat(9)
maxnum,m,n=findmax(mat)
print(maxnum)
print(m,n)
