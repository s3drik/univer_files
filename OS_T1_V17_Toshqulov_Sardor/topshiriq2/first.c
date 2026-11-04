#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int n = 26;
    int *p = (int *)malloc(n * sizeof(int));
    if (p == NULL) return 1;

    srand((unsigned int)time(NULL));

    printf("Massiv elementlari:\n");
    for (int i = 0; i < n; i++) {
        *(p + i) = rand() % 101 - 50;
        printf("%d ", *(p + i));
    }
    printf("\n");

    int freq[101] = {0};

    for (int i = 0; i < n; i++) {
        int val = *(p + i);
        (*(freq + (val + 50)))++;
    }

    int max_count = 0;
    int most_frequent = *(p + 0);

    for (int idx = 0; idx < 101; idx++) {
        if (*(freq + idx) > max_count) {
            max_count = *(freq + idx);
            most_frequent = idx - 50;
        }
    }

    printf("\nEng ko'p uchragan element: %d (%d marta uchradi)\n", most_frequent, max_count);

    free(p);
    p = NULL;
    return 0;
}
