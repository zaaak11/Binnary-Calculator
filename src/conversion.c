#include <stdio.h>
#include "conversion.h"


int to_decimal(long long binary, int type, int bits) {
    int resultat = 0;
    int bit_valeur = 1;
    int bit_position = 1;

    // validation de choix
    if (bits != 8 && bits != 16) {
        printf("Error: la taille est invalid\n");
        return -1;
    }

    while (binary > 0) {
        // bit cpacite validation
        if (bit_position > bits) {
            printf("Le nombre binaire dépasse %d bits !\n", bits);
            return -1;
        }

        int dernier_nombre = binary % 10;
        binary = binary / 10;

        if (dernier_nombre != 0 && dernier_nombre != 1) {
            printf("Erreur : l'entree n'est pas un nombre binaire valide.\n");
            return -1;
        }

        // pour complement a 2 on subtract dans le MSB, si non on ajoute
        if (bit_position == bits && type == 2) {
            resultat -= dernier_nombre * bit_valeur;
        } else {
            resultat += dernier_nombre * bit_valeur;
        }

        bit_valeur *= 2;
        bit_position++;
    }

    return resultat;
}



long long to_binaire(int decimal, int type, int bits) {
    long long resultat = 0;
    long long shifter = 1;
    int bit_position = 1;
    int est_negatif = 0;

    // validation de choix
    if (bits != 8 && bits != 16) {
        printf("Error: Bit size must be 8 or 16.\n");
        return -1;
    }

    // pour complement a 2 on ajoute 2^8 (256) ou 2^16 (65536) si le nombre est negatif
    if (decimal < 0) {
        if (type == 1) {
            printf("Error: Input cannot be negative in unsigned mode.\n");
            return -1;
        }
        est_negatif = 1;
        if (bits == 8) {
            decimal += 256;
        } else {
            decimal += 65536;
        }
    }

    while (decimal > 0) {
        // bit cpacite validation
        if (bit_position > bits) {
            printf("Error: Decimal number exceeds %d bits!\n", bits);
            return -1;
        }

        int rest = decimal % 2;
        decimal = decimal / 2;

        // pour complement a 2 un nombre positif ne peut pas utiliser le MSB
        if (bit_position == bits && type == 2 && est_negatif == 0) {
            printf("Error: Positive number exceeds %d bits signed limit!\n", bits);
            return -1;
        }

        resultat += rest * shifter;

        shifter *= 10;
        bit_position++;
    }

    return resultat;
}
