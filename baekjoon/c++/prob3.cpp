/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/



#include <iostream>
#include <cstring>
using namespace std;


int main()
{
    int num,y,m,d;
    string name,max,min;
    int maxb[3];
    int minb[3];
    cin >> num;
    for(int i=0;i<num;i++){
        cin>>name>>d>>m>>y;
        if(i==0){
            maxb[0]=minb[0]=y;
            maxb[1]=minb[1]=m;
            maxb[2]=minb[2]=d;
            max=name;
            min=name;
        } else {
                if((y<maxb[0])||(y==maxb[0]&&(m<maxb[1]||(m==maxb[1]&&d<maxb[2])))){
                    maxb[0]=y;
                    maxb[1]=m;
                    maxb[2]=d;  
                    max=name;
        } 
                if((y>minb[0])||(y==minb[0]&&(m>minb[1]||(m==minb[1]&&d>minb[2])))){
                    minb[0]=y;
                    minb[1]=m;
                    minb[2]=d;
                    min=name;
        //min, max 다 저장되어 있는 상태
        }    
        }
 
        
    }
    cout<<min<<"\n"<<max<<endl;
    return 0;
}
