#include <stdio.h>
#include <stdlib.h>

void replace_char(char *str, char c, char d) {
    while (*str != '\0') {
        if (*str == c) {
            *str = d;
        }
        str++;
    }
}

int main(void) {
    int capacity = 256;
    
    char *line = (char *)malloc(capacity * sizeof(char));
    if (line == NULL) {
        printf("Xotira ajratishda xatolik!\n");
        return 1;
    }

    printf("Satrni kiriting: ");
    if (fgets(line, capacity, stdin) == NULL) {
        free(line);
        return 1;
    }

    char c, d;
    printf("Almashtiriladigan belgi (c): ");
    scanf(" %c", &c);

    printf("Yangi belgi (d): ");
    scanf(" %c", &d);

    replace_char(line, c, d);

    printf("\nNatijaviy satr: %s", line);

    free(line);
    line = NULL;

    return 0;
}
