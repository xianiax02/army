#include <stdio.h>
#include <stdlib.h>

typedef struct poly {
    float coef;
    int degree;
    struct poly* link;
} poly;

poly* createNode(float coef, int degree) {
    poly* newNode = (poly*)malloc(sizeof(poly));
    if (newNode != NULL) {
        newNode->coef = coef;
        newNode->degree = degree;
        newNode->link = NULL;
    }
    return newNode;
}//계수, 차수를 매개변수로 노드 단위를 만들어주고 새 노드의 포인터를 반환하는 함수

void insertNode(poly** polyList, float coef, int degree) {
    if (*polyList == NULL) {
        *polyList = createNode(coef, degree);
        return;
    }

    poly* current = *polyList;
    poly* prev = NULL;

    while (current != NULL) {
        if (current->degree == degree) {
            current->coef = coef;  // Update the coefficient if the degree already exists
            return;
        }
        if (current->degree < degree)
            break;
        prev = current;
        current = current->link;
    }

    poly* newNode = createNode(coef, degree);
    if (newNode == NULL)
        return;

    newNode->link = current;

    if (prev == NULL)
        *polyList = newNode;
    else
        prev->link = newNode;
}//계수 차수 입력해서 폴리리스트에 노드를 새로 삽입해주는 함수

// 
poly* add_poly(poly* poly1, poly* poly2) {
    poly* result = poly1;
    poly* term= poly2;
    if(poly1==NULL&&term != NULL){
        result= poly2;
        return result;
    }
    else if(poly1!=NULL&&term == NULL){
        return result;
    }
    else{
        while (poly1 != NULL && term != NULL) {
        insertNode(&result,term->coef,term->degree);
        
            term = term->link;
        }
        return result;
    }
}


  //덧셈연산정의(같으면 합 다르면 큰 쪽의 항은 합에 저장되고 다음 항으로 이동 비교 연산이 행해지면 양쪽 둘 다 
    // 다음칸으로 이동 연산자 한쪽이라도 끝나면 나머지는 복사붙여넣기) 
    //합할 폴리너미얼 정의, 각항 차수 비교후 각 경우마다 합연산을 정의
poly* mult_poly(poly* poly1, poly* poly2) {
    poly* result = NULL;
    poly* tmpResult = NULL;

    while (poly1 != NULL) {
        poly* term = poly2;
        poly* subresult = NULL;
        poly* last = NULL;

        while (term != NULL) {
            float coef = poly1->coef * term->coef;
            int degree = poly1->degree + term->degree;
            if (coef != 0) {
                if (last == NULL) {
                    subresult = createNode(coef, degree);
                    last = subresult;
                } else {
                    last->link = createNode(coef, degree);
                    last = last->link;
                }
            }
            term = term->link;
        }

        tmpResult = add_poly(tmpResult, subresult);
        poly1 = poly1->link;
    }

    while (tmpResult != NULL) {
        result = add_poly(result, tmpResult);
        tmpResult = tmpResult->link;
    }

    return result;
}
//폴리너미얼 곱셈 구현
    //첫째 폴리너미얼 기준 첫 폴리노미얼 전체를  두번째 폴리너미얼의 각 항 term으로 곱해서, (mult_each함수) subresult 다항식 연결리스트의 각 컴포넌트에 
    //그 값을 저장
    //tmpresult 다항식 연결리스트의 각 컴포넌트를 모두 더해서(add_poly함수 다시 사용)결과 반환


void print_poly(poly* polyList, FILE* file) {
    while (polyList != NULL) {
        fprintf(file, "%.1f %d\n", polyList->coef, polyList->degree);
        polyList = polyList->link;
    }
}
//다항식 출력함수
int main() {
    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("파일 불러오기 실패.\n");
        return 1;
    }
//파일에서 다항식 읽어들이기
    poly* poly1 = NULL;
    poly* poly2 = NULL;

    float coef;
    int degree;
    while (fscanf(inputFile, "%f %d", &coef, &degree) == 2) {
        insertNode(&poly1, coef, degree);
        if (getc(inputFile) == '\n') {
            break;
        }
    }

    while (fscanf(inputFile, "%f %d", &coef, &degree) == 2) {
        insertNode(&poly2, coef, degree);
    }

    poly* sumResult = add_poly(poly1, poly2);
    poly* multResult = mult_poly(poly1, poly2);

    fprintf(outputFile, "Addition\n");
    print_poly(sumResult, outputFile);

    fprintf(outputFile, "Multiplication\n");
    print_poly(multResult, outputFile);


    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
