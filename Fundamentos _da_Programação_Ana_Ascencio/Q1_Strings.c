#include<stdio.h>
#include<string.h>

/* Faça um programa que receba uma frase, calcule e mostre a quantidade de vogais da frase digitada. O
programa deverá contar vogais maiúsculas e minúsculas.
SOLUÇÃO:
Digitar uma frase.
Pegar o tamanho da frase.
Percorrer a frase, pegando caractere por caractere.
Comparar cada caractere com as vogais (maiúsculas e minúsculas).
Quando encontrar uma vogal, acrescentar um na quantidade. */

int main (){
	char vet [80];
	int tam, i, cont=0;
	printf("Digite uma frase: ");
	gets(vet);
	tam=strlen(vet); //Armazena a quantidade de caracteres
	
	for (i=0;i<tam;i++){
		if (vet[i]=='a'||vet[i]=='A'||vet[i]=='e'||vet[i]=='E'||vet[i]=='i'||vet[i]=='I'||vet[i]=='o'||vet[i]=='O'||vet[i]=='u'||vet[i]=='U'){
			cont++;
		}	
	}
	printf("A quantidade de vogais eh %i",cont);
	
	return 0;
}
