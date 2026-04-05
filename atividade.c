#include <stdio.h>

int main() {
    int numero, tipo;
    float kWh, preco, custo;
    
    float totalResidencial = 0, totalComercial = 0, totalIndustrial = 0;
    int countResidencial = 0, countComercial = 0; 

    printf("=== SISTEMA DE LEITURA DE CONSUMO ===\n");
    
    while (1) {
      
        printf("\nDigite o número do consumidor (0 para sair): ");
        scanf("%d", &numero);
        
        if (numero == 0) {
            break; 
        }
        
     
        printf("Quantidade de kWh consumidos no mês: ");
        scanf("%f", &kWh);
        

        printf("Tipo do consumidor (1-Residencial, 2-Comercial, 3-Industrial): ");
        scanf("%d", &tipo);
        
      
        switch (tipo) {
            case 1:
                preco = 0.3;
                totalResidencial += kWh;
                countResidencial++;
                break;
            case 2:
                preco = 0.5;
                totalComercial += kWh;
                countComercial++;
                break;
            case 3:
                preco = 0.7;
                totalIndustrial += kWh;
                break;
            default:
                printf("Tipo inválido! Considere apenas 1, 2 ou 3.\n");
                continue; 
        }
        
       
        custo = kWh * preco;
        printf("Custo total do consumidor %d: R$ %.2f\n", numero, custo);
    }
    

    printf("\n=== RELATÓRIO FINAL ===\n");
    printf("Total de consumo residencial (tipo 1): %.2f kWh\n", totalResidencial);
    printf("Total de consumo comercial   (tipo 2): %.2f kWh\n", totalComercial);
    printf("Total de consumo industrial  (tipo 3): %.2f kWh\n", totalIndustrial);
   
    int totalCountTipos1e2 = countResidencial + countComercial;
    if (totalCountTipos1e2 > 0) {
        float mediaConsumo12 = (totalResidencial + totalComercial) / totalCountTipos1e2;
        printf("Média de consumo dos tipos 1 e 2: %.2f kWh\n", mediaConsumo12);
    } else {
        printf("Não houve consumidores dos tipos 1 ou 2 para calcular a média.\n");
    }
    
    return 0;
}