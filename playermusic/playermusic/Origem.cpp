#include<stdio.h>							   
#include<stdlib.h>
#include<string.h>

//declarção de funções
int menu();
void InserirInicio(int num, char nbanda[], char nmusica[]);
void InserirFim(int num, char nbanda[], char nmusica[]);
void InserirMeio(int num, int posicao, char nbanda[], char nmusica[]);
int Remover(char nmusica[]);
void Listar();

// estrutura do dado a ser salvo
struct ElementoDaLista_Simples {
	int duracao;
	char nbanda[50], nmusica[50];
	struct ElementoDaLista_Simples* prox;
} *Head;

int  main() {

	// declaração e inicialização de variaveis
	int op, num, pos, c;
	char nbanda[50], nmusica[50];
	Head = NULL;

	// loop do menu
	while (1) {
		op = menu();
		switch (op) {
		case 1:
			printf("Digite a duracao da musica em segundos: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			printf("Digite o nome da banda/artista: ");
			gets_s(nbanda);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			printf("Digite o nome da musica: ");
			gets_s(nmusica);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			InserirInicio(num, nbanda, nmusica);
			break;
		case 2:
			printf("Digite a duracao da musica em segundos: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			printf("Digite o nome da banda/artista: ");
			gets_s(nbanda);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			printf("Digite o nome da musica: ");
			gets_s(nmusica);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			InserirFim(num, nbanda, nmusica);
			break;
		case 3:
			printf("Digite a posicao que deseja inserir a musica: ");
			scanf_s("%d", &pos);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			printf("Digite a duracao da musica em segundos: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			printf("Digite o nome da banda/artista: ");
			gets_s(nbanda);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			printf("Digite o nome da musica: ");
			gets_s(nmusica);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			InserirMeio(num, pos, nbanda, nmusica);
			
			break;
		case 4:
			int res;
			printf("Digite o nome da musica que deseja excluir da lista: ");
			gets_s(nmusica);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			res = Remover(nmusica);
			if (res == 1) {
				printf("Musica removida. \n");
				system("pause");
			}
			else {
				printf("Musica nao encontrado. \n");
				system("pause");
			}
			break;
		case 5:
			Listar();
			break;
		case 6:
			return 0;
		default:
			printf("Invalido\n");
		}
	}
	return 0;
}

// desenvolvimento das funções
int menu() {
	int op, c;
	system("Cls");

	printf("1.Inserir musica no inicio da playlist\n");
	printf("2.Inserir musica no fim da playlist\n");
	printf("3.Inserir musica no meio da playlist\n");
	printf("4.Remover musica da playlist\n");
	printf("5.Mostrar playlist\n");
	printf("6.Sair\n");
	printf("Digite sua escolha: ");

	scanf_s("%d", &op);
	while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.

	system("Cls");
	return op;
}

void InserirInicio(int num, char nbanda[], char nmusica[])
{
	// declarando uma variavel alocando espaço na memoria e atribuindo valor aos elementos da variavel
	ElementoDaLista_Simples* NovoElemento;
	NovoElemento = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));
	NovoElemento->duracao = num;
	strcpy_s(NovoElemento->nbanda, nbanda);
	strcpy_s(NovoElemento->nmusica, nmusica);

	// verificando se existe um head
	if (Head == NULL)
	{
		//se não existe atribui o novo elemento ao head e nulo ao ponteiro que aponta para o proximo elemento
		Head = NovoElemento;
		Head->prox = NULL;
	}
	else
	{
		//caso exista atribui ao ponteiro proximo o endereço do atual head e torna o novo elemento o head (atribui ao ponteiro head o endereço do novo elemento)
		NovoElemento->prox = Head;
		Head = NovoElemento;
	}
}

void InserirFim(int num, char nbanda[], char nmusica[])
{
	//criados dois elementos um para os novos dados e outro para varredura
	ElementoDaLista_Simples* NovoElemento;
	NovoElemento = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));
	ElementoDaLista_Simples* ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));

	// atribuindo valores as variaveis do novo elemento
	NovoElemento->duracao = num;
	strcpy_s(NovoElemento->nbanda, nbanda);
	strcpy_s(NovoElemento->nmusica, nmusica);

	// verificando se o head existe caso não exista atribui o novo elemento a head
	if (Head == NULL)
	{
		Head = NovoElemento;
		Head->prox = NULL;
	}
	else
	{
		// caso exista o elemento de varredura passara por todos os elementos ate encontrar um que tenha o ponteiro para o proximo elemento nulo
		ElementoVarredura = Head;
		while (ElementoVarredura->prox != NULL)
			ElementoVarredura = ElementoVarredura->prox;
		// encontrado o elemento com ponteiro prox nulo elemento de varredura recebe o novo elemento e o ponteiro prox do novo elemento recebe nulo
		ElementoVarredura->prox = NovoElemento;
		NovoElemento->prox = NULL;
	}
}

void InserirMeio(int num, int posicao, char nbanda[], char nmusica[])
{
	//criados tres elementos um para os novos dados e outro para varredura e um auxiliar para mover os dados
	ElementoDaLista_Simples* NovoElemento;
	NovoElemento = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));
	ElementoDaLista_Simples* ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));
	ElementoDaLista_Simples* ElementoAuxiliar;
	ElementoAuxiliar = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));

	// atribuindo valores as variaveis do novo elemento
	NovoElemento->duracao = num;
	strcpy_s(NovoElemento->nbanda, nbanda);
	strcpy_s(NovoElemento->nmusica, nmusica);

	// verificando se a posição escolhida é 0
	if (posicao == 0)
	{
		// verifica se a lista está vazia caso sim o novo elemento se torna o head e não aponta para ninguem
		if (Head == NULL) {
			Head = NovoElemento;
			Head->prox = NULL;
		}
		//caso não esteja vazia o novo elemento se torna o head e aponta para o antigo head
		else {
			ElementoVarredura = Head;
			Head = NovoElemento;
			Head->prox = ElementoVarredura->prox;
		}
	}
	else
	{
		// verifica se a lista está vazia caso sim o novo elemento se torna o head e não aponta para ninguem
		if (Head == NULL) {
			Head = NovoElemento;
			Head->prox = NULL;
		}
		else {
			/* caso não esteja vazia seja maior que 0 o elemento de varredura recebe o head e percorre as posições baseado na posição solicitada e trocando os valores de posição para que
			o novo elemento fique na posição desejada*/
			ElementoVarredura = Head;
			for (int i = 0; i < posicao - 1; i++)
				ElementoVarredura = ElementoVarredura->prox;

			ElementoAuxiliar = ElementoVarredura->prox;
			ElementoVarredura->prox = NovoElemento;
			NovoElemento->prox = ElementoAuxiliar;
		}
	}
}

int Remover(char nmusica[])
{
	ElementoDaLista_Simples* ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));
	ElementoDaLista_Simples* Anterior;
	Anterior = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));

	ElementoVarredura = Head;
	while (ElementoVarredura != NULL) {
		if (strcmp(ElementoVarredura->nmusica, nmusica) == 0) {
			if (ElementoVarredura == Head) {
				Head = ElementoVarredura->prox;
				free(ElementoVarredura);
				return 1;
			}
			else {
				Anterior->prox = ElementoVarredura->prox;
				free(ElementoVarredura);
				return 1;
			}
		}
		else {
			Anterior = ElementoVarredura;
			ElementoVarredura = ElementoVarredura->prox;
		}
	}
	return 0;
}

void Listar()
{
	//criando elemento de varredura e alocando espaço na memoria e recebe os dados do head
	ElementoDaLista_Simples* ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));
	ElementoVarredura = Head;
	int indice = 0;
	//verifica se o head existe caso não exista retorna msg
	if (ElementoVarredura == NULL) {
		printf_s("Nao existem musicas na playlist");
		return;
	}
	printf("Indice | Banda | Nome da Musica | duracao \n");
	// enquanto o elemento de varredura for diferente de nulo ele imprime na tela a msg e recebe o valor do proximo elemento da lista
	while (ElementoVarredura != NULL) {
		printf("%d | %s | %s | %d seg \n", indice, ElementoVarredura->nbanda, ElementoVarredura->nmusica, ElementoVarredura->duracao);
		ElementoVarredura = ElementoVarredura->prox;
		indice++;
	}
	printf("\n");

	system("pause");
	return;
}
