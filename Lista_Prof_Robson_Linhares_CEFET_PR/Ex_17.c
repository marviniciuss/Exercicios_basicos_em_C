#include<stdio.h>
#include<stdlib.h>

/* O número 3025 possui a seguinte característica: 30 + 25 = 55 -> 55*55 = 3025. Fazer um
programa para obter todos os números de 4 algarismos com a mesma característica do
número 3025. */

int main (){
	int numero;
	for (numero=1000; numero<=9999;numero++){
		int parte1=numero/100;
		int parte2=numero%100;
		int soma = parte1+parte2;
		int produto = soma*soma;
		if (numero == produto){
			printf("%i \n", numero);
		}	
	}
	return 0;
}
