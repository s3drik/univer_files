#include <stdio.h>
#include <stdlib.h>

void print_poly(double *coeffs, int degree) {
    for (int i = 0; i <= degree; i++) {
        printf("%.1fx^%d ", coeffs[i], i);
        if (i < degree) printf("+ ");
    }
    printf("\n");
}

int input_poly(double *coeffs, int degree) {
    for (int i = 0; i <= degree; i++) {
        printf("x^%d koeffitsiyentini kiriting: ", i);
        if (scanf("%lf", &coeffs[i]) != 1) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int degA, degB, degSum, degProd;
    double *polyA = NULL, *polyB = NULL, *polySum = NULL, *polyProd = NULL;

    printf("1-ko'phad darajasini kiriting: ");
    if (scanf("%d", &degA) != 1 || degA < 0) {
        printf("Xato: Noto'g'ri daraja!\n");
        return 1;
    }

    printf("2-ko'phad darajasini kiriting: ");
    if (scanf("%d", &degB) != 1 || degB < 0) {
        printf("Xato: Noto'g'ri daraja!\n");
        return 1;
    }

    polyA = (double *)malloc((degA + 1) * sizeof(double));
    polyB = (double *)malloc((degB + 1) * sizeof(double));
    
    if (polyA == NULL || polyB == NULL) {
        printf("Xotira ajratishda xatolik!\n");
        free(polyA); free(polyB);
        return 1;
    }

    printf("\n--- 1-ko'phad koeffitsiyentlari ---\n");
    if (!input_poly(polyA, degA)) {
        printf("Xato: Son o'rniga harf kiritildi!\n");
        free(polyA); free(polyB);
        return 1;
    }

    printf("\n--- 2-ko'phad koeffitsiyentlari ---\n");
    if (!input_poly(polyB, degB)) {
        printf("Xato: Son o'rniga harf kiritildi!\n");
        free(polyA); free(polyB);
        return 1;
    }

    degSum = (degA > degB) ? degA : degB;
    polySum = (double *)calloc((degSum + 1), sizeof(double)); // calloc hammasini 0 qiladi
    if (polySum == NULL) return 1;

    for (int i = 0; i <= degA; i++) polySum[i] += polyA[i];
    for (int i = 0; i <= degB; i++) polySum[i] += polyB[i];

    degProd = degA + degB;
    polyProd = (double *)calloc((degProd + 1), sizeof(double));
    if (polyProd == NULL) return 1;

    for (int i = 0; i <= degA; i++) {
        for (int j = 0; j <= degB; j++) {
            polyProd[i + j] += polyA[i] * polyB[j];
        }
    }

    printf("\nA(x) = "); print_poly(polyA, degA);
    printf("B(x) = "); print_poly(polyB, degB);
    printf("Yig'indi = "); print_poly(polySum, degSum);
    printf("Ko'paytma = "); print_poly(polyProd, degProd);

    free(polyA);
    free(polyB);
    free(polySum);
    free(polyProd);

    return 0;
}
