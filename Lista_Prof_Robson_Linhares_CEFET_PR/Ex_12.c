#include<stdio.h>
#include<stdlib.h>

/*  Suponha que você está programando um módulo contador de cédulas para caixas eletrônicos. Escreva um programa que informa com
quantas cédulas de Real podemos representar um dado valor. Exemplo de resposta: R$ 218 = 2 cédulas de 100, 1 cédula de 10, 1 cédula de 5, 1 
cédula de 2 e 1 cédula de 1. Procure minimizar o número de cédulas usadas. Desconsidere valores com centavos, e suponha que
a máquina sempre tem disponíveis as cédulas necessárias. */

int main(){
	int nota100, nota50, nota20, nota10, nota5, nota2, nota1, valor;
	printf ("Informe o valor: ");
	scanf ("%d",&valor);
	
	nota100=valor/100;
	valor=valor%100;
	
	nota50=valor/50;
	valor=valor%50;
	
	nota20=valor/20;
	valor=valor%20;
	
	nota10=valor/10;
	valor=valor%10;
	
	nota5=valor/5;
	valor=valor%5;
	
	nota2=valor/2;
	valor=valor%2;
	
	nota1=valor/1;
	
	printf ("R$ %d notas de 100, %d notas 50, %d notas de 20, %d notas 10, %d notas de 5, %d notas de 2 e %d notas de 1",nota100, nota50, nota20, nota10, nota5, nota2, nota1);
	
	
	return 0;
}
