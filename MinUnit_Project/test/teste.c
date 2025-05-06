
/* 
Idade

Válida: [0, 12] (Criança), [13, 59] (Adulto), [60, ∞] (Idoso)
Inválida: Menor que 0 ou maior que 120 

Quantidade de bilhetes

Válida: 1 =< bilhetes >= 5
Inválida: 1 > bilhetes > 5 

------------------------------------------------------------------------------------------------------

Validação particionamento em classes de equivalência

Idade
CT = {(0, válido), (12, válido), (-1, inválido), (59, válido)}

Bilhetes
CT = {(0, inválido), (1, válido), (5, válido), (6, inválido)}

CT = {
        (0, 1, válido, 10),         // Criança (R$10 * 1)
        (12, 3, válido, 30),        // Criança (R$10 * 3)
        (160, 5, inválido, -1),     // Idade inválida (idade > 120)
        (12, 6, inválido, -1)       // Quantidade inválida (bilhetes > 5)
};

-------------------------------------------------------------------------------------------------------
Valor Limite

Idade	Classificação esperada
-1	    Inválido
0	    Válido (criança)
12	    Válido (criança)
13	    Válido (adulto)
59	    Válido (adulto)
60	    Válido (idoso)
120	    Válido (idoso)
121	    Inválido


Quantidade	Classificação esperada
0	        Inválido
1	        Válido
5	        Válido
6	        Inválido

CT = {
    (idade, qtd, clas. esperada)

    (-1, 3, inválido),       // idade abaixo do mínimo
    (0, 3, válido),          // idade mínima permitida (criança)
    (12, 3, válido),         // limite superior da criança
    (13, 3, válido),         // limite inferior do adulto
    (59, 3, válido),         // limite superior do adulto
    (60, 3, válido),         // limite inferior do idoso
    (150, 3, válido),        // idade alta, ainda válida (idoso)
    (151, 3, inválido),      // idade acima do permitido
    (30, 0, inválido),       // quantidade abaixo do mínimo
    (30, 1, válido),         // quantidade mínima permitida
    (30, 5, válido),         // quantidade máxima permitida
    (30, 6, inválido)        // quantidade acima do máximo
};

*/

//Chamada das bibliotecas
#include "../test/minunit-master/minunit.h" 
#include "../src/bilhete.h" 

int tests_run = 0;

// Teste: quantidade válida (dentro do limite)
MU_TEST(test_quantidade_valida_ok) {
    mu_assert_int_eq(1, verificarQtdBilhetes(3));
}

// Teste: quantidade menor que 1 (Fora do Limite)
MU_TEST(test_quantidade_menor) {
    mu_assert_int_eq(0, verificarQtdBilhetes(0));
}

// Teste: quantidade maior que 5 (Fora do Limite)
MU_TEST(test_quantidade_maior) {
    mu_assert_int_eq(0, verificarQtdBilhetes(9));
}

// Teste: Vericação de limite (dentro do limite)
MU_TEST(test_quantidade_limiteMenor_ok) {
    mu_assert_int_eq(1, verificarQtdBilhetes(1));
}

// Teste: Verificação de Limite (dentro do limite)
MU_TEST(test_quantidade_limiteMaior_ok) {
    mu_assert_int_eq(1, verificarQtdBilhetes(5));
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_quantidade_valida_ok);
    MU_RUN_TEST(test_quantidade_menor);
    MU_RUN_TEST(test_quantidade_maior);
    MU_RUN_TEST(test_quantidade_limiteMenor_ok);
    MU_RUN_TEST(test_quantidade_limiteMaior_ok);
}

int main() {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
