#include <stdio.h>
/*Fazer um programa para solicitar ao usuário um número entre 0 e 99 e mostrar este número
por extenso. Se o usuário introduzir um número que não está neste intervalo, mostre:
"número inválido"*/

int main() {
	int numero;
	printf("Digite um numero entre 0 e 99: ");
	scanf("%d",&numero);
	
	if (numero>=0 && numero<=99){
		switch (numero) {
			case 0: printf("Zero \n"); break;
			case 1: printf("Um \n"); break;
			case 2: printf("Dois \n"); break;
			case 3: printf("Três \n"); break;
			case 4: printf("Quatro \n"); break;
			case 5: printf("Cinco \n"); break;
			case 6: printf("Seis \n"); break;
			case 7: printf("sete\n"); break;
            case 8: printf("oito\n"); break;
            case 9: printf("nove\n"); break;
            case 10: printf("dez\n"); break;
            case 11: printf("onze\n"); break;
            case 12: printf("doze\n"); break;
            case 13: printf("treze\n"); break;
            case 14: printf("catorze\n"); break;
            case 15: printf("quinze\n"); break;
            case 16: printf("dezesseis\n"); break;
            case 17: printf("dezessete\n"); break;
            case 18: printf("dezoito\n"); break;
            case 19: printf("dezenove\n"); break;
			default: 
					int dezena=numero/10;
					int unidade=numero%10;
					switch (dezena){
						case 2: printf("Vinte"); break;
						case 3: printf("Trinta"); break;
						case 4: printf("Quarenta"); break;
						case 5: printf("Cinquenta"); break;
						case 6: printf("Sessenta"); break;
						case 7: printf("Setenta"); break;
						case 8: printf("Oitenta"); break;
						case 9: printf("Noventa"); break;
					} if (unidade>0){
							printf(" e ");
							switch (unidade){
								case 1: printf("um"); break;
								case 2: printf("dois"); break;
								case 3: printf("três"); break;
								case 4: printf("quatro"); break;
								case 5: printf("cinco"); break;
								case 6: printf("seis"); break;
								case 7: printf("sete"); break;
								case 8: printf("oito"); break;
								case 9: printf("nove"); break;
							}
							
					}
	
		}  
		
    } else {
        // Número inválido
        printf("Numero invalido\n");
    }
    
    return 0;
}
