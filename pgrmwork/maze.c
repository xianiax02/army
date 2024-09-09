
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAX_ROWS 100  // 배열의 최대 행 수
#define MAX_COLS 200  // 배열의 최대 열 수(입력된 것의 숫자 사이에 공백이 있으므로 최대 갯수의 두배인 200으로 설정함)

typedef struct {
    int row;
    int col;
} Position;

// 기본 스택 정의
#define MAX_SIZE 20000//최대 100x100입력되므로 200에 100을 곱한 20000이 최대 스탯이 되어야한다.

typedef struct {
    Position data[MAX_SIZE];
    int top;
} Stack;

// 스택 초기화
void init(Stack *stack) {
    stack->top = -1;
}

// 스택이 비어있는지 확인
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// 스택에 위치 요소 추가 (push함수)
void push(Stack *stack, Position value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("스택이 가득 찼습니다.\n");
        return ;
    }

    stack->top++;
    stack->data[stack->top] = value;
}

// 스택에서 위치 원소 제거하고 반환 (pop함수)
Position pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("스택이 비어있습니다.\n");
        Position a = {1, 1};
        return a;  // 스택이 비어있을 경우 임의의 값을 반환하거나 오류 처리를 할 수 있습니다.
    }

    Position value = stack->data[stack->top];
    stack->top--;

    return value;
}

char maze[MAX_ROWS][MAX_COLS];  // 함수 정의하기 전에 배열 선언

// 갈 수 있는 길(지나간 길이거나 벽이 아닌 경우)을 스택에 저장하는 함수 pushLoc 선언
void pushLoc(Stack *s, int r, int c) {
    if (r < 0 || c < 0) return;
    if (maze[r][c] != '1' && maze[r][c] != '.') {
        Position tmp;
        tmp.row = r;
        tmp.col = c;
        push(s, tmp);
    }
}



int main() {
    char filename[] = "input.txt";  // 입력 파일 이름
    FILE *file = fopen(filename, "r");  // 파일 열기

    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    int row = 0;
    Position posE;  // E의 위치 저장을 위한 구조체 변수
    Position posX;  // x의 위치 저장을 위한 구조체 변수
    char line[MAX_COLS];
    while (fgets(line, sizeof(line), file)) {
        int col = 0;
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] != '\n') {  // 줄바꿈 문자 제외
                maze[row][col] = line[i];
                if (line[i] == 'E') {
                    posE.row = row;
                    posE.col = col;
                } else if (line[i] == 'X') {
                    posX.row = row;
                    posX.col = col;
                }
                if (line[i] != ' '){
                    col++;
                }
                
                
            }
        }
        row++;
    
    }

    fclose(file);  // 파일 닫기

    // 경로 탐색
    int R, C;
    char result[]="성공";
    Stack S; 
    Stack path; //탐색용 스택 하나와 경로저장용 스택
    init(&S);
    init(&path);
    Position here;
    here = posE;
    while (maze[here.row][here.col] != 'X') {
        R = here.row;
        C = here.col;
        maze[R][C] = '.';
        pushLoc(&S, R - 1, C);
        pushLoc(&S, R + 1, C);
        pushLoc(&S, R, C - 1);
        pushLoc(&S, R, C + 1);
        if (isEmpty(&S)) {
            strcpy(result, "실패");
            return 0;
        } else {
            here = pop(&S);
            push(&path, here);
        }
    }
    //지금까지 읽어들인 path 출력
    printf("시작");
    printf("(%d,%d)->",posE.row,posE.col);
    for(int k=0;(path.data[k].row != 0) && (path.data[k].col != 0);k++){
        printf("(%d,%d)->",path.data[k].row,path.data[k].col);
    }
    printf("도착");
    printf("\n탐색 %c",result);

    FILE* ofile = fopen("output.txt", "w");
    if (ofile == NULL) {
        printf("Failed to open the output file.\n");
        return 0;
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < MAX_COLS && maze[i][j] != '\0'; j++) {
            if(i==posE.row&&j==posE.col){
                fprintf(ofile, "E ");
                continue;
            } else if (maze[i][j] == '1') {
                fprintf(ofile, "[]");
            } else if (maze[i][j] == '.') {
                fprintf(ofile, "  ");
            }  else if (maze[i][j] == '0') {
                fprintf(ofile, "  ");
            } else if (maze[i][j] != ' ') {
                fprintf(ofile, "%c ", maze[i][j]);
            }
        }//출력 양식이 입력 양식과 다르므로 각 경우에 대해 변환하고자 하는 기호를 조건문으로 할당해줌
        fprintf(ofile, "\n");
    }

    fprintf(ofile, "\n탐색 경로\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < MAX_COLS && maze[i][j] != '\0'; j++) {
            if (maze[i][j] == '1') {
                fprintf(ofile, "[]");
            }  else if (maze[i][j] == '0') {
                fprintf(ofile, "  ");
            }  else if (maze[i][j] != ' ') {
                fprintf(ofile, "%c ", maze[i][j]);
            }
        }
        fprintf(ofile, "\n");
    }

    fclose(ofile);
    return 0;
}
