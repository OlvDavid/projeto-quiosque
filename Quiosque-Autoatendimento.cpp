#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAX_LENGTH 50

int quant = 1, quantP = 1, num = 1;
float total = 0;

struct Cliente {
    
	char name[25];
};

struct Cliente cliente;

typedef struct {
    
	const char nome1[MAX_LENGTH];
    const char nome2[MAX_LENGTH];
    const char nome3[MAX_LENGTH];
    const char nome4[MAX_LENGTH];

} Lanches;

typedef struct {
    
	const char nome1[MAX_LENGTH];
    const char nome2[MAX_LENGTH];
    const char nome3[MAX_LENGTH];
    const char nome4[MAX_LENGTH];

} Acompanhamentos;

typedef struct {
    
	const char nome1[MAX_LENGTH];
    const char nome2[MAX_LENGTH];
    const char nome3[MAX_LENGTH];
    const char nome4[MAX_LENGTH];

} Bebidas;

typedef struct {
    
	const char nome1[MAX_LENGTH];
    const char nome2[MAX_LENGTH];
    const char nome3[MAX_LENGTH];
    const char nome4[MAX_LENGTH];

} Sobremesas;

typedef struct {
    
	char copia[MAX_LENGTH];

} Lista;

struct Pedidos {
    
	float valor;

} pedidos[5];

struct PedidosBe {
    
	float valor;

} pedidosBe[5];

struct PedidosAcomp {
    
	float valor;

} pedidosAcomp[5];

struct PedidosSobre {
    
	float valor;

} pedidosSobre[5];

struct id {
    
	int id;
    float preco;

} id[50];

void mostrarPedidos() {
    
	FILE *file;
    file = fopen("pedido.bin", "rb"); 

    if (file == NULL) {
        printf("Nenhum pedido foi encontrado.\n");
        return;
    }

    float orderTotal;
    fread(&orderTotal, sizeof(float), 1, file); 

    printf("Último pedido:\n");
    printf("Total: R$ %.2f\n", orderTotal);

    while (fread(&orderTotal, sizeof(float), 1, file) == 1) {
        char itemName[MAX_LENGTH];
        fread(itemName, sizeof(char), MAX_LENGTH, file);
        printf("R$ %.2f %s\n", orderTotal, itemName);
    }

    fclose(file);
}


void valor() {
   
    pedidos[1].valor = 20.00;
    pedidos[2].valor = 30.00;
    pedidos[3].valor = 25.00;
    pedidos[4].valor = 15.00;
}

void valorAcomp() {
    
	pedidosAcomp[1].valor = 13.00;
    pedidosAcomp[2].valor = 8.50;
    pedidosAcomp[3].valor = 15.00;
    pedidosAcomp[4].valor = 6.99;
}

void valorBe() {
    
	pedidosBe[1].valor = 7.50;
    pedidosBe[2].valor = 3.50;
    pedidosBe[3].valor = 5.00;
    pedidosBe[4].valor = 4.00;
}

void valorSobre() {
   
    pedidosSobre[1].valor = 12.00;
    pedidosSobre[2].valor = 17.00;
    pedidosSobre[3].valor = 15.00;
    pedidosSobre[4].valor = 8.00;
}


void menu() {
    system("cls");

    printf("|====================|====================|====================|\n");
    printf("|                    |                    |                    |\n");
    printf("| 1- Sanduíches      | 3- Acompanhamentos | 5- Carrinho        |\n");
    printf("|                    |                    |                    |\n");
    printf("|====================|====================|====================|\n");
    printf("|                    |                    |                    |\n");
    printf("| 2- Bebidas         | 4- Sobremesas      | 6- Finalizar Pedido|\n");
    printf("|                    |                    |                    |\n");
    printf("|====================|====================|====================|\n");
}

int lanches() {
    system("cls");

    printf("|========================|=======================|\n");
    printf("|                        |                       |\n");
    printf("| 1- X-Burguer R$ 20,00  |  2- X-Salada R$ 30,00 |\n");
    printf("|                        |                       |\n");
    printf("|========================|=======================|\n");
    printf("|                        |                       |\n");
    printf("| 3- X-Senai R$ 25,00    |  4- X-Github R$ 15,00 |\n");
    printf("|                        |                       |\n");
    printf("|========================|=======================|\n");
}

void bebidas() {
    system("cls");

    printf("|========================|=====================|\n");
    printf("|                        |                     |\n");
    printf("| 1- Coca-Cola R$ 7,50   |   2- Fanta R$ 3,50  |\n");
    printf("|                        |                     |\n");
    printf("|========================|=====================|\n");
    printf("|                        |                     |\n");
    printf("| 3- Antarctica R$ 5,00  |   4- Sprite R$ 4,00 |\n");
    printf("|                        |                     |\n");
    printf("|========================|=====================|\n");
}

int acompanhamentos() {
    system("cls");

    printf("|=============================|==========================|\n");
    printf("|                             |                          |\n");
    printf("| 1- Batata-Rustica R$ 13,00  | 2- Batata-Frita R$  8,50 |\n");
    printf("|                             |                          |\n");
    printf("|=============================|==========================|\n");
    printf("|                             |                          |\n");
    printf("| 3- Batata-Canoa R$ 15,00    | 4- Molhos R$ 6,99        |\n");
    printf("|                             |                          |\n");
    printf("|=============================|==========================|\n");
}

int sobremesas() {
    system("cls");

    printf("|========================|=======================|\n");
    printf("|                        |                       |\n");
    printf("| 1- MilkShake R$ 12,00  |  2- Açai R$ 17,00     |\n");
    printf("|                        |                       |\n");
    printf("|========================|=======================|\n");
    printf("|                        |                       |\n");
    printf("| 3- Casquinha R$ 15,00  |  4- Sundae R$ 8,00    |\n");
    printf("|                        |                       |\n");
    printf("|========================|=======================|\n");
}

int menuPrincipal() {
    system("cls");
	
	int options;
	char senha_correta[] = "admin";
	char senha_usuario[20];

    printf("|====================|====================|=============|\n");
    printf("|                    |                    |             |\n");
    printf("|  1- FAZER PEDIDO   |     2- SAIR        |  3- Pedidos |\n");
    printf("|                    |                    |             |\n"); 
    printf("|====================|====================|=============|\n");
    printf("ESCOLHA UMA OPÇÃO: ");
    scanf("%d", &options);

    switch (options) {
        case 1:
            system("cls");

            printf("=============CADASTRO DE CLIENTE==============");
            printf("\nInforme seu nome para seguirmos com o pedido\n\t\t");
            scanf("%s", &cliente.name);
            break;

        case 2:
            system("cls");

            printf("Ate a proxima!!!\n");

            exit(0);
            break;
            
        case 3:
		    system("cls");
		    
		    printf("=============PEDIDOS DOS CLIENTES==============");
			printf("\nOl?, atendente, informe sua senha para ter acesso aos ?ltimos pedidos! :\n");
    		scanf("%s", senha_usuario);
    		
  		  if (strcmp(senha_usuario, senha_correta)== 0) {
      		  printf("Senha correta! Acesso concedido.\n");
      		  
      		  system("cls");
      		  
      		  mostrarPedidos();
      		  
			} else{
			  printf("Senha incorreta! Acesso negado.\n");
			}   
			 system("pause");
			 
			 return menuPrincipal();
			 
			break;

        default:
            
			fflush(stdin);
			
			system("cls");

            printf("Opção inválida. Tente Novamente.\n");

            system("pause");
            return menuPrincipal();
            break;
    }
}

int main() {
    
	setlocale(LC_ALL, "portuguese");

    Lanches meusLanches = {"X-Burguer", "X-Salada", "X-Senai", "X-Github"};
    Acompanhamentos meusAcompanhamentos = {"Batata-Rustica", "Batata-Frita", "Batata-Canoa", "Molhos"};
    Bebidas minhasBebidas = {"Coca-Cola", "Fanta", "Antarctica", "Sprite"};
    Sobremesas minhasSobremesas = {"MilkShake", "Açai", "Casquinha", "Sundae"};

    int opcao, lanche, bebida, acompanhamento, sobremesa, remover, options;
    float total = 0;

    Lista Lista[50];
    valor();
    valorAcomp();
    valorBe();
    valorSobre();

    fflush(stdin);

    menuPrincipal();

    do {
        menu();

        printf("\n\nOpcao: ");

        while (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n');
            printf("Caracter invalido, Digite novamente: ");
        }

        switch (opcao) {
            case 1:
                do {
                    
					system("cls");
                    
					lanches();
                    printf("\n\nEscolha(0 para retornar ao menu): ");
                  
                    while (scanf("%d", &lanche) != 1) {
                        while (getchar() != '\n');
                        printf("Caracter invalido, Digite novamente: ");
                                              
                    }
                    
                    switch (lanche) {
                        case 1:
                            
							system("cls");
                            
							total += pedidos[1].valor;
                            strcpy(Lista[num].copia, meusLanches.nome1);
                            quant++;
                            id[quant].id = num;
                            id[quantP].preco = pedidos[1].valor;
                            num++;
                            quantP++;
                            printf("%s adcionado\n", meusLanches.nome1);
                            
							system("pause");
                            
						break;

                        case 2:
                            
							system("cls");
                            
							total += pedidos[2].valor;
                            strcpy(Lista[num].copia, meusLanches.nome2);
                            quant++;
                            id[quant].id = num;
                            id[quantP].preco = pedidos[2].valor;
                            num++;
                            quantP++;
                            printf("%s adcionado\n", meusLanches.nome2);
                            
							system("pause");
                            
						break;

                        case 3:
                            
							system("cls");
                            
							total += pedidos[3].valor;
                            strcpy(Lista[num].copia, meusLanches.nome3);
                            quant++;
                            id[quant].id = num;
                            id[quantP].preco = pedidos[3].valor;
                            num++;
                            quantP++;
                            printf("%s adcionado\n", meusLanches.nome3);
                           
						    system("pause");
                            
						break;

                        case 4:
                            
							system("cls");
                            
							total += pedidos[4].valor;
                            strcpy(Lista[num].copia, meusLanches.nome4);
                            quant++;
                            id[quant].id = num;
                            id[quantP].preco = pedidos[4].valor;
                            num++;
                            quantP++;
                            printf("%s adcionado\n", meusLanches.nome4);
                            
							system("pause");
                            
						break;

                        case 0:
                            
						break;

                        default:
                            
							system("cls");
                            
							printf("Opcao nao existe!!\n");
                           
						    system("pause");
                            
						break;
                    }
                } while (lanche != 0);

                		break;
			
      		
      		case 2:
    			do {
        			
					system("cls");
        			
					bebidas();
        			printf("\n\nEscolha(0 para retornar ao menu): ");

       				while (scanf("%d", &bebida) != 1) {
            			while (getchar() != '\n');
            			printf("Caracter invalido, Digite novamente: ");
        			}

       				switch (bebida) {
            			case 1:
                			
							system("cls");
                			
							total += pedidosBe[1].valor;
                			strcpy(Lista[num].copia, minhasBebidas.nome1);
                			quant++;
                			id[quant].id = num;
                			id[quantP].preco = pedidosBe[1].valor;
                			num++;
                			quantP++;
                			printf("%s adicionado\n", minhasBebidas.nome1);
                			
							system("pause");
                			
						break;

            			case 2:
                			
							system("cls");
                			
							total += pedidosBe[2].valor;
                			strcpy(Lista[num].copia, minhasBebidas.nome2);
                			quant++;
                			id[quant].id = num;
               				id[quantP].preco = pedidosBe[2].valor;
                			num++;
                			quantP++;
                			printf("%s adicionado\n", minhasBebidas.nome2);
                			
							system("pause");
                			
						break;

            			case 3:
                			
							system("cls");
                			
							total += pedidosBe[3].valor;
	                		strcpy(Lista[num].copia, minhasBebidas.nome3);
	               			quant++;
                			id[quant].id = num;
                			id[quantP].preco = pedidosBe[3].valor;
                			num++;
                			quantP++;
                			printf("%s adicionado\n", minhasBebidas.nome3);
                			
							system("pause");
               				 
						break;

            			case 4:
                		
							system("cls");
                		
							total += pedidosBe[4].valor;
               				strcpy(Lista[num].copia, minhasBebidas.nome4);
                			quant++;
                			id[quant].id = num;
                			id[quantP].preco = pedidosBe[4].valor;
                			num++;
                			quantP++;
                			printf("%s adicionado\n", minhasBebidas.nome4);
                		
							system("pause");
                	
						break;

            			case 0:
                		
						break;

            			default:
                		
							system("cls");
                		
							printf("Opcao nao existe!!\n");
                		
							system("pause");
                		
						break;
        			}

    			} while (bebida != 0);
    
						break;

      		
  			case 3:
    			do {
        			
					system("cls");
       				
					    acompanhamentos();
        				printf("\n\nEscolha(0 para retornar ao menu): ");

        				while (scanf("%d", &acompanhamento) != 1) {
            				while (getchar() != '\n');
            				printf("Caracter inválido, Digite novamente: ");
        				}

        			switch (acompanhamento) {
            			case 1:
                			
							system("cls");
                			
							total += pedidosAcomp[1].valor;
                			strcpy(Lista[num].copia, meusAcompanhamentos.nome1);
                			quant++;
                			id[quant].id = num;
                			id[quantP].preco = pedidosAcomp[1].valor;
               				num++;
                			quantP++;
                			printf("%s adicionado\n", meusAcompanhamentos.nome1);
                			
							system("pause");
                			
						break;

            			case 2:
                			
							system("cls");
                			
							total += pedidosAcomp[2].valor;
                			strcpy(Lista[num].copia, meusAcompanhamentos.nome2);
                			quant++;
                			id[quant].id = num;
                			id[quantP].preco = pedidosAcomp[2].valor;
                			num++;
                			quantP++;
                			printf("%s adicionado\n", meusAcompanhamentos.nome2);
                			
							system("pause");
                			
						break;

           			    case 3:
                			
							system("cls");
                			
							total += pedidosAcomp[3].valor;
                			strcpy(Lista[num].copia, meusAcompanhamentos.nome3);
                			quant++;
                			id[quant].id = num;
                			id[quantP].preco = pedidosAcomp[3].valor;
                			num++;
                			quantP++;
                			printf("%s adicionado\n", meusAcompanhamentos.nome3);
                			
							system("pause");
                			
						break;

            			case 4:
                			
							system("cls");
                			
							total += pedidosAcomp[4].valor;
                			strcpy(Lista[num].copia, meusAcompanhamentos.nome4);
                			quant++;
                			id[quant].id = num;
                			id[quantP].preco = pedidosAcomp[4].valor;
                			num++;
                			quantP++;
                			printf("%s adicionado\n", meusAcompanhamentos.nome4);
                			
							system("pause");
                			
						break;

            			case 0:
                		
						break;

            			default:
               		 		
							system("cls");
                			
							printf("Opção não existe!!\n");
                			
							system("pause");
                			
						break;
        			}
    			
				} while (acompanhamento != 0);
    						
						break;


        	case 4:
   				do {
        			
					system("cls");
        			
					sobremesas();
        			printf("\n\nEscolha(0 para retornar ao menu): ");

        			while (scanf("%d", &sobremesa) != 1) {
            			while (getchar() != '\n');
            			printf("Caracter inválido, Digite novamente: ");
       				}			

        			switch (sobremesa) {
            			case 1:
                			
							system("cls");
                			
							total += pedidosSobre[1].valor;
                			strcpy(Lista[num].copia, minhasSobremesas.nome1);
                			quant++;
                			id[quant].id = num;
                			id[quantP].preco = pedidosSobre[1].valor;
                			num++;
                			quantP++;
                			printf("%s adicionado\n", minhasSobremesas.nome1);
                			
							system("pause");
                			
						break;

            			case 2:
                			
							system("cls");
                			
							total += pedidosSobre[2].valor;
                			strcpy(Lista[num].copia, minhasSobremesas.nome2);
                			quant++;
                			id[quant].id = num;
                			id[quantP].preco = pedidosSobre[2].valor;
                			num++;
                			quantP++;
                			printf("%s adicionado\n", minhasSobremesas.nome2);
                			
							system("pause");
                		
						break;

            			case 3:
                			
							system("cls");
                			
							total += pedidosSobre[3].valor;
                			strcpy(Lista[num].copia, minhasSobremesas.nome3);
                			quant++;
                			id[quant].id = num;
               				id[quantP].preco = pedidosSobre[3].valor;
                			num++;
                			quantP++;
               				printf("%s adicionado\n", minhasSobremesas.nome3);
                			system("pause");
               			
						break;

            			case 4:
               		 		
							system("cls");
                			
							total += pedidosSobre[4].valor;
                			strcpy(Lista[num].copia, minhasSobremesas.nome4);
                			quant++;
                			id[quant].id = num;
                			id[quantP].preco = pedidosSobre[4].valor;
                			num++;
                			quantP++;
                			printf("%s adicionado\n", minhasSobremesas.nome4);
                			
							system("pause");
                		
						break;

            			case 0:
                		
						break;

            			default:
                			
							system("cls");
                			printf("Opção não existe!!\n");
                			
							system("pause");
                		
						break;
       				}

    		} while (sobremesa != 0);

   						 break;

    
			case 5:
    			if (total == 0) {
        			printf("Ainda não existem itens para remover!\n");
        			
					system("pause");
    			
				} else {
        			do {
            			
						system("cls");
            			
						printf("O seu pedido:\n");

           				for (int i = 1; i < quant; i++) {
                			printf("\n %d R$ %.2f %s\n", i, id[i].preco, Lista[i].copia);
           			 	}

            			printf("\nO total do seu pedido é de: R$ %.2f\n", total);
            			printf("\nEscolha o número do item que deseja remover (0 para voltar ao menu): ");

            			while (scanf("%d", &remover) != 1) {
                			while (getchar() != '\n');
                			
							fflush(stdin);
							
							printf("Caracter inválido, Digite novamente: ");
           				}

            			if (remover >= 1 && remover < quant) {
                			total -= id[remover].preco;
                			printf("%s removido com sucesso.\n", Lista[remover].copia);
                			
							system("pause");

                			for (int i = remover; i < quant - 1; i++) {
                    			strcpy(Lista[i].copia, Lista[i + 1].copia);
                    			id[i].preco = id[i + 1].preco;
                			}

                			quant--;
            			
						} else {
                			
							system("pause");
            			}

            			if (remover == 0) {
            			}

        			} while (remover != 0);
   				 }

    		break;

        	case 6:
    			
				system("cls");
    			
				printf("O seu pedido:\n");

    			for (int i = 1; i < quant; i++) {
        			printf("\nR$ %.2f %s\n", id[i].preco, Lista[i].copia);
    			}

    			printf("\n%s, o total do seu pedido foi de: R$ %.2f\n\n", cliente.name, total);
    			
    			FILE *file;
    			file = fopen("pedido.bin", "wb"); 

    			if (file == NULL) {
        		printf("Erro ao abrir o arquivo para salvar o pedido.\n");
        		
   				 }

    			fwrite(&total, sizeof(float), 1, file); 
    			for (int i = 1; i < quant; i++) {
        		fwrite(&id[i].preco, sizeof(float), 1, file); 
       			fwrite(Lista[i].copia, sizeof(char), MAX_LENGTH, file); 
    			
				}

    			fclose(file);
    			
				system("pause");
    			
    			system("cls");
				
				printf("1 -> Voltar ao Menu\n");
    			printf("2 -> Sair\n");
				scanf("%d", &options);
	
				switch(options){
					case 1: 
						return main();
						break;
						
						case 2:
						exit(0);
						break;
					
					default:
						printf("Opção Invalida. Tente novamente.\n");
						break;
				}
    		
			break;

			default:
    			
				printf("\nOpção inválida\n");
    			
				system("pause");
    		
			break;
		}
	} while (true);
}        	      	    
