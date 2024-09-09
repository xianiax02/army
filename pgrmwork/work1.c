// # include <stdio.h>
// int main(){
//     //파일 읽어들이고 항 나눠서 폴리노미얼 스트럭트 두개에 저장
//     typedef struct poly{
//         float coef;
//         int degree;
//         struct poly * link;
//     }poly;

//     FILE* file=fopen("input.txt","r");
//     if (file==NULL){
//         return 0;
//     }
//     while(1){
//         int i,j=0;
//         int num[101];
//         while(fgets(num,4,file)!=NULL){
//             i++;
//         }
//         poly poly1[i];
//         for(j=0;fgets(num,4,file)!=NULL,j++){
//                 // fgets(&poly1[j]->coef ,4, file);
//             fscanf(file, "%d %d", &poly1[j]->coef,&poly1[j]->degree);
//         }

//     }
    
    
//     return 0;
// }                                          
#include <stdio.h>
#include <stdlib.h>

typedef struct poly {
    float coef;
    int degree;
    struct poly* link;
} poly;

poly* createNode(float coef, int degree) {
    poly* newNode = (poly*)malloc(sizeof(poly));
    newNode->coef = coef;
    newNode->degree = degree;
    newNode->link = NULL;
    return newNode;
}//계수, 차수를 매개변수로 노드 단위를 만들어주고 새 노드의 포인터를 반환하는 함수

void insertNode(poly** polyList, float coef, int degree) {
    poly* newNode = createNode(coef, degree);

    if (*polyList == NULL) {
        *polyList = newNode;
    //폴리리스트가 없으면 새로만든 노드의 포인터 자체를 리스트 헤드로 설정
    } else {
        poly* temp = *polyList;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}//계수 차수 입력해서 폴리리스트에 노드를 새로 삽입해주는 함수

void printPolynomial(poly* polyList) {
    poly* temp = polyList;
    while (temp != NULL) {
        printf("%.1f x^%d ", temp->coef, temp->degree);
        temp = temp->link;
        if (temp != NULL) {
            printf("+ ");
        }
    }
    printf("\n");
}
char compare(int a,int b){
    if(a>b){
        return(">");
    }
    else if(a=b){
        return("=");
    }
    else return("<");
}
    //합할 폴리너미얼 정의, for(피연산자 각 항 차수 서로 비교 숫자 비교연산정의{비교 후), 
    //덧셈연산정의(같으면 합 다르면 큰 쪽의 항은 합에 저장되고 다음 항으로 이동 비교 연산이 행해지면 양쪽 둘 다 
    // 다음칸으로 이동 연산자 한쪽이라도 끝나면 나머지는 복붙) 
poly* add_poly(poly* poly1,poly* poly2,poly* polysum){
    
    int a=compare(poly1->degree,poly2->degree)
    if(poly1==NULL){
        polysum->degree=poly2->degree;
        polysum->coef=poly2->coef;
        polysum->link=poly2->link;
        add_poly(poly1,poly2->link,polysum->link);  

    }
    if(poly2==NULL){
        polysum->degree=poly1->degree;
        polysum->coef=poly1->coef;
        polysum->link=poly1->link;
        add_poly(poly1->link,poly2,polysum->link);  

    }
    switch (a){
    case ">":
        polysum->degree=poly1->degree;
        polysum->coef=poly1->coef;
        add_poly(poly1->link,poly2,polysum->link);
        break;
    case "=":
        if((poly1->coef)+(poly2->coef)==0){
            add_poly(poly1->link,poly2->link,polysum->link)
        }
        else{
            polysum->degree=poly1->degree;
            polysum->coef=poly1->coef+poly2->coef;
            add_poly(poly1->link,poly2->link,polysum->link)
        }
        break;
    case "<":
        polysum->degree=poly2->degree;
        polysum->coef=poly2->coef;
        add_poly(poly1,poly2->link,polysum->link);
        break;
    }
}
//폴리너미얼 곱셈 구현
    //첫째 폴리너미얼 기준 첫 폴리노미얼의 항에 두번째 폴리너미얼의 각 항 miltappend함수(링크 따라가며 항과 계수 나눠서 차례대로 곱한 후,
    // 차수는 입서트 하기전에 헤드부터 따라가며 같으면->계수 더하기, 다르면->(비교하고자 하는게 더 
    // 크면 그 순간 {{insert함수}}), 더 작으면 다음걸로 넘어가서 반복, null 이면 끝에 붙이기(append함수))
poly* mult_each(poly* poly,poly* term,poly* subresult){
    if(poly==NULL){
        return subresult;
    }
    subresult->degree=poly->degree+term->degree;
    subresult->coef=(poly->coef)*(term->coef);
    mult_each(poly->link,term,subresult->link);
}
poly* mult_poly(poly* poly1,poly* poly2,poly* multpoly){
    int i=0;
    while(poly2!=NULL){
        poly* subresult[i]=mult_each(poly1,poly2,subresult[i]);
        poly2=poly2->link;
        i++;
    }
}
int main() {
    //poly1, poly 2에 저장 완료
    FILE* file = fopen("input.txt", "r");
    // if (file == NULL) {
    //     printf("Failed to open the input file.\n");
    //     return 0;
    // }
    poly* poly1 = NULL;
    poly* poly2 = NULL;

    float coef;
    int degree; 
    // while (fscanf(file, "%f %d", &coef, &degree) == 2) {
    //     insertNode(&poly1, coef, degree);
    //     if (getc(file) == '\n\n') {
    //         break;
    //     }
    // }

    // while (fscanf(file, "%f %d", &coef, &degree) == 2) {
    //     insertNode(&poly2, coef, degree);
    // }

    while (fscanf(file, "%f %d", &coef, &degree) == 2) {
        insertNode(&poly1, coef, degree);
        if ((getc(file) == '\n')&&(getc(file) == '\n')&&(getc(file) == '\n')) {
            break;
        }
    }

    while (fscanf(file, "%f %d", &coef, &degree) == 2) {
        insertNode(&poly2, coef, degree);
    }
    


    // printf("Polynomial 1: ");
    // printPolynomial(poly1);

    // printf("Polynomial 2: ");
    // printPolynomial(poly2);

    // fclose(file);
    poly* polysum = (poly*)malloc(sizeof(poly));
    polysum->coef=NULL;
    polysum->degree=NULL;
    polysum->link=NULL;
    poly* multpoly = (poly*)malloc(sizeof(poly));
    polysum->coef=NULL;
    polysum->degree=NULL;
    polysum->link=NULL;
    add_poly(poly1,poly2,polysum);
    mult_poly(poly1,poly2,multpoly);
    //파일 출력
    FILE* ofile = fopen("output.txt", "w");
    if (ofile == NULL) {
        printf("Failed to open the output file.\n");
        return 0;
    }

    fprintf(ofile, "Addition\n");
    while(1){
        if(polysum==NULL){
            break;
        }
        fprintf(ofile,multpoly->coef);
        fprintf(ofile," ");
        fprintf(ofile,multpoly->degree);
        fprintf(ofile,"\n");
        multpoly=multpoly->link;
    }
    fprintf(ofile, "Multiplication\n");
    while(1){
        if(polymult==NULL){
            break;
        }
        fprintf(ofile,polymult->coef);
        fprintf(ofile," ");
        fprintf(ofile,polymult->degree);
        fprintf(ofile,"\n");
        polymult=polymult->link;
    }
    fclose(file);



     return 0;
}


    //폴리너미얼 덧셈 구현(내림차순)

    
    
