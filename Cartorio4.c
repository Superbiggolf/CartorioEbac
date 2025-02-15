#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca para aloca��o de espa�os em mem�ria (fun��es, arrays)
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel pelas strings

int main()
{
	int opcao=0; //definindo vari�veis
	int laco=1; //la�o para repeti��o
	
	for(laco=1;laco=1;) //"for(;)" tamb�m funcionaria, idem para "while(1)"
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cart�rio EBAC ###\n\n"); //"\n" pula linha, "\t" d� um espa�o CUIDADO COM A DIRE��O DA BARRA

		printf("Escolha a op��o desejada:\n\n");

		printf("\t1- Registrar nomes\n");
		printf("\t2- Consultar nomes\n");
		printf("\t3- Deletar nomes\n\n");
		printf("Op��o: ");
	
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
			printf("Essa op��o n�o est� dispon�vel\n");
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
	
	printf("Voc� escolheu o registro de nomes!\n\n");
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	
	strcpy(arquivo,cpf); //n�o pode usar x=y pra string, precisa de uma funl��o pr�pria para copiar
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "W"); //cria o arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" � para incluir nova informa��o no arquivo
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
	
	printf("Voc� escolheu consultar os nomes!\n\n");
	printf("Digite o CPF do usu�rio a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file==NULL)
	{
		printf("N�o foi poss�vel encontrar o usu�rio.\n");
	}

	while(fgets(conteudo,200,file) != NULL)
	{
		printf("Essas s�o as informa��es do usu�rio: \n");
		printf("CPF - Nome - Sobrenome - Cargo \n");
		printf("%s",conteudo); //ERRO QUE FEZ EU PERDER TEMPO: USAR "%S" AO INV�S DE "%s"
		printf("\n\n");	
	}

	fclose(file);	//precisa fechar o arquivo
	system("pause");
}

int deletar()
{
	char cpf[40];	
	
	printf("Voc� escolheu deletar nomes!\n\n");
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);	//sem isso o arquivo n�o � deletado
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);	
		
	if(file==NULL)
	{
		printf("N�o foi poss�vel encontrar o usu�rio.\n");
	}

	if(file!=NULL)
	{
		remove(cpf);
		printf("Usu�rio deletado com sucesso!\n");
	}

	fclose(file);	//sem esse o arquivo n�o � deletado
	system("pause");
	
	
}
