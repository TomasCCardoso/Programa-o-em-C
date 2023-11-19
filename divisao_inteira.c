#include <stdio.h>

int divisao_inteira(int divisor, int dividendo, int *quociente, int *resto) {
    /*Verificar se o divisor é 0*/
    if(divisor == 0) {
        return 0; //código de erro quando divisor é 0
    }
    /*Inicializar quociente e resto*/
    *quociente = 0;
    *resto = 0;
    /*Calcular quociente pelo algoritmo da divisão*/
    while(dividendo >= divisor) { //Enquanto o dividendo for maior ou igul ao divisor a divisão inteira é possível
        dividendo -= divisor;  //O dividendo vai subtraindo ao divisor n vezes enquanto a condição anterior se verificar
        (*quociente)++; //Será incrementado 1 ao quociente
    }
    *resto = dividendo; //o resto será dado pelo último dividendo
    return 1; //Não há erro
    }

int main() {
    int divisor, dividendo, quociente, resto;
    printf("Insira o dividendo: ");
    scanf("%d", &dividendo);
    printf("Insira o divisor: ");
    scanf("%d", &divisor);
    /*Chamar a função para calcular a divisão inteira*/
        int code_error = divisao_inteira(divisor,dividendo,&quociente,&resto);
    /*Verificar se a função retorna 0*/
        if(code_error == 0) {
            printf("Erro: Divisão por 0\n"); //Verifica se a função dá erro
        } else {
            printf("Quociente: %d\n", quociente); //Imprime quociente
            printf("Resto: %d\n", resto); //Imprime o resto
        }

}