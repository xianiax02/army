#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 이진 탐색 트리의 노드 구조체 정의
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 텍스트 파일을 읽어서 문자열 배열로 반환하는 함수
char** readTextFile(const char* filename, int* lineCount) {
    char** lines = NULL;
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("파일을 불러오지 못했습니다.\n");
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

// 이진 탐색 트리에서 특정 값을 찾아 해당 노드를 반환하는 함수
TreeNode* search(TreeNode* node, int key) {
    if (node == NULL) {
        return NULL;
    }
    if (key == node->data) {
        return node;
    } else if (key < node->data) {
        return search(node->left, key);
    } else {
        return search(node->right, key);
    }
}

// 이진 탐색 트리에 새로운 노드를 삽입하는 함수
void insert_node(TreeNode** root, int key) {
    TreeNode* p, * t;
    TreeNode* n;
    t = *root;
    p = NULL;
    while (t != NULL) {
        if (key == t->data) {
            return;
        }
        p = t;
        if (key < p->data) {
            t = p->left;
        } else {
            t = p->right;
        }
    }
    n = (TreeNode*)malloc(sizeof(TreeNode));
    if (n == NULL) {
        return;
    }
    n->data = key;
    n->left = n->right = NULL;
    if (p != NULL) {
        if (key < p->data) {
            p->left = n;
        } else {
            p->right = n;
        }
    } else {
        *root = n;
    }
}

// 이진 탐색 트리에서 특정 값을 가지는 노드를 삭제하는 함수
void delete_node(TreeNode** root, int key) {
    TreeNode* p, * child, * succ, * succ_p, * t;
    p = NULL;
    t = *root;
    while (t != NULL && t->data != key) {
        p = t;
        t = (key < t->data) ? t->left : t->right;
    }
    if (t == NULL) {
        printf("Key is not in the tree.\n");
        return;
    }
    // 단말 노드인 경우
    if (t->left == NULL && t->right == NULL) {
        if (p != NULL) {
            if (p->left == t) {
                p->left = NULL;
            } else {
                p->right = NULL;
            }
        } else {
            *root = NULL;
        }
    }
    // 하나의 자식만 가지는 경우
    else if (t->left == NULL || t->right == NULL) {
        child = (t->left != NULL) ? t->left : t->right;
        if (p != NULL) {
            if (p->left == t) {
                p->left = child;
            } else {
                p->right = child;
            }
        } else {
            *root = child;
        }
    }
    // 두 개의 자식을 가지는 경우
    else {
        succ_p = t;
        succ = t->right;
        while (succ->left != NULL) {
            succ_p = succ;
            succ = succ->left;
        }
        if (succ_p->left == succ) {
            succ_p->left = succ->right;
        } else {
            succ_p->right = succ->right;
        }
        t->data = succ->data;
        t = succ;
    }
    free(t);
}

// 이진 탐색 트리를 레벨 순서로 출력하는 함수
void printTreeLevelOrder(TreeNode* root, FILE* outputFile) {
    if (root == NULL) {
        fprintf(outputFile, "0\n");  // 출력을 파일에 기록
        return;
    }

    TreeNode* queue[1000];
    int front = 0, rear = 0;
    int currentLevel = 1;
    int nodesInCurrentLevel = 1;
    int nodesInNextLevel = 0;

    queue[rear++] = root;

    while (front < rear) {
        TreeNode* node = queue[front++];
        if (node != NULL) {
            fprintf(outputFile, "%d ", node->data);  // 출력을 파일에 기록

            queue[rear++] = node->left;
            queue[rear++] = node->right;

            nodesInNextLevel += 2;
        } else {
            fprintf(outputFile, "0 ");  // 출력을 파일에 기록
        }

        if (--nodesInCurrentLevel == 0) {
            nodesInCurrentLevel = nodesInNextLevel;
            nodesInNextLevel = 0;
            currentLevel++;
        }
    }
}
// 명령을 수행하는 함수
void applycommand(TreeNode** Tree, char command, int value) {
    switch (command) {
        case 'i':
            insert_node(Tree, value);
            break;
        case 'd':
            delete_node(Tree, value);
            break;
        case 's':
            break;
        default:
            printf("Invalid command: %c\n", command);
            break;
    }
}


int main() {
    const char* filename = "input.txt";
    int lineCount;
    char** textArray = readTextFile(filename, &lineCount);
    TreeNode* Tree = NULL;

    // 출력 파일 설정
    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("출력 파일을 열 수 없습니다.\n");
        return 1;
    }

    for (int i = 0; i < lineCount; i++) {
        char command = textArray[i][0];
        int value = atoi(&textArray[i][1]);
        fprintf(outputFile, "%s:", textArray[i]);

        if (textArray[i][0] == 's') {
            int value = atoi(&textArray[i][1]);
            applycommand(&Tree, command, value);
            if (search(Tree, value) != NULL) {
                fprintf(outputFile, "Exist");
            } else {
                fprintf(outputFile, "Not Exist");
            }
        } else {
            applycommand(&Tree, command, value);
            printTreeLevelOrder(Tree, outputFile);
        }

        fprintf(outputFile, "\n");
    }

    fclose(outputFile);
    return 0;

}

