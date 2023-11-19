#include <stdio.h>
#include <math.h>

#define GRAU_MAX 10

int lerpoli(int *poli) {
    int grau;
    printf("Insira o grau do termo máximo deste polinómio (até %d): ", GRAU_MAX);
    scanf("%d", &grau);

    if (grau > GRAU_MAX || grau < 0) {
        printf("GRAU INVÁLIDO\n");
        return 0;
    }

    printf("Insira os coeficientes do polinómio começando pelo termo de ordem 0.\n");
    for (int i = 0; i <= grau; i++) {
        printf("Coeficiente de x^%d: ", i);
        scanf("%d", &poli[i]);
    }

    return grau;
}

void escreverpoli(int *poli, int grau) {
    printf("Polinómio: ");
    for (int i = grau; i >= 0; i--) {
        if (poli[i] != 0) {
            printf("%d", poli[i]);

            if (i > 0) {
                printf("x^%d", i);
            }

            if (i > 0 && poli[i - 1] >= 0) {
                printf(" + ");
            } else if (i > 0 && poli[i - 1] < 0) {
                printf(" - ");
            }
        }
    }
    printf("\n");
}

void adicionapoli(int *p1, int *p2, int *pResultado, int Maiorgrau) {
    for (int i = 0; i <= Maiorgrau; i++) {
        pResultado[i] = p1[i] + p2[i];
    }
}

float calcul(int *poli, int grau, float x) {
    float soma = 0;
    for (int i = 0; i <= grau; i++) {
        soma += poli[i] * pow(x, i);
    }
    return soma;
}

int main() {
    int polinomio1[GRAU_MAX + 1], polinomio2[GRAU_MAX + 1], resultado[GRAU_MAX + 1];
    int grau1, grau2, maiorGrau;
    float x;

    printf("Polinómio 1:\n");
    grau1 = lerpoli(polinomio1);
    escreverpoli(polinomio1, grau1);

    printf("\nPolinómio 2:\n");
    grau2 = lerpoli(polinomio2);
    escreverpoli(polinomio2, grau2);

    maiorGrau = (grau1 > grau2) ? grau1 : grau2;

    adicionapoli(polinomio1, polinomio2, resultado, maiorGrau);

    printf("\nResultado da adição:\n");
    escreverpoli(resultado, maiorGrau);

    printf("\nDigite o valor de x para calcular o polinómio: ");
    scanf("%f", &x);

    float resultadoCalculado = calcul(resultado, maiorGrau, x);

    printf("Resultado do polinómio para x=%.2f: %.2f\n", x, resultadoCalculado);

    return 0;
}
