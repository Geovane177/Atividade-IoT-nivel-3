#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n1 = 1, n2 = 100;
    int n3;

   
    srand(time(NULL));

    
    n3 = (rand() % (n2 - n1 + 1)) + n1;

    printf("Número aleatório entre %d e %d: %d\n", n2, n1, n3);

    return 0;
}
