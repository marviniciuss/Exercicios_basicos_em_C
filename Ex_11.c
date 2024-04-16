#include<stdio.h>
#include<stdlib.h>

/*    Escreva um programa para receber do usuário um mês (de 1 a 12) e um ano (de 0 D.C. em
diante) e mostrar o número de dias daquele mês daquele ano. Utilizar switch e levar em
consideração anos bissextos para o cálculo    */

int main(){
	int mes, ano;
	printf("Digite o numero do mes: ");
	scanf("%i",&mes);
	printf("Digite o ano: ");
	scanf("%i",&ano);
	
	int a=ano%4;
	int b=ano%100;
	int c=ano%400;	
	
	switch (mes) {
		case 1: printf("O mes tem 31 dias."); break;
		case 3: printf("O mes tem 31 dias."); break;
		case 5: printf("O mes tem 31 dias."); break;
		case 7: printf("O mes tem 31 dias."); break;
		case 8: printf("O mes tem 31 dias."); break;
		case 10: printf("O mes tem 31 dias."); break;
		case 12: printf("O mes tem 31 dias."); break;
		case 4: printf("O mes tem 30 dias."); break;
		case 6: printf("O mes tem 30 dias."); break;
		case 9: printf("O mes tem 30 dias."); break;
		case 11: printf("O mes tem 30 dias."); break;
		case 2: if ((a==0 && b!=0)||c==0) {
			printf("O mes tem 29 dias.");
		} else {
			printf("O mes tem 28 dias.");
		} break;
		
	}
	
	return 0;
}


/*  
int bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
printf("O ano %d %s bissexto.\n", ano, bissexto ? "e" : "nao e");

OBS: A variável bissexto só receberá valor após a avaliação da condição (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0). 
Se essa condição for verdadeira, bissexto receberá o valor 1 (verdadeiro), caso contrário, receberá o valor 0 (falso).

O operador ternário é frequentemente usado para atribuir um valor a uma variável com base em uma condição. Por exemplo:
int a = 10;
int b = 20;
int maior = (a > b) ? a : b;

variável = condicao ? expressao_se_verdadeiro : expressao_se_falso

OBS: Neste exemplo, se a for maior que b, maior será atribuído o valor de a, caso contrário, maior será atribuído o valor de b.
**/



