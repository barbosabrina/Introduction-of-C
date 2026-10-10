#include <stdio.h>

// Função que valida o CPF. Retorna 1 se for válido e 0 se for inválido.
int validarCPF(long cpfOriginal) {
    int digitos[11];
    long temp = cpfOriginal;

    // Isola os dígitos do CPF de trás para frente usando repetição
    for (int i = 10; i >= 0; i--) {
        digitos[i] = temp % 10;
        temp /= 10;
    }

    // --- Validação do Primeiro Dígito ---
    int soma1 = 0;
    int peso1 = 10;
    
    for (int i = 0; i < 9; i++) {
        soma1 += digitos[i] * peso1;
        peso1--;
    }

    int resto1 = (soma1 * 10) % 11;
    if (resto1 == 10) {
        resto1 = 0;
    }

    // Se o primeiro resto não bater com o 10º dígito, é inválido
    if (resto1 != digitos[9]) {
        return 0;
    }

    // --- Validação do Segundo Dígito ---
    int soma2 = 0;
    int peso2 = 11;

    for (int i = 0; i < 10; i++) {
        soma2 += digitos[i] * peso2;
        peso2--;
    }

    int resto2 = (soma2 * 10) % 11;
    if (resto2 == 10) {
        resto2 = 0;
    }

    // Se o segundo resto bater com o 11º dígito, o CPF é válido
    if (resto2 == digitos[10]) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    long cpf;

    printf("Digite o CPF: ");
    if (scanf("%ld", &cpf) == 1) {
        // Chama a função e verifica o retorno (1 para Válido, 0 para Inválido)
        if (validarCPF(cpf)) {
            printf("Válido!\n");
        } else {
            printf("Inválido!\n");
        }
    }

    return 0;
}
