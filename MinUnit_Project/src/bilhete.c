//ARQUIVO BILHETE.C 
#include <stdio.h>
#include "bilhete.h"

int main() {
    int idade, quantidade;
    int precoUnitario, precoTotal;

    printf("Digite a idade do visitante: ");
    scanf("%d", &idade);

    printf("Digite a quantidade de bilhetes (1 a %d): ", LIMITE_BILHETES);
    scanf("%d", &quantidade);

    if (!verificarQtdBilhetes(quantidade)) {
        printf("Erro: A quantidade máxima permitida por pessoa é de %d bilhetes.\n", LIMITE_BILHETES);
        return 1;
    }

    precoUnitario = calcPrecoUnitario(idade);
    precoTotal = calcPrecoTotal(idade, quantidade);

    printf("Idade: %d anos - Preço unitário: R$ %d\n", idade, precoUnitario);
    printf("Quantidade: %d - Preço total: R$ %d\n", quantidade, precoTotal);

    return 0;
}
