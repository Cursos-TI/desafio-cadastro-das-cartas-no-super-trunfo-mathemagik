#include <stdio.h>
#include <stdbool.h>

int main() {
    // Variáveis para a primeira carta
    char estado1;
    char codigo1[4];
    char cidade1[50];
    unsigned long populacao1;
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
    unsigned long populacao2;
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
    scanf("%lu", &populacao1);
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
    scanf("%lu", &populacao2);
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

    // Menu interativo para escolha dos atributos
    int opcao1, opcao2;
    bool opcoes_disponiveis[8] = {false, true, true, true, true, true, true, true}; // índice 0 não usado, 1 a 7 disponíveis

    printf("\n-------------------------------------\n");
    printf("ESCOLHA DO PRIMEIRO ATRIBUTO\n");
    printf("-------------------------------------\n");
    printf("Selecione o primeiro atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("6 - PIB per Capita\n");
    printf("7 - Super Poder\n");
    printf("Opção: ");
    scanf("%d", &opcao1);

    // Validar a primeira opção
    if (opcao1 < 1 || opcao1 > 7) {
        printf("Opção inválida!\n");
        return 1;
    }
    opcoes_disponiveis[opcao1] = false; // marca como indisponível

    // Menu para o segundo atributo (opções dinâmicas)
    printf("\n-------------------------------------\n");
    printf("ESCOLHA DO SEGUNDO ATRIBUTO\n");
    printf("-------------------------------------\n");
    printf("Selecione o segundo atributo para comparação:\n");
    if (opcoes_disponiveis[1]) printf("1 - População\n");
    if (opcoes_disponiveis[2]) printf("2 - Área\n");
    if (opcoes_disponiveis[3]) printf("3 - PIB\n");
    if (opcoes_disponiveis[4]) printf("4 - Pontos Turísticos\n");
    if (opcoes_disponiveis[5]) printf("5 - Densidade Demográfica\n");
    if (opcoes_disponiveis[6]) printf("6 - PIB per Capita\n");
    if (opcoes_disponiveis[7]) printf("7 - Super Poder\n");
    printf("Opção: ");
    scanf("%d", &opcao2);

    // Validar a segunda opção
    if (opcao2 < 1 || opcao2 > 7 || !opcoes_disponiveis[opcao2]) {
        printf("Opção inválida ou repetida!\n");
        return 1;
    }

    // Variáveis para os atributos selecionados
    char* atributos[2];
    float valores1[2], valores2[2];
    int regras[2]; // 1 = maior vence, 0 = menor vence

    // Função para definir atributos usando operador ternário
    #define DEFINIR_ATRIBUTO(opcao, nome, val1, val2, regra) \
        do { \
            if (opcao == opcao1 || opcao == opcao2) { \
                int idx = (opcao == opcao1) ? 0 : 1; \
                atributos[idx] = nome; \
                valores1[idx] = val1; \
                valores2[idx] = val2; \
                regras[idx] = regra; \
            } \
        } while(0)

    // Definir os atributos selecionados
    DEFINIR_ATRIBUTO(1, "População", (float)populacao1, (float)populacao2, 1);
    DEFINIR_ATRIBUTO(2, "Área", area1, area2, 1);
    DEFINIR_ATRIBUTO(3, "PIB", pib1, pib2, 1);
    DEFINIR_ATRIBUTO(4, "Pontos Turísticos", (float)pontos_turisticos1, (float)pontos_turisticos2, 1);
    DEFINIR_ATRIBUTO(5, "Densidade Demográfica", densidade1, densidade2, 0);
    DEFINIR_ATRIBUTO(6, "PIB per Capita", pib_percapita1, pib_percapita2, 1);
    DEFINIR_ATRIBUTO(7, "Super Poder", superpoder1, superpoder2, 1);

    #undef DEFINIR_ATRIBUTO

    // Calcular soma dos atributos
    float soma1 = valores1[0] + valores1[1];
    float soma2 = valores2[0] + valores2[1];

    // Exibição dos resultados
    printf("\n-------------------------------------\n");
    printf("RESULTADO DA COMPARAÇÃO\n");
    printf("-------------------------------------\n");
    printf("Carta 1: %s\n", cidade1);
    printf("Carta 2: %s\n\n", cidade2);
    
    printf("Atributos selecionados:\n");
    printf("1. %s\n", atributos[0]);
    printf("2. %s\n\n", atributos[1]);
    
    printf("Comparação por atributo:\n");
    for (int i = 0; i < 2; i++) {
        printf("- %s:\n", atributos[i]);
        printf("  %s: %.2f\n", cidade1, valores1[i]);
        printf("  %s: %.2f\n", cidade2, valores2[i]);
        
        // Determinar vencedor do atributo com operador ternário
        char* vencedor = 
            (regras[i] == 1) ? 
                ((valores1[i] > valores2[i]) ? cidade1 : 
                (valores2[i] > valores1[i]) ? cidade2 : "Empate") :
                ((valores1[i] < valores2[i]) ? cidade1 : 
                (valores2[i] < valores1[i]) ? cidade2 : "Empate");
                
        printf("  Vencedor: %s\n\n", vencedor);
    }
    
    printf("Soma dos atributos:\n");
    printf("%s: %.2f\n", cidade1, soma1);
    printf("%s: %.2f\n\n", cidade2, soma2);
    
    // Determinar vencedor final
    if (soma1 > soma2) {
        printf("VENCEDOR FINAL: %s\n", cidade1);
    } else if (soma2 > soma1) {
        printf("VENCEDOR FINAL: %s\n", cidade2);
    } else {
        printf("EMPATE FINAL!\n");
    }
    printf("-------------------------------------\n");

    return 0;
}