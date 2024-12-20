#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // Biblioteca respons�vel por cuidar das strings

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	char arquivo[40]; // Aqui abrimos a fun��o character com o nome da vari�vel e a quantidade de caracteres (strings)
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); // Aqui � a pergunta ao usu�rio
	scanf("%s", cpf); // Aqui � a resposta do usu�rio
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings do cpf(digitado pelo usu�rio) para a fun��o arquivo
	
	FILE *file; // Aqui a biblioteca ir� buscar uma estrutura FILE e criar uma file
	file = fopen(arquivo, "w"); //Aqui o file abri o arquivo com o nome da vari�vel, e o w � para escrever (gravar um novo arquivo) no file
	fprintf(file,"CPF: ");
	fprintf(file, cpf); //Aqui salva o valor da vari�vel
	fclose(file); //Aqui fecha o arquivo

	file = fopen(arquivo, "a"); // Aqui vai abrir o arquivo para atualizar
	fprintf(file,"\nnome: "); //Aqui ir� inserir  o conte�do (no caso 'nome') a ser mostrado
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nsobrenome: ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",\ncargo: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fprintf(file,".\n\n");
	fclose(file);

	system("pause");
		
}
int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40]; // Aqui criamos novamente a fun��o e a vari�vel
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // Aqui abrimos o arquivo e o "r" � para ler o arquivo gravado
	
	if(file== NULL) // Aqui se l�: (if) se o arquivo "file" for igual a (NULL) nulo
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	printf("\nEssas s�o as informa��es do usu�rio: ");
	
	while(fgets(conteudo, 200, file) != NULL) // Aqui se l�: (while)enquanto (fgets) busca o arquivo e escrevo na vari�vel "conte�do" at� 200 valores dentro do arquivo "file" e diferente de nulo
	{
		printf("%s", conteudo);
		
	}
	fclose(file);
	system("pause");
}

int deletar()
{
	char cpf[40];
	char arquivo[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
   
	else 
	{
		fclose(file);
	
		remove(cpf);
		printf("Usu�rio removido com sucesso!\n");
		system("pause");
	}
	fclose(file);
}


int main()
{
	int opcao=0; // Aqui estamos definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
			system("cls"); // Aqui o comando � para limpar a tela
			setlocale(LC_ALL, "Portuguese"); // Aqui identificamos o idioma � ser utilizado

		printf("### Cart�rio da EBAC ###\n\n"); // T�tulo do software
		printf("Escolha a op��o desejada do menu:\n\n"); // T�tulo de op��o para o usu�rio
		printf("\t1 - Registrar nomes\n"); // a��o do usu�rio
		printf("\t2 - Consultar nomes\n"); // a��o do usu�rio
		printf("\t3 - Deletar nomes\n\n"); // a��o do usu�rio
		printf("Op��o: ");
	
		scanf("%d", &opcao);// Aqui estamos armazenando a escolha do usu�rio
	
		system("cls");// Aqui limpamos a tela
		
		switch(opcao)// Aqui iniciamos a sele��o do usu�rio
		{
			case 1:
			registro(); //Aqui chama a fun��o desejada pelo usu�rio
			break;
		
			case 2:
		    consulta();
			break;
		
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		}// Aqui finalizamos a sele��o
	
	}
}



