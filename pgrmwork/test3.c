#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** readTextFile(const char* filename, int* lineCount) {
    char** lines = NULL;
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return NULL;
    }

    char line[256];
    int count = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = '\0'; // 개행 문자 제거
        lines = realloc(lines, (count + 1) * sizeof(char*));
        lines[count] = strdup(line);
        count++;
    }

    fclose(file);
    *lineCount = count;
    return lines;
}

int main() {
    const char* filename = "input.txt";
    int lineCount;
    char** textArray = readTextFile(filename, &lineCount);

    if (textArray != NULL) {
        for (int i = 0; i < lineCount; i++) {
            printf("%s\n", textArray[i]);
        }

        // 메모리 해제
        for (int i = 0; i < lineCount; i++) {
            free(textArray[i]);
        }
        free(textArray);
    }

    return 0;
}
