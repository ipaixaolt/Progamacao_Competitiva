#include <stdio.h>

int main (void) {
    int N; //N = consumo de água na residência
    int saida = 0;
    
    scanf("%d", &N);
    
    if (N >= 101) {
        saida += (N - 100) * 5;
        N -= N - 100;
    } 
    
    if ((N >= 31) && (N <= 100)) {
        saida += (N - 30) * 2;
        N -= N - 30;
    }
    
    if ((N >= 11) && (N <= 30)) {
        saida += N - 10;
        N -= N - 10;
    }
    
    if (N <= 10) {
        saida += 7;
    }
    
    printf("%d\n", saida);

    return 0;
}
