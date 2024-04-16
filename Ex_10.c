#include<stdio.h>
#include<stdlib.h>
/*10. (Cortesia do Prof. Bogdan Tomoyuki Nassu) Escreva um programa que receba a velocidade
máxima em uma avenida e a velocidade com que um motorista estava dirigindo nela.
Calcule a multa que o motorista vai receber, considerando que são pagos R$ 5,00 por cada
km/h que estiver acima da velocidade permitida (considere apenas números inteiros). Se a
velocidade do motorista estiver dentro do limite, o programa deve informar que não há
multa.*/

int main(){
	int vel, vel_max, multa;
	printf("Informe o limite maximo de velocidade da via (em km/h): ");
	scanf("%i",&vel_max);
	printf("Informe a velocidade com que um motorista estava dirigindo (em km/h): ");
	scanf("%i",&vel);
	
	if(vel>vel_max){
		multa=(vel-vel_max)*5;
		printf("O valor da multa eh: R$ %.2i ",multa);

	} else {
		printf("Nao ha multa. Motorista trafegando dentro do limite de velocidade da via.");
	}
	return 0;
}
