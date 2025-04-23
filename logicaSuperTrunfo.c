#include <stdio.h>

// Estrutura para armazenar os dados da carta
typedef struct {
    char estado[50];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float PIB;
    int pontosTuristicos;
} Carta;

// Função para calcular a densidade populacional
float calcularDensidadePopulacional(Carta c) {
    return c.populacao / c.area;
}

// Função para calcular o PIB per capita
float calcularPIBPerCapita(Carta c) {
    return c.PIB / c.populacao;
}

// Função para comparar dois atributos e determinar a carta vencedora
void compararCartas(Carta c1, Carta c2, int atributo) {
    float valor1, valor2;
    char *nomeAtributo;

    switch (atributo) {
        case 1:
            valor1 = c1.populacao;
            valor2 = c2.populacao;
            nomeAtributo = "População";
            break;
        case 2:
            valor1 = c1.area;
            valor2 = c2.area;
            nomeAtributo = "Área";
            break;
        case 3:
            valor1 = c1.PIB;
            valor2 = c2.PIB;
            nomeAtributo = "PIB";
            break;
        case 4:
            valor1 = calcularDensidadePopulacional(c1);
            valor2 = calcularDensidadePopulacional(c2);
            nomeAtributo = "Densidade Populacional";
            break;
        case 5:
            valor1 = calcularPIBPerCapita(c1);
            valor2 = calcularPIBPerCapita(c2);
            nomeAtributo = "PIB per capita";
            break;
        default:
            printf("Atributo inválido!\n");
            return;
    }

    printf("\nComparação de cartas (Atributo: %s)\n", nomeAtributo);
    printf("Carta 1 - %s (%s): %.2f\n", c1.nomeCidade, c1.estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", c2.nomeCidade, c2.estado, valor2);

    // Determinar vencedora
    if (atributo == 4) {
        if (valor1 < valor2)
            printf("Resultado: Carta 1 (%s) venceu!\n", c1.nomeCidade);
        else
            printf("Resultado: Carta 2 (%s) venceu!\n", c2.nomeCidade);
    } else {
        if (valor1 > valor2)
            printf("Resultado: Carta 1 (%s) venceu!\n", c1.nomeCidade);
        else
            printf("Resultado: Carta 2 (%s) venceu!\n", c2.nomeCidade);
    }
}

int main() {
    // Definição de duas cartas
    Carta carta1 = {"SP", "C001", "São Paulo", 12300000, 1521.11, 699.28, 10};
    Carta carta2 = {"RJ", "C002", "Rio de Janeiro", 6000000, 1200.27, 366.21, 15};

    // Escolha do atributo para comparação (alterar manualmente)
    int atributoEscolhido = 1; // População

    // Comparação das cartas
    compararCartas(carta1, carta2, atributoEscolhido);

    return 0;
}
