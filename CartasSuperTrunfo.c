#include <stdio.h>

int main() {
    // Variáveis para a primeira carta
    char estado1;
    char codigo1[4];
    char cidade1[50];
    unsigned long populacao1;  // Alterado para unsigned long
    float area1;
    float pib1;
    int pontos_turisticos1;
    float densidade1;
    float pib_percapita1;
    float superpoder1;

    // Variáveis para a segunda carta
    char estado2;
    char codigo2[4];
    char cidade2[50];
    unsigned long populacao2;  // Alterado para unsigned long
    float area2;
    float pib2;
    int pontos_turisticos2;
    float densidade2;
    float pib_percapita2;
    float superpoder2;

    // Leitura dos dados da primeira carta
    printf("-------------------------------------\n");
    printf("DADOS DA PRIMEIRA CARTA\n");
    printf("-------------------------------------\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Código (ex: A01): ");
    scanf("%3s", codigo1);
    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", cidade1);
    printf("População: ");
    scanf("%lu", &populacao1);  // %lu para unsigned long
    printf("Área (km²): ");
    scanf("%f", &area1);
    printf("PIB (bilhões de reais): ");
    scanf("%f", &pib1);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos1);

    // Leitura dos dados da segunda carta
    printf("\n-------------------------------------\n");
    printf("DADOS DA SEGUNDA CARTA\n");
    printf("-------------------------------------\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Código (ex: B02): ");
    scanf("%3s", codigo2);
    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", cidade2);
    printf("População: ");
    scanf("%lu", &populacao2);  // %lu para unsigned long
    printf("Área (km²): ");
    scanf("%f", &area2);
    printf("PIB (bilhões de reais): ");
    scanf("%f", &pib2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos2);

    // Cálculos para a primeira carta
    densidade1 = (float)populacao1 / area1;
    pib_percapita1 = (pib1 * 1000000000) / populacao1;
    
    // Cálculos para a segunda carta
    densidade2 = (float)populacao2 / area2;
    pib_percapita2 = (pib2 * 1000000000) / populacao2;

    // Cálculo do Super Poder
    superpoder1 = pib1 + populacao1 + area1 + pontos_turisticos1 + pib_percapita1 + (1.0/densidade1);
    superpoder2 = pib2 + populacao2 + area2 + pontos_turisticos2 + pib_percapita2 + (1.0/densidade2);

    // Exibição dos dados das cartas
    printf("\n-------------------------------------\n");
    printf("CARTA 1:\n");
    printf("-------------------------------------\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pib_percapita1);
    printf("Super Poder: %.2f\n", superpoder1);

    printf("\n-------------------------------------\n");
    printf("CARTA 2:\n");
    printf("-------------------------------------\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pib_percapita2);
    printf("Super Poder: %.2f\n", superpoder2);

    // Comparação entre as cartas
    printf("\n-------------------------------------\n");
    printf("COMPARAÇÃO ENTRE CARTAS:\n");
    printf("-------------------------------------\n");
    printf("População: %d\n", (populacao1 > populacao2) ? 1 : 0);
    printf("Área: %d\n", (area1 > area2) ? 1 : 0);
    printf("PIB: %d\n", (pib1 > pib2) ? 1 : 0);
    printf("Pontos Turísticos: %d\n", (pontos_turisticos1 > pontos_turisticos2) ? 1 : 0);
    printf("Densidade: %d\n", (densidade1 < densidade2) ? 1 : 0);  // Menor valor vence
    printf("PIB per Capita: %d\n", (pib_percapita1 > pib_percapita2) ? 1 : 0);
    printf("Super Poder: %d\n", (superpoder1 > superpoder2) ? 1 : 0);
    printf("-------------------------------------\n");

    printf("Comparação de Superpoderes: \n")
    if(superpoder1> superpoder2){
        printf("A carta 1 venceu!\n");
    }else if( superpoder1 == superpoder2){
        printf("As cartas empataram!\n");
    }else{
        printf("A carta 2 venceu!\n");
    }
    return 0;
}