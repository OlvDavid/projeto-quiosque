#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX_LENGTH 50
#include <string.h>

int quant = 1, quantP = 1, num = 1;

struct Cliente{
	char name[25];	

	};
	
	struct Cliente cliente;

typedef struct {

  const char nome1[MAX_LENGTH];

  const char nome2[MAX_LENGTH];

  const char nome3[MAX_LENGTH];

  const char nome4[MAX_LENGTH];

} Lanches;

typedef struct{

  char copia[MAX_LENGTH];

}Lista;

struct Pedidos{

  float valor;

}pedidos[5];

struct id{

  int id;
  float preco;
  
}id[50];

void valor(){

  pedidos[1].valor = 20.00;

  pedidos[2].valor = 30.00;

  pedidos[3].valor = 25.00;

  pedidos[4].valor = 15.00;
  
}
menu(){

  system("cls");

  printf("|====================|====================|====================|");
  printf("\n|                    |                    |                    |");
  printf("\n| 1- Sandu�ches      | 3- Acompanhamentos | 5- Carrinho        |");
  printf("\n|                    |                    |                    |");
  printf("\n|====================|====================|====================|");
  printf("\n|                    |                    |                    |");
  printf("\n| 2- Bebidas         | 4- Sobremesas      | 6- Finalizar Pedido|");
  printf("\n|                    |                    |                    |");
  printf("\n|====================|====================|====================|");

}

int lanches(){

  system("cls");

  printf("|========================|=======================|");
  printf("\n|                        |                       |");
  printf("\n| 1- X-Burguer R$ 20,00  |  2- X-Salada R$ 30,00 |");
  printf("\n|                        |                       |");
  printf("\n|========================|=======================|");
  printf("\n|                        |                       |");
  printf("\n| 3- X-Senai R$ 25,00    |  4- X-Github R$ 15,00 |");
  printf("\n|                        |                       |");
  printf("\n|========================|=======================|");
}

int menuPrincipal(){
	
	int options;
	
	printf("|====================|====================|");
  	printf("\n|                    |                    |");
  	printf("\n|  1- FAZER PEDIDO   |     2- SAIR        |");
  	printf("\n|                    |                    |");
  	printf("\n|====================|====================|");
  	printf("\nESCOLHA UMA OP��O: ");
  	scanf("%d", &options);
	
	switch(options){
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
		
		default:
			system("cls");
			
			printf("Op��o invalida. Tente Novamente.\n");
			
			system("pause");
			return menuPrincipal();
			break;
	}

	}

int main() {

	setlocale(LC_ALL, "portuguese");
	
	Lanches meusLanches = {"X-Burguer", "X-Salada", "X-Senai", "X-Github"};
	int opcao, lanche, bebida, remover;
	float total = 0;
	
	Lista Lista[50]; 
  	valor();

	fflush(stdin);

	menuPrincipal();
	
	do{
	
	menu();	
	
	printf("\n\nOpcao: ");

  	while (scanf("%d", &opcao) != 1) {

        while (getchar() != '\n');

        printf("Caracter invalido, Digite novamente: ");

	}
	switch(opcao){

    	case 1:

      		do{

      		system("cls");

      		lanches();

      		printf("\n\nEscolha(0 para retornar ao menu): ");

         		while (scanf("%d", &lanche) != 1) {

                   	while (getchar() != '\n');

                  	printf("Caracter invalido, Digite novamente: ");

         }

      	switch(lanche){

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

          		total += pedidos[3].valor;;

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

          		total += pedidos[4].valor;;

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
           
      		}while(lanche != 0);

      		break;
    
	case 5:
           
        if(total== 0){
                    
            printf("Ainda nao existe itens para remover!\n");
                    
            system("pause");
                    
        }else{
                          
            do{
         
        		system("cls");

        		printf("O seu pedido:\n");

       			for(int i = 1; i < quant; i++){

          		printf("\n %d R$ %.2f %s\n", i, id[i].preco, Lista[i].copia);

        }

        		printf("\nO total do seu pedido foi de: R$ %.2f\n", total);

        		printf("\nEscolha o numero do item que deseja remover(0 para voltar ao menu): ");

        		while (scanf("%d", &remover) != 1) {

                   while (getchar() != '\n');

                  printf("Caracter invalido, Digite novamente: ");

         }

        	if(remover >= 1 && remover < quant){

          		total -= id[remover].preco;

          		printf("%s removido com sucesso.\n", Lista[remover].copia);

          		system("pause");

          		for (int i = remover; i < quant - 1; i++) {

          		strcpy(Lista[i].copia, Lista[i + 1].copia);

          		id[i].preco = id[i + 1].preco;

         	 }

          	quant--;

        }	else{

          		printf("\nSem itens adcionados!!");

          		system("pause");

        }

        	if(remover == 0){

        }

        }	while(remover != 0);
                          
                          }

        	break;  
   
	}		
	
	}while(true);

}
