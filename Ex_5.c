#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Fazer um programa para receber valores inteiros X, Y e Z do usuário e determinar se estes
valores podem formar os lados de um triângulo. Em caso afirmativo, informar se o triângulo
é equilátero, isósceles ou escaleno. */

int main()
 {
 	int L1, L2, L3;
 	printf ("Digite o comprimento de L1: \n");
 	scanf("%d", &L1);
 	printf ("Digite o comprimento de L2: \n");
 	scanf("%d",&L2);
 	printf ("Digite o comprimento de L3: \n");
 	scanf("%d",&L3);
 	if (L1+L2>L3 && L1+L3>L2 && L2+L3>L1) {
 		if (L1==L2 && L2==L3) {
 			printf("O triângulo é equilátero.\n");
		 } else if (L1==L2 || L2==L3 || L1==L3) {
		 	printf("O triângulo é isósceles.\n");
		 } else {
		 	printf("O triângulo é escaleno.\n");
		 }
 		
	 } else {
	 	
	 	printf("Os seguimentos não formam um triângulo.\n");
	 }
 	
 return 0;
 }
