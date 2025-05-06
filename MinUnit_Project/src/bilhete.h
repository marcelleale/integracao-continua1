#include <stdio.h>

// Constantes
#define CRIANCAS 10   // 0 < criancas <= 12
#define ADULTOS 30    // 12 < adultos < 60
#define IDOSOS 15     // idosos >= 60
#define LIMITE_BILHETES 5

// Verifica se a quantidade está dentro do limite permitido
int verificarQtdBilhetes(int quantidade) {
    if (quantidade < 1 || quantidade > LIMITE_BILHETES)
        return 0;  // inválido
    else
        return 1;  // válido
}

// Retorna o preço unitário com base na idade
int calcPrecoUnitario(int idade) {
    if (idade <= 12) {
        return CRIANCAS;
    } else if (idade >= 60) {
        return IDOSOS;
    } else {
        return ADULTOS;
    }
}

// Calcula o preço total com base na idade e quantidade
int calcPrecoTotal(int idade, int quantidade) {
    if (idade < 0 || idade > 120) {
        return -1;
    }
    if (!verificarQtdBilhetes(quantidade)) {
        return -1;
    }

    int precoUnitario = calcPrecoUnitario(idade);
    return precoUnitario * quantidade;
}

