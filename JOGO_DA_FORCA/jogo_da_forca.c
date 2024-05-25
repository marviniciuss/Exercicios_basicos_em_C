#include<stdlib.h>
#include<stdio.h>
#include<locale.h>
#include<string.h>
#include "forca.h"   //importa as funções do arquivo header forca.h
#include<time.h>

//VARIÁVEIS GLOBAIS
char palavrasecreta[TAMANHO_PALAVRA];
char chutes[20];
int chutesdados=0;


void abertura(){
	printf("/****************/\n");
	printf("/ Jogo da Forca */\n");
	printf("/****************/\n\n");
}

void escolhepalavra(){
    FILE* f;
    f = fopen("palavras.txt","r");
    if (f==0){
        printf("Banco de palavras não disponível \n\n");
        exit(1); // o parâmetro 1, passado ao exit, indica ao sistema operacional que o programa
                 //terminou de maneira que ele não gostaria; ou seja, um erro ocorreu. Se tivéssemos retornado 0,
                 //o sistema operacional saberia que o programa rodou de acordo com o esperado.
                 }
    int quantidade_palavras;
	fscanf(f, "%d", &quantidade_palavras); //lê o arquivo f e armazena a primeira linha na variável quantidade_palavras.
	srand(time(NULL)); //SEMENTE
	int aleatorio = rand()% quantidade_palavras;

	for (int i=0; i<aleatorio; i++){ //Precisamos percorrer o arquivo até o indice gerado aleatoriamente. Em C não é possível
        fscanf(f, "%s", palavrasecreta);                                                     // ir diretamente para a palavra
	}
	fclose(f); // Fecha o arquivo palavras.txt
}

void chuta(){
	char chute;
	printf("\n");
	printf("Escolha uma letra -> ");
	scanf(" %c",&chute);
	if (letraexiste(chute)){
        printf("Você acertou: a palavra tem a letra %c\n\n", chute);
	} else {
	    printf("Você errou: a palavra não tem a letra %c\n\n", chute);
	}
	chutes[chutesdados]=chute; //Armazena os chutes no vetor chutes
	chutesdados++;
}


int jachutou(char letra){ // uso de ponteiros para acessar o vetor chutes
	int achou = 0;
	for (int j=0; j<chutesdados; j++){ //Verifica se a letra chutada está no vetor palavrasecreta
		if(chutes[j]==letra){
			achou=1;
			break;
		}
	}
	return achou;
}

void desenhaforca(){
	printf("Você já deu %d chutes\n", chutesdados);
	int erros = chuteserrados();

	if(erros == 0) {
        printf(" _______    \n");
        printf(" |/     |   \n");
        printf(" |          \n");
        printf(" |          \n");
        printf(" |          \n");
        printf(" |          \n");
        printf(" |          \n");
        printf("_|___       \n");
}
    if(erros == 1){
        printf(" _______    \n");
        printf(" |/     |   \n");
        printf(" |     (_)  \n");
        printf(" |          \n");
        printf(" |          \n");
        printf(" |          \n");
        printf(" |          \n");
        printf("_|___       \n");
    }
    if(erros == 2){
        printf(" _______    \n");
        printf(" |/     |   \n");
        printf(" |     (_)  \n");
        printf(" |      |   \n");
        printf(" |      |   \n");
        printf(" |          \n");
        printf(" |          \n");
        printf("_|___       \n");
    }
    if(erros == 3){
        printf(" _______    \n");
        printf(" |/     |   \n");
        printf(" |     (_)  \n");
        printf(" |     \\|/  \n");
        printf(" |      |   \n");
        printf(" |          \n");
        printf(" |          \n");
        printf("_|___       \n");
    }
    if(erros == 4){
        printf(" _______    \n");
        printf(" |/     |   \n");
        printf(" |     (_)  \n");
        printf(" |     \\|/  \n");
        printf(" |      |   \n");
        printf(" |     / \\ \n");
        printf(" |          \n");
        printf("_|___       \n");
    }

	for (int i=0; i<strlen(palavrasecreta);i++){
			if (jachutou(palavrasecreta[i])){
				printf("%c ", palavrasecreta[i]); //Se achou, imprime a Letra
			} else {
				printf("_ "); //Se nessa iteração não achou uma letra, imprime underline _
			}
		}
	printf("\n");
}

int letraexiste(char letra) {

    for(int j = 0; j < strlen(palavrasecreta); j++) {
        if(letra == palavrasecreta[j]) {
            return 1;
        }
    }
    return 0;
}

int chuteserrados(){
    int erros = 0;
	for (int i=0; i<chutesdados; i++){
		if(!letraexiste(chutes[i])) {
        erros++;
		}
	}
	return erros;
}

int enforcou(){
	return chuteserrados() >= 5;
}

int ganhou(){
	for (int i=0; i<strlen(palavrasecreta);i++){
		if (!jachutou(palavrasecreta[i])){
			return 0;
		}
	}
	return 1;
}

void adicionapalavra(){
    char quer;
    printf("Você deseja adicionar uma nova palavra no jogo (S/N)?");
    scanf(" %c", &quer);

    if(quer=='S'){
        char novapalavra[TAMANHO_PALAVRA];
        printf("Digite uma nova palavra, em letras maiúsculas ");
        scanf("%s", novapalavra);

        FILE* f;
        f = fopen("palavras.txt", "r+"); //O uso do a significa append, ou seja, que vamos inserir no fim do arquivo.
        if (f==0){                      // O uso do r+ permite ler e alterar um arquivo.
            printf("Banco de palavras não disponível \n\n");
            exit(1);
        }
        int quantidade;
        fscanf(f, "%d", &quantidade);
        quantidade++; //atualiza a quantidade de palavras
        fseek(f, 0, SEEK_SET); //Reposiciona o ponteiro para o início do arquivo
        fprintf(f, "%d", quantidade);

        fseek(f, 0, SEEK_END); //Reposiciona o ponteiro para o final do arquivo
        fprintf(f, "\n%s", novapalavra); //adiciona a nova palavra no final do arquivo palavras.txt
        fclose(f); //fecha o arquivo
    }
}



int main (){
    setlocale(LC_ALL,"Portuguese");
	abertura();
	escolhepalavra();

	do {
		desenhaforca();
		chuta();
	} while (!ganhou() && !enforcou());    //CONTINUA O LOOP ENQUANTO NÃO ACERTOU E NÃO ENFORCOU
									     // A FUNÇÃO ENFORCOU() RETORNA O VALOR 1 (VERDADEIRO) SE A CONDIÇÃO erros>=5 FOR SATISFEITA E
								       	// RETORNA 0 (FALSO) SE A CONDIÇÃO NÃO FOR SATISFEITA.
    if(ganhou()) {
    printf("\nParabéns, você ganhou!\n\n");
    printf("              ...-*%%%%%%#-..                                        \n");
    printf("              .*%==%%%%%**#%:                                        \n");
    printf("            ..-*:..*%%%%=+*#%..                                      \n");
    printf("            ..**:..=#**#++**@..                          ....        \n");
    printf("            ..##*=:.:=+*****@:.                  ..::. ...**.        \n");
    printf("            ..%##**********#@-.                  .+@@...:%@%. .....  \n");
    printf("            ..%*---=+**+=-:*%-.                  .%@@..=%%@....::..  \n");
    printf("            ..##+=-=+***==+#@..                  :%@@.-@@@-..*%@#..  \n");
    printf("            ..=%%#########%%=                   .=%@@-@%@%.=%%@+...  \n");
    printf("              .%%%%%####%@@@@..                ..+%%@@#%%@%#@%....:::\n");
    printf("              .+%%%%##%%@@@@@@%*...      ..=#...+%##**###*%@*..*#%%%. \n");
    printf("      .......:#@@%%#####@@@@@@@%@@@%-......@@%#+#:==---=+*#%+#%@%-... \n");
    printf("    ..-%%%%%@@@%%@@%%%%@@@%#%@@%%%%%%%%%%%%%%@@#%--.....-+#%@%...    \n");
    printf("....+%%%@@%%%@%%%#%#%%%%%%@%*%%%%%#%%%%%%%%%%%@@#+-:....-=*%%-.      \n");
    printf(".:%%%%%%%%%%#%#%%%%%%%%%%%%%%%@@%@@%%%%%@@%%%%@@%#*+==--+*##@..      \n");
    printf(".%@@%%%##*******##%%%%%%%%%#@@#%%#%%#%%##%%#@%%%@@###*##%#%=.        \n");
    printf("-@@%%%%#+=-::-====+=--=***++#@%@@##%%%##%%%%%@@#%%%%@%%%%%...        \n");
    printf("-@@@@%%*........:----.:=+*%@@@@@@%#%#%%%@@@%%@%%%@@@%%%#=.           \n");
    printf(":@@@%%%#=.....:-+*==-.=%%@%@%@@@@%@@@@@%@@@@@@@@@@@@@@%+.            \n");
    printf(".@%@%%%%*-..-=+*##%##%%%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@+..             \n");
    printf(".-%@@%%%%######%%%%%%%%%@@@@@@@@@@@@@%@%===--::::::...               \n");
    printf(".%%@@@@@@@%%%%%%%%%%%%@@%@%%%@@@@@@@@@@.                              \n");
    printf("-@@@@@@@@@@%%%%%%%%%@@@@@@@@@@@@@@@@%%#.                              \n");
    printf("+@@@@@@@@@@@@@%@%%@@@@@@@@@@@@@@@@@@%@:                               \n");
    printf("#@@@@@@@@@@@@@@%@@@@@@@@@@@@@@@@@@@@@#.                               \n");
    printf("#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:.                               \n");
    }
    else {
    printf("\nPuxa, você foi enforcado!\n");
    printf("A palavra era **%s**\n\n", palavrasecreta);
    printf("   ....  .... ..... ....  ....  .... ..... .... .....  ...  ....  .\n");
    printf("..................................................................\n");
    printf("...  ....  .... ..... ....  ....::--+=-:.... .... .....  ...  ....\n");
    printf("  ....  .... ..... ....  .:*%%%#######%#%%@@*:......  ...  ....  .\n");
    printf(".......................:*%#%%######%%%@@@@@@@@@@*:................\n");
    printf("...  ....  .... ..... -%%%%%%@@@@@@@@@@@@@@@@@@@@@*....  ...  ....\n");
    printf("  ....  .... ..... ...+*#%%*%@@@@@@@%@@@#%@@@@@@%%%+. ...  ....  .\n");
    printf("..........................+**+::--+#%#+#**=---:...................\n");
    printf("...  ....  .... ..... ....+***::::=-=++#**-. .... .....  ...  ....\n");
    printf("..........................-#*##%###%%##*#*........................\n");
    printf("........................-@***********#****%+......................\n");
    printf("...  ....  .... ..... .*#************#******#:... .....  ...  ....\n");
    printf("......................##**:*--********+-%:=**#:...................\n");
    printf("  ....  .... ..... .:%#***+:-+***#*###*+-=+**##-+:..  ...  ....  .\n");
    printf("...  ....  ......:=#%%%#*************#******#*%-.......  ...  ....\n");
    printf("...................**=#*===+******************%@:::...............\n");
    printf("  ....  .... ...=:**==========+*****#@*********#*.... ...  ....  .\n");
    printf("...  ....  .... .++============+*%@*#@*******%#*#:.....  ...  ....\n");
    printf("................=*=======**+-::::+%#%%************................\n");
    printf("  ....  .... ...%======#+:::::===:--+##**********%=.  ...  ....  .\n");
    printf("...  ....  ....#==++=+#-=-=:::-::::---+#**********%....  ...  ....\n");
    printf("...  ....  ...++==%-*+::::::::::::::---=#*********#=...  ...  ....\n");
    printf("  ....  .... .+==++=+::::::::-::::=++---=##*******#*. ...  ....  .\n");
    printf(".............:+==*=+=-=-:::-=*+-::::::-+==*##******#:.............\n");
    printf(".............-+==*=*-=::::::::::::::::------=*##***#:.............\n");
    printf("  ....  .... ++=+*=#::::::::::::::::::----------+#*#: ...  ....  .\n");
    printf(".............*+=+*=*:::::::::::::::::::---------=#*#:.............\n");
    printf("...  ....  ..++=**++:::::::::::::::::::---------=#**:..  ...  ....\n");
    printf("  ....  .... :#*#*++:::::::::::::::::::---------+***. ...  ....  .\n");
    printf(".............:*%**+#::::::::::::::::::----------+#*#..............\n");
    printf("...  ....  ....:=*=#::::::::::::::::::----------#*#+...  ...  ....\n");
    printf("  ....  .... ...-*=++::::::::::::::::----------##*@:  ...  ....  .\n");
    printf(".................*+=*+::::::::::::::----------#**%=...............\n");
    printf("...  ....  .... .:%===%=::::::::::----------=#**#=.....  ...  ....\n");
    printf("...................#===+*=:::::-----------+#***#+.................\n");
    printf("....................#+==+*#%+----------+%#***##...................\n");
    printf("...  ....  .... .....-%%%%#****##@####***###%+... .....  ...  ....\n");
    printf(".........................:--::..:-=++%@@@@@@@@@@@@@@@@**+-:::.....\n");
    printf("..................................................................\n");
    printf("...  ....  .... ..... ....  ....  .... ..... .... .....  ...  ....\n");
    printf("..................................................................\n");
    }

    adicionapalavra();

	return 0;
}
