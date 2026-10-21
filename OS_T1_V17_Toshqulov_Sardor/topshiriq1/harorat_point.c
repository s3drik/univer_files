#include <stdio.h>

double c_to_f(double c) { return (c * 9.0 / 5.0) + 32.0; }
double c_to_k(double c) { return c + 273.15; }
double f_to_c(double f) { return (f - 32.0) * 5.0 / 9.0; }
double f_to_k(double f) { return (f - 32.0) * 5.0 / 9.0 + 273.15; }
double k_to_c(double k) { return k - 273.15; }
double k_to_f(double k) { return (k - 273.15) * 9.0 / 5.0 + 32.0; }

int main() {
    double (*f[6])(double) = { c_to_f, c_to_k, f_to_c, f_to_k, k_to_c, k_to_f };

    int choice;
    double input_temp, res1, res2;

    printf("=== 2-MASALA: POINTERLAR MASSIVI BILAN KENGAYTIRISH ===\n");
    printf("1. Selsiy (C)\n");
    printf("2. Farengeyt (F)\n");
    printf("3. Kelvin (K)\n");
    printf("Kiritilayotgan harorat turini tanlang (1-3): ");

    if (scanf("%d", &choice) != 1 || choice < 1 || choice > 3) {
        printf("Xato: Noto'g'ri tanlov yoki son emas!\n");
        return 1;
    }

    printf("Harorat qiymatini kiriting: ");
    if (scanf("%lf", &input_temp) != 1) {
        printf("Xato: Son kiritishingiz kerak edi!\n");
        return 1;
    }

    if ((choice == 1 && input_temp < -273.15) || 
        (choice == 2 && input_temp < -459.67) || 
        (choice == 3 && input_temp < 0.0)) {
        printf("Xato: Absolyut noldan past harorat kiritish ma'nosiz!\n");
        return 1;
    }

    int idx1 = (choice - 1) * 2;
    int idx2 = idx1 + 1;

    res1 = f[idx1](input_temp);
    res2 = f[idx2](input_temp);

    printf("\nNatijalar:\n");
    if (choice == 1) {
        printf("Farengeyt: %.2f F\n", res1);
        printf("Kelvin: %.2f K\n", res2);
    } else if (choice == 2) {
        printf("Selsiy: %.2f C\n", res1);
        printf("Kelvin: %.2f K\n", res2);
    } else {
        printf("Selsiy: %.2f C\n", res1);
        printf("Farengeyt: %.2f F\n", res2);
    }

    return 0;
}
