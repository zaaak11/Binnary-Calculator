#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arithmetic.h"
#include "conversion.h"

int main(){
char a[100] = "1010101011" ;
char b[100] = "11001";
char *resultat = add(a, b);
printf("the result is : %s", resultat);
free(resultat);
return 0;
}
