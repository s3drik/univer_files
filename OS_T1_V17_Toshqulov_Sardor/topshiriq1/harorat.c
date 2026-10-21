#include <stdio.h>

double c_to_f(double c) { return (c * 9.0 / 5.0) + 32.0; }
double c_to_k(double c) { return c + 273.15; }
double f_to_c(double f) { return (f - 32.0) * 5.0 / 9.0; }
double f_to_k(double f) { return (f - 32.0) * 5.0 / 9.0 + 273.15; }
double k_to_c(double k) { return k - 273.15; }
double k_to_f(double k) { return (k - 273.15) * 9.0 / 5.0 + 32.0; }

int main() {
    int choice;
    double temp;

    printf("=== 1-MASALA: C ASOSLARI (HARORAT KONVERTORI) ===\n");
    printf("1. Selsiy (C)\n");
    printf("2. Farengeyt (F)\n");
    printf("3. Kelvin (K)\n");
    printf("Kiritilayotgan harorat turini tanlang (1-3): ");
    
    if (scanf("%d", &choice) != 1 || choice < 1 || choice > 3) {
        printf("Xato: Noto'g'ri menyu tanlandi yoki son kiritilmadi!\n");
        return 1;
    }

    printf("Harorat qiymatini kiriting: ");
    if (scanf("%lf", &temp) != 1) {
        printf("Xato: Noto'g'ri son formati kiritildi!\n");
        return 1;
    }

    if ((choice == 1 && temp < -273.15) || 
        (choice == 2 && temp < -459.67) || 
        (choice == 3 && temp < 0.0)) {
        printf("Xato: Absolyut noldan past harorat ma'nosiz qiymat hisoblanadi!\n");
        return 1;
    }

    printf("\nNatijalar:\n");
    switch (choice) {
        case 1:
            printf("Farengeyt: %.2f F\n", c_to_f(temp));
            printf("Kelvin: %.2f K\n", c_to_k(temp));
            break;
        case 2:
            printf("Selsiy: %.2f C\n", f_to_c(temp));
            printf("Kelvin: %.2f K\n", f_to_k(temp));
            break;
        case 3:
            printf("Selsiy: %.2f C\n", k_to_c(temp));
            printf("Farengeyt: %.2f F\n", k_to_f(temp));
            break;
    }

    return 0;
}