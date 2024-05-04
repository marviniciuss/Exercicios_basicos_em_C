#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h> // Permite usar caracteres especiais

/* Questão 02 (6 pontos)
Uma pequena loja de artesanato possui apenas um vendedor e comercializa dez tipos de objetos. O vendedor recebe, mensalmente por comissão de 5% sobre o total de suas vendas. O valor unitário dos objetos deve ser informado e armazenado em um vetor; a quantidade vendida de cada peça deve ficar em outro vetor, mas na mesma posição. Crie um programa que receba os preços e as quantidades vendidas, armazenando-os em seus respectivos vetores (ambos com tamanho dez).

Depois determine e mostre:

um relatório contendo: a quantidade vendida, valor unitário e valor total de cada objeto. Ao final do relatório, deverão ser mostrados o valor geral das vendas e o valor da comissão que será paga ao vendedor; e

o valor do objeto mais vendido e sua quantidade (não se preocupe com empates).

Estratégia
Implemente a subfunção produto_quantidade para preencher os vetores de preços e quantidades dos produtos (1 ponto);
Implemente a subfunção total_vendas para calcular o total geral vendido e exibir as quantidade, preço e total de cada produto (1 ponto);
Implemente a subfunção comissao para calcular a comissão de vendas (1 ponto);
Implemente a subfunção maior_produto para definir o preço do produto com a maior quantidade vendida (2 ponto);
Implemente a função principal main a fim de chamar as subfunções e exibir os resultados exigidos de acordo com as entradas obrigatórias (1 ponto). */

int n=10;
float preco[10];
int quant[10];

int produto_quantidade(int n){
	int i;
	for (i=0;i<n;i++){
		printf("Digite o preço do produto %i: ", i+1);
		scanf("%f", &preco[i]);
		printf("Digite a quantidade do produto %i: ", i+1);
		scanf("%i", &quant[i]);
	} 	
}

float total_vendas(int n){
	int i;
	float total=0;
	printf("\n");
	printf("Relatório de vendas");
	printf("\n");
	for (i=0;i<n;i++){
		total=total+(preco[i]*quant[i]);
		printf("R$ %.2f, Qtd. %i, Total: R$ %.2f \n", preco[i], quant[i], preco[i]*quant[i]);
	}
	printf("\n");
	printf("Total geral vendido: R$ %.2f", total);
	return total;
}

float comissao(float total, float taxa){
	float comis= total*taxa;
	printf("\n");
	printf("\nO valor da comissao a ser paga é: R$ %.2f", comis);
	return comis;
}

void maior_produto(int n){
	int i, j=0;
	int maior=0;
	for (i=0; i<n; i++){
		if (maior>=quant[i]){
			maior=quant[i];
			j=i;
		}
	}
	printf("\nO produto %i é o mais vendido. Preço R$ %.2f ", j+1, preco[j]);
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	float taxa = 0.05;
	float total;
	produto_quantidade(n);
	total=total_vendas(n);
	comissao(total, taxa);
	maior_produto(n);
	
	return 0;
}
