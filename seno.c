#include <stdio.h>
#include <math.h>

float fatorial(int n) {
    float fatorial = 1;
    for(int i = 1; i <= n; i++) {
        fatorial *= i;
    }
    return fatorial; 
}

float seno(float x, float tolerance) {
    float resultado = 0.0;
    int n = 1;
    float termo;

    do {
        // Calcula o número da série de Taylor corrigindo o cálculo da potência
        termo = (n % 2 == 1 ? 1 : -1) * pow(x, 2 * n - 1) / fatorial(2 * n - 1);

        // Adiciona o termo ao resultado
        resultado += termo;

        // Incrementa o termo para o próximo ciclo
        n++; 
    } while(fabs(termo) >= tolerance);

    return resultado;
}

int main() {
    float x, tolerance, sin_result;
    
    printf("Qual o valor de x? ");
    scanf("%f", &x);

    printf("Qual a tolerância? ");
    scanf("%f", &tolerance);

    sin_result = seno(x, tolerance);

    printf("O seno de %f é %f\n", x, sin_result);

    return 0;
}
