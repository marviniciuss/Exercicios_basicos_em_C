//JOGO DE ADIVINHAÇÃO
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //para poder usar acentos e caracteres especiais 
#include <time.h> //Necessária para usar a função rand e srand.


int main () {

	setlocale(LC_ALL, "Portuguese"); //Permite o uso de acentos e caracteres especiais
	printf("************************************\n");
	printf("* Bem-vindo ao Jogo de Adivinhação *\n");
	printf("************************************\n\n");
	
	srand(time(NULL)); //semente
	//Declaração de variáveis
	int numerosecreto=rand()%100;
	int chute;
	int i=0;
	double pontos=1000;
	int nivel;
	int total_de_tentativas;
	int acertou=0;
	
	printf("Qual o nível de dificuldade?\n");
	printf("(1) Fácil (2) Médio (3) Difícil \n\n");
	printf("Escolha: ");
	scanf("%d",&nivel);
	//Define o total de tentativas a partir do nível escolhido.
	switch (nivel){
		case 1:
			total_de_tentativas=20;
			break;
		case 2:
			total_de_tentativas=15;
			break;
		case 3:
			total_de_tentativas=6;
			break;
		default:
			printf("Você deve escolher entre as opções 1, 2 e 3.");
			return 0;
	}
	
	//INÍCIO DO LOOP
	for (i;i<total_de_tentativas;i++){
	printf("-> Tentativa %d de %d\n", i+1, total_de_tentativas);
	printf("Chute um número: ");
	scanf("%d", &chute);
	printf("\n");
		//Verifica se o número digitado foi negativo
		if (chute<0){
			printf("Você não pode chutar números negativos.\n");
			i--;
			continue; //Essa função interrompe e recomeça o loop. É diferente da função break que sai completamente de loop;
		}
    // a variável "acertou" recebe o valor 1 (verdadeiro) se a condição for verdadeira e recebe o valor 0 (falso) se a condição for falsa;
	acertou = chute == numerosecreto; 
	int maior = chute > numerosecreto; //a variável maior assume valores 0 (condição falsa) ou 1 (condição verdadeira);
	int menor = chute < numerosecreto; //a variável menor assume valores 0 (condição falsa) ou 1 (condição verdadeira);
	
	if (acertou){  // somente executa o if se acertou for 1 (verdadeiro);         
		break;
	} else if (maior){
		printf("Seu chute foi maior do que o número secreto!\n");
	} else if (menor){
		printf("Seu chute foi menor do que o número secreto!\n");
	}
	pontos=pontos - (double)abs((double)chute-(double)numerosecreto)/2;
	} //FIM DO LOOP
	
	if (acertou){
		printf("                                                  \n");
    	printf("                                                  \n");
	    printf("        @@@                  @@                   \n");
	    printf("        @@@                  @@ @@@@     @@@      \n");
	    printf("       @@@                   @@ @@@@@@@@@@@       \n");
	    printf("      @@@     @@@@@          @@ @@@@@@@@@@        \n");
	    printf("     @@@     @@@@@@@         @@ @   @@@@@         \n");
	    printf("     @@@     @@@@@@@         @@                   \n");
	    printf("     @@@@@@    @@@                                \n");
	    printf("        @@@@@@@@@@@@@      @@@@                   \n");
	    printf("           @@@@@@@@@@@@  @@@@@                    \n");
	    printf("             @@@@@@@ @@@@@@@ @@                   \n");
	    printf("             @@@@@@@         @@                   \n");
	    printf("             @@@@@@@         @@                   \n");
	    printf("             @@@@@@@                               \n");
	    printf("             @@@@@@@                               \n");
	    printf("             @@@@@@@                               \n");
	    printf("            @@@@ @@@@                              \n");
	    printf("            @@@   @@@                              \n");
	    printf("           @@@    @@@                              \n");
	    printf("           @@@     @@@                             \n");
	    printf("          @@@@     @@@@                            \n");
	    printf("          @@@       @@@                            \n");
	    printf("         @@@@       @@@@                           \n");
	    printf("        @@@@         @@@                           \n");
	    printf("                                                  \n");
	    printf("                                                  \n");
		printf("Parabéns! Você acertou o número.\n");
		printf("Jogue de novo, você é um bom jogador!\n");
	} else {
		printf(" \\|/ ____ \\|/ \n");
		printf(" @~/ ,. \\~@ \n");
		printf(" /_( \\__/ )_\\ \n");
		printf(" \\__U_/ \n");
		printf("\nVocê perdeu! Tente novamente!\n");
		printf("O número secreto era %d \n", numerosecreto);
	}
	printf("\nSua pontuação foi %.2f pontos! \n", pontos);

return 0;
}
