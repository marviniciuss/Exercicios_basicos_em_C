#include<stdio.h>
#include<stdlib.h>

/* 7. Fazer um programa que recebe um símbolo de operação do usuário (+, -, / ou *) e dois
números reais. O programa deve retornar o resultado da operação recebida sobre estes dois
números. */

int main(){
	float n1, n2, resultado;
	char operador;
	printf ("Digite o operador: ");
	scanf ("%c", &operador);
	printf ("Digite o primeiro numero: ");
	scanf ("%f", &n1);
	printf ("Digite o segundo numero: ");
	scanf ("%f", &n2);
	
	switch (operador){
		case '+': resultado=n1+n2;
				printf ("O resultado da operação eh: %f", resultado);
			break;
		case '-': resultado=n1-n2;
				printf ("O resultado da operação eh: %f", resultado);
			break;
		case '*': resultado=n1*n2;
				printf ("O resultado da operação eh: %f", resultado);
			break;
		case '/': 
			
			if (n2==0){
				printf ("Não existe divisão por zero!");
				
			} else {
				resultado=n1/n2;
				printf ("O resultado da operação eh: %f", resultado);
			}
			break;
		default:
		printf ("Digite um operador valido!");
	}
	return 0;
}
