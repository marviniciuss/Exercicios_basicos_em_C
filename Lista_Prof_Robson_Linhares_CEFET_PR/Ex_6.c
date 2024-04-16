#include <stdio.h>
#include <stdlib.h>

/* 6. Fazer um programa que recebe 3 valores não inteiros do usuário e mostra o maior deles, o
menor deles e o valor intermediário.  */

int main () {
	float n1, n2 , n3, temp;
	printf ("Digite o 1º numero: \n");
	scanf("%f",&n1);
	printf ("Digite o 2º numero: \n");
	scanf("%f",&n2);
	printf ("Digite o 3º numero: \n");
	scanf("%f",&n3);
	
	if (n1>n2) {
		temp=n1;
		n1=n2;
		n2=temp;
	} if (n1>n3) {
		temp=n1;
		n1=n3;
		n3=temp;
	} if (n2>n3) {
		temp=n2;
		n2=n3;
		n3=temp;
	}
	
	printf ("Os números informados em ordem crescente são: %.0f, %.0f, %.0f. ",n1, n2, n3);
	
	return 0;
}
