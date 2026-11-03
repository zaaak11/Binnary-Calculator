#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arithmetic.h"
#include "conversion.h"

char *add(char *a, char *b){
        char *result = malloc(18);
        if (result == NULL) exit(1);
        int i, j, cash;
        char n_a[17], n_b[17];

        /* ----string size match confirmation---- */

        if (strlen(a) > strlen(b)){
            /* adding the amount of zeros needed at the start */
            int nbzero = (int)strlen(a)- (int)strlen(b);
            for (i = 0; i < nbzero; i++ ){
                n_b[i] = '0';
                }
            /* repositioning the values after the zeros */
            for (j = nbzero, i = 0; j<=(int)strlen(b)+nbzero; j++, i++){
                n_b[j] = b[i];
            }
            b = n_b;
        }

        if (strlen(b) > strlen(a)){
            int nbzero2 = (int)strlen(b)- (int)strlen(a);
            for (i = 0; i < nbzero2; i++ ){
                n_a[i] = '0';
                }
            for (j = nbzero2, i = 0; j<= (int)strlen(a)+nbzero2; j++, i++){
                n_a[j] = a[i];
            }
            a = n_a;
        }

        /* ----addition logic---- */

        cash = 0;
        for (i = (int)strlen(a)-1, j = 0; /* condition */ i >= 0; i--, j++){
            /* 1 + 1 case */
            if (a[i] == '1' && b[i]=='1'){

                if (cash == 1){
                    result[j] = '1';
                }
                if (cash == 0){
                    result[j] = '0';
                    cash = 1;
                }
            }
            /* 0 + 0 case */
            if (a[i] == '0' && b[i]=='0'){
                if (cash == 0){
                    result[j] = '0';
                }
                if (cash == 1){
                    result[j] = '1';
                    cash = 0;
                }
            }
            /* 0 + 1 case*/
            if (a[i] != b[i]){
                if (cash == 0){
                    result[j] = '1';
                }
                if (cash == 1){
                    result[j] = '0';
                    cash = 1;
                }

            }
            /* i = 0 --> check cash and add the null terminator */
            if (i == 0){
                if (cash == 1){
                    result[j+1] = '1';
                    result[j+2] = '\0';
                }
                if (cash == 0){
                    result[j+1] = '\0';
                }
            }


        }
        revstr(result);
        return result;

}

