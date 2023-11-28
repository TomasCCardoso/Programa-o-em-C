#include <stdio.h>

int converte_codigo_cores(int cor, int pos, float *ret){
    // Verifica se a posição é válida (1ª, 2ª ou 3ª banda)
    if (pos < 1 || pos > 3) {
        return -1; // Posição inválida
    }

    // Verifica se a cor é válida (de 0 a 9)
    if (cor < 0 || cor > 9) {
        return -1; // Cor inválida
    }

    // Atribui multiplicador baseado na posição da banda
    float multiplicador;
    if (pos == 1) {
        multiplicador = 1.0;
    } else if (pos == 2) {
        multiplicador = 10.0;
    } else {
        multiplicador = 100.0;
    }

    // Calcula o valor da resistência
    *ret += cor * multiplicador;

    return 1; // Sucesso
}

int main(){
    int cor, i;
    float resistor = 0.0;
    printf("Cores:\n 0 - Black \n 1 - Brown \n 2 - Red \n 3 - Orange \n 4 - Yellow \n 5 - Green \n 6 - Blue \n 7 - Violet \n 8 - Grey \n 9 - White\n\n");
    for(i = 1; i < 4; i++){
        do{
            printf("Introduza a cor da banda %d: ", i);
            scanf("%d", &cor);
        } while((cor < 0) || (cor > 9));
        
        // Chama a função para converter as cores para o valor da resistência
        int resultado = converte_codigo_cores(cor, i, &resistor);
        if (resultado == -1) {
            printf("Erro: Posição ou cor inválida para a banda %d.\n", i);
            return 1;
        }
    }
    printf("Valor da resistencia: %.2f Ohms\n", resistor);

    return 0;
}
