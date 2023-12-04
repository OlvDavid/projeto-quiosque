#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Cliente{
	char name[25];	

	};

int menuPrincipal(){

	struct Cliente cliente;
	
	int options;
	
	printf("|====================|====================|");
  	printf("\n|                    |                    |");
  	printf("\n|  1- FAZER PEDIDO   |     2- SAIR        |");
  	printf("\n|                    |                    |");
  	printf("\n|====================|====================|");
  	printf("\nESCOLHA UMA OPÇÃO: ");
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
			
			printf("Opção invalida. Tente Novamente.\n");
			
			system("pause");
			return menuPrincipal();
			break;
	}

	}

int main() {

	setlocale(LC_ALL, "portuguese");
	
	menuPrincipal();	
	
}
