/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cstring>
using namespace std;

struct player{
    int cost;
    char name[21];
};

player* findmax(player arr[], int size){
    player *maxplayer=arr;//arr=&arr[0]
    //int i=sizeof(arr)/sizeof(player);
    for(int j=1;j<size;j++){
        if(arr[j].cost>=maxplayer->cost){
            maxplayer=&arr[j];
        }   
    }
    return maxplayer;
}//플레이어 리스트를 받으면 가장 비싼 선수가 저장되어 있는 플레이어 포인터를 반환

int main(){
    int listnumber;
    cin >> listnumber;
    player value[listnumber]; //각 팀별 최고 선수들 담을 배열 생성
    for(int i=0;i<listnumber;i++){
        int listlength;
        cin >> listlength; 
        player list[listlength];
        for(int j=0;j<listlength;j++){
            int cost;
            char name[21];
            cin >> cost >> name;
            list[j].cost = cost;
            strcpy(list[j].name,name);//해당 팀의 선수들이 기입된 배열 작성 완료
        }
        value[i]=*findmax(list,listlength);//각 팀별 최고 선수들의 리스트 작성
        cout << value[i].name << endl;
    }
    
    return 0;
}
    