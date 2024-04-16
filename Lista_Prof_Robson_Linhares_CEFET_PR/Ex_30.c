#include<stdio.h>
#include<stdlib.h>

/*30. (Cortesia do Prof. Bogdan Tomoyuki Nassu)
 Escreva um programa que lê um inteiro positivo e
  verifica se ele contém o dígito 3 em 
  qualquer posição. */

int main(){
   int N,i=0,j=0;
   printf("Digite um número positivo: ");
   scanf("%i",&N);
   while (N>0){
        int resto=N%10;
        N=N/10;
        i++;
            if(resto==3){
              printf("Contém o número 3 na posição %i \n",i);
              j++;
            }
   }
   if (j==0){
   printf("O número não contém o dígito 3!\n");
   }
return 0;
}


