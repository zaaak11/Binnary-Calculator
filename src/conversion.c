#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conversion.h"

void revstr(char *str) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}
