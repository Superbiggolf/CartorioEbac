#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca para alocação de espaços em memória (funções, arrays)
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável pelas strings

int main()
{
	int opcao=0; //definindo variáveis
	int laco=1; //laço para repetição
	
	for(laco=1;laco=1;) //"for(;)" também funcionaria, idem para "while(1)"
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cartório EBAC ###\n\n"); //"\n" pula linha, "\t" dá um espaço CUIDADO COM A DIREÇÃO DA BARRA

		printf("Escolha a opção desejada:\n\n");

		printf("\t1- Registrar nomes\n");
		printf("\t2- Consultar nomes\n");
		printf("\t3- Deletar nomes\n\n");
		printf("Opção: ");
	
		scanf("%d", &opcao); //%d armazena um valor inteiro
	
		system("cls"); //limpa a tela
	
		switch(opcao)
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponível\n");
			system("pause");
			break;
		}
	
	}
}

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Você escolheu o registro de nomes!\n\n");
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	
	strcpy(arquivo,cpf); //não pode usar x=y pra string, precisa de uma funlção própria para copiar
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "W"); //cria o arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" é para incluir nova informação no arquivo
	fprintf(file,cpf);	
	fprintf(file,", ");
	fprintf(file,nome);
	fprintf(file,", ");
	fprintf(file,sobrenome);	
	fprintf(file,", ");	
	fprintf(file,cargo);	
	fclose(file);	
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	char conteudo[200];
	
	printf("Você escolheu consultar os nomes!\n\n");
	printf("Digite o CPF do usuário a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file==NULL)
	{
		printf("Não foi possível encontrar o usuário.\n");
	}

	while(fgets(conteudo,200,file) != NULL)
	{
		printf("Essas são as informações do usuário: \n");
		printf("CPF - Nome - Sobrenome - Cargo \n");
		printf("%s",conteudo); //ERRO QUE FEZ EU PERDER TEMPO: USAR "%S" AO INVÉS DE "%s"
		printf("\n\n");	
	}

	fclose(file);	//precisa fechar o arquivo
	system("pause");
}

int deletar()
{
	char cpf[40];	
	
	printf("Você escolheu deletar nomes!\n\n");
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);	//sem isso o arquivo não é deletado
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);	
		
	if(file==NULL)
	{
		printf("Não foi possível encontrar o usuário.\n");
	}

	if(file!=NULL)
	{
		remove(cpf);
		printf("Usuário deletado com sucesso!\n");
	}

	fclose(file);	//sem esse o arquivo não é deletado
	system("pause");
	
	
}
