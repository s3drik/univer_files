#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **create_matrix(int rows, int cols) {
    int **mat = (int **)malloc(rows * sizeof(int *));
    if (mat == NULL) return NULL;

    for (int i = 0; i < rows; i++) {
        *(mat + i) = (int *)malloc(cols * sizeof(int));
        if (*(mat + i) == NULL) {
            for (int k = 0; k < i; k++) {
                free(*(mat + k));
            }
            free(mat);
            return NULL;
        }
    }
    return mat;
}

void free_matrix(int **mat, int rows) {
    if (mat == NULL) return;
    for (int i = 0; i < rows; i++) {
        free(*(mat + i));
    }
    free(mat);
}

void fill_matrix(int **mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(*(mat + i) + j) = rand() % 50 + 1;
        }
    }
}

void print_matrix(int **mat, int rows, int cols, const char *name) {
    printf("%s matritsa (%dx%d):\n", name, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", *(*(mat + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    int rows = 3, cols = 4;
    srand((unsigned int)time(NULL));

    int **A = create_matrix(rows, cols);
    int **B = create_matrix(rows, cols);
    int **C = create_matrix(rows, cols);

    if (A == NULL || B == NULL || C == NULL) {
        fprintf(stderr, "Matritsa uchun xotira ajratishda xatolik!\n");
        free_matrix(A, rows);
        free_matrix(B, rows);
        free_matrix(C, rows);
        return 1;
    }

    fill_matrix(A, rows, cols);
    fill_matrix(B, rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(*(C + i) + j) = *(*(A + i) + j) + *(*(B + i) + j);
        }
    }

    print_matrix(A, rows, cols, "A");
    print_matrix(B, rows, cols, "B");
    print_matrix(C, rows, cols, "C (A + B)");

    free_matrix(A, rows);
    free_matrix(B, rows);
    free_matrix(C, rows);

    return 0;
}
