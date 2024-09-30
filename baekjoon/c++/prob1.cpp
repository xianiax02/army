/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int sum, min, res, cnt=0 ;
    int  m, n;
    cin >> m>> n;
    for (int i=m;i<=n;i++){
        res=sqrt(i);
        if (res*res==i){
            sum+=i;
            cnt++;
            if (cnt==1){
                min=i;
            }
        }
        
    }
    if (cnt==0){
        cout << -1 << endl;
    }
    else {
        cout << sum << endl;
        cout << min << endl;
    }

    return 0;
    
}