#include<stdio.h>
#include<stdlib.h>

/* 14. (Cortesia do Prof. Bogdan Tomoyuki Nassu) Zeca está organizando um bolão de futebol.
Segundo suas regras, os apostadores informam o placar do jogo e ganham 10 pontos se
acertarem o vencedor ou se acertarem que foi empate, e ganham mais 5 pontos para o placar
de cada time que acertarem. A tabela a seguir dá um exemplo, considerando que o placar
real foi 3x2:
Escreva um programa que requisita do usuário o placar apostado e depois o placar do jogo e
informa quantos pontos o apostador fez. */


int main (){
	
	int a=0, b=0, c=0, d=0, pontos=0;
	printf ("Informe o placar apostado (separados por um espaço): ");
	scanf("%d %d", &a, &b);
	printf ("Informe o placar do jogo (separados por um espaço): ");
	scanf("%d %d",&c, &d);
	
	
	if (a==b && c==d){   //empate!
		pontos=pontos+10;
		if (a==c && b==d) {
			pontos=pontos+10;
		} else if (a==c || b==d){
			pontos=pontos+5;
		}
	} else if ((a>b && c>d) || (b>a && d>c)){
		pontos=pontos+10;
		if (a==c && b==d){
			pontos=pontos+10;
		} else if(a==c || b==d){
			pontos=pontos+5;
		}	
	} 
	printf ("O total de pontos eh: %d ",pontos);
	return 0;
}
