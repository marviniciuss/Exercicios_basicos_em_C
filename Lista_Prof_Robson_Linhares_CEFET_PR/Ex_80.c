#include<stdio.h>

/* 80. Faça um programa para receber do
 usuário a dimensão de um array (máx. 20),
  os elementos desse array e efetuar a sua
   ordenação utilizando o método da bolha
    (bubble-sort). */

int main()
{
    int tamanho, aux=0;
    printf("Informe o tamanho do array(máximo 20) ");
    scanf("%i",&tamanho);
    int array[tamanho];
    for (int i=0;i<tamanho;i++){
    printf("Digite o %i elemento do vetor: ",i+1);
    scanf("%i",&array[i]);
    }
    
    for (int i=0;i<tamanho;i++){
       for(int j=0;j<tamanho;j++){
          if (array[i]<array[j]){
          aux=array[i];
          array[i]=array[j];
          array[j]=aux;
          }
       }
    }
    
    printf("O array em ordem crescente é: ");
    for (int i=0;i<tamanho;i++){
    printf(" %i ,",array[i]);
    
    }
    
    
    return 0;
}