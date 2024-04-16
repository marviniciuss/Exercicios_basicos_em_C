#include<stdio.h>
#include<stdlib.h>
/*13. Escreva um programa que calcule o salário semanal de um trabalhador. As entradas são o
número de horas trabalhadas na semana e o valor da hora. Até 40 h/semana não se
acrescenta nenhum adicional. Acima de 40h e até 60h há um bônus de 50% para essas horas.
Acima de 60h há um bônus de 100% para essas horas.*/

int main (){
	int hora;
	float valor_hora, salario;
	printf ("Informe o numero de horas trabalhadas: ");
	scanf("%d",&hora);
	printf ("Informe o valor da hora trabalhada: ");
	scanf("%f",&valor_hora);
	
	if (hora<=40){
		salario=hora*valor_hora;
	} else if (hora>=40 && hora<=60){
		salario=(40*valor_hora)+((hora-40)*(1.5*valor_hora));		
	} else if (hora>60){
		salario=(40*valor_hora)+(20*(1.5*valor_hora))+((hora-60)*2*valor_hora);	
	}
	printf ("O salário eh: %f ",salario);
	
	return 0;
}
