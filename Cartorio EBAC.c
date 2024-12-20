#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // Biblioteca responsável por cuidar das strings

int registro() // Função responsável por cadastrar os usuários no sistema
{
	char arquivo[40]; // Aqui abrimos a função character com o nome da variável e a quantidade de caracteres (strings)
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); // Aqui é a pergunta ao usuário
	scanf("%s", cpf); // Aqui é a resposta do usuário
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings do cpf(digitado pelo usuário) para a função arquivo
	
	FILE *file; // Aqui a biblioteca irá buscar uma estrutura FILE e criar uma file
	file = fopen(arquivo, "w"); //Aqui o file abri o arquivo com o nome da variável, e o w é para escrever (gravar um novo arquivo) no file
	fprintf(file,"CPF: ");
	fprintf(file, cpf); //Aqui salva o valor da variável
	fclose(file); //Aqui fecha o arquivo

	file = fopen(arquivo, "a"); // Aqui vai abrir o arquivo para atualizar
	fprintf(file,"\nnome: "); //Aqui irá inserir  o conteúdo (no caso 'nome') a ser mostrado
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
	
	char cpf[40]; // Aqui criamos novamente a função e a variável
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // Aqui abrimos o arquivo e o "r" é para ler o arquivo gravado
	
	if(file== NULL) // Aqui se lê: (if) se o arquivo "file" for igual a (NULL) nulo
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	printf("\nEssas são as informações do usuário: ");
	
	while(fgets(conteudo, 200, file) != NULL) // Aqui se lÊ: (while)enquanto (fgets) busca o arquivo e escrevo na variável "conteúdo" até 200 valores dentro do arquivo "file" e diferente de nulo
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
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}
   
	else 
	{
		fclose(file);
	
		remove(cpf);
		printf("Usuário removido com sucesso!\n");
		system("pause");
	}
	fclose(file);
}


int main()
{
	int opcao=0; // Aqui estamos definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
			system("cls"); // Aqui o comando é para limpar a tela
			setlocale(LC_ALL, "Portuguese"); // Aqui identificamos o idioma à ser utilizado

		printf("### Cartório da EBAC ###\n\n"); // Título do software
		printf("Escolha a opção desejada do menu:\n\n"); // Título de opção para o usuário
		printf("\t1 - Registrar nomes\n"); // ação do usuário
		printf("\t2 - Consultar nomes\n"); // ação do usuário
		printf("\t3 - Deletar nomes\n\n"); // ação do usuário
		printf("Opção: ");
	
		scanf("%d", &opcao);// Aqui estamos armazenando a escolha do usuário
	
		system("cls");// Aqui limpamos a tela
		
		switch(opcao)// Aqui iniciamos a seleção do usuário
		{
			case 1:
			registro(); //Aqui chama a função desejada pelo usuário
			break;
		
			case 2:
		    consulta();
			break;
		
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
		}// Aqui finalizamos a seleção
	
	}
}



