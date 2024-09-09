#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100  // 배열의 최대 행 수
#define MAX_COLS 200  // 배열의 최대 열 수

typedef struct {
    int row;
    int col;
} Position;

int main() {
    char array[MAX_ROWS][MAX_COLS];  // 배열 선언
    char filename[] = "input.txt";  // 입력 파일 이름
    FILE *file = fopen(filename, "r");  // 파일 열기

    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    int row = 0;
    Position positionE;  // E의 위치 저장을 위한 구조체 변수
    Position positionX;  // x의 위치 저장을 위한 구조체 변수
    char line[MAX_COLS];
    while (fgets(line, sizeof(line), file)) {
        int col = 0;
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] != '\n') {  // 줄바꿈 문자 제외
                array[row][col] = line[i];
                if (line[i] == 'E') {
                    positionE.row = row;
                    positionE.col = col;
                } else if (line[i] == 'X') {
                    positionX.row = row;
                    positionX.col = col;
                }
                if (line[i] != ' '){
                    col++;
                }
                
                //printf("\nline:{%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c}",line[0],line[1],line[2],line[3],line[4],line[5],line[6],line[7],line[8],line[9],line[10],line[11]);
                printf("\n%d",i);
                printf("\ncol");
                printf("\n%d",col);
            }
        }
        row++;
    
    }

    fclose(file);  // 파일 닫기

    // 배열 출력
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < MAX_COLS && array[i][j] != '\0'; j++) {
            printf("%c ", array[i][j]);
        }
        printf("\n");
    }

    // E와 X의 위치 출력
    printf("E의 위치: {%d, %d}\n", positionE.row, positionE.col);
    printf("X의 위치: {%d, %d}\n", positionX.row, positionX.col);
    

    return 0;
}
