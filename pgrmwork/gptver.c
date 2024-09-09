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
}

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
}

poly* add_poly(poly* poly1, poly* poly2) {
    poly* result = NULL;
    poly* last = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->degree > poly2->degree) {
            if (last == NULL) {
                result = createNode(poly1->coef, poly1->degree);
                last = result;
            } else {
                last->link = createNode(poly1->coef, poly1->degree);
                last = last->link;
            }
            poly1 = poly1->link;
        } else if (poly1->degree < poly2->degree) {
            if (last == NULL) {
                result = createNode(poly2->coef, poly2->degree);
                last = result;
            } else {
                last->link = createNode(poly2->coef, poly2->degree);
                last = last->link;
            }
            poly2 = poly2->link;
        } else {
            float sum = poly1->coef + poly2->coef;
            if (sum != 0) {
                if (last == NULL) {
                    result = createNode(sum, poly1->degree);
                    last = result;
                } else {
                    last->link = createNode(sum, poly1->degree);
                    last = last->link;
                }
            }
            poly1 = poly1->link;
            poly2 = poly2->link;
        }
    }

    while (poly1 != NULL) {
        if (last == NULL) {
            result = createNode(poly1->coef, poly1->degree);
            last = result;
        } else {
            last->link = createNode(poly1->coef, poly1->degree);
            last = last->link;
        }
        poly1 = poly1->link;
    }

    while (poly2 != NULL) {
        if (last == NULL) {
            result = createNode(poly2->coef, poly2->degree);
            last = result;
        } else {
            last->link = createNode(poly2->coef, poly2->degree);
            last = last->link;
        }
        poly2 = poly2->link;
    }

    return result;
}

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

void print_poly(poly* polyList, FILE* file) {
    while (polyList != NULL) {
        fprintf(file, "%.1f %d\n", polyList->coef, polyList->degree);
        polyList = polyList->link;
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("파일 불러오기 실패.\n");
        return 1;
    }

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
