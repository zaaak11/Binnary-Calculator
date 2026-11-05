#include <stdio.h>
#include "conversion.h"

int main(){
    int mode, base, bits;
    long long num1, num2;
    int dec1, dec2, resultat_dec;
    long long resultat_bin;
    char op;

    printf("--------------------------------------------------\n");
    printf("         BINAIR ET DECIMAL CALCULATRICE              \n");
    printf("--------------------------------------------------\n");

    printf("[1] choisi un mode:\n");
    printf("    1. binaire non signé\n");
    printf("    2. complement à 2\n");
    printf("    votre choix (1 ou 2): ");
    scanf("%d", &mode);

    if (mode != 1 && mode != 2) {
        printf("\nError: choix invalid\n");
        return 1;
    }

    printf("\n[2] choisi la base:\n");
    printf("    1. Binair\n");
    printf("    2. Decimal\n");
    printf("    votre choix (1 or 2): ");
    scanf("%d", &base);

    if (base != 1 && base != 2) {
        printf("\nError: base invalid!\n");
        return 1;
    }


    printf("\n[3] choisi la taille:\n");
    printf("    8 bit\n");
    printf("    16 bit\n");
    printf("    votre choix (8 or 16): ");
    scanf("%d", &bits);

    if (bits != 8 && bits != 16) {
        printf("\nError: La taille est invalid\n");
        return 1;
    }


    printf("\n--------------------------------------------------\n");
    printf("Entrer le premier nombre  : ");
    scanf("%lld", &num1);

    printf("Entrer l'operateur (+ - x /) : ");
    scanf(" %c", &op);

    printf("Entrer le deuxiem nombre  : ");
    scanf("%lld", &num2);
    printf("--------------------------------------------------\n");

    // converter si la base est binair
    if (base == 1) {
        dec1 = to_decimal(num1, mode, bits);
        dec2 = to_decimal(num2, mode, bits);
    } else {
        dec1 = (int)num1;
        dec2 = (int)num2;
    }

    // calcule
    switch (op) {
        case '+':
            resultat_dec = dec1 + dec2;
            break;
        case '-':
            resultat_dec = dec1 - dec2;
            break;
        case 'x':
        case '*':
            resultat_dec = dec1 * dec2;
            break;
        case '/':
            if (dec2 == 0) {
                printf("\nError: Division par zero !\n");
                return 1;
            }
            resultat_dec = dec1 / dec2;
            break;
        default:
            printf("\nError: operateur invalid\n");
            return 1;
    }

    // 7. converter la resulta de decimal a binair
    resultat_bin = to_binaire(resultat_dec, mode, bits);

    // Check if the final result overflowed the 8-bit or 16-bit limit
    if (resultat_bin == -1) {
        printf("Calculation failed: Result (%d) overflows %d-bit capacity!\n", resultat_dec, bits);
        return 1;
    }

    // resultat final
    printf("\n==================== RESULTAT =====================\n");
    printf("  Operation (Decimal) : %d %c %d\n", dec1, op, dec2);
    printf("  Resultat Decimal   : %d\n", resultat_dec);
    printf("  Resultat Binair    : %lld\n", resultat_bin);
    printf("==================================================\n");

    return 0;
}
