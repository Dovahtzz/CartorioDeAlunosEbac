#include <stdio.h> //biblioteca de cominuca��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o responsavel por registrar usuarios no sistema
{
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
    char sobrenome[40];
    char cargo[40];
	//final da cria��o de vari�veis
	
	printf("\tDigite o CPF a ser cadastrado:\n"); //coletando informa��o
	scanf("%s",cpf); //refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("\tDigite o nome a ser cadastrado:\n");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("\tDigite o sobrenome a ser cadastrado:\n");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("\tDigite o cargo a ser cadastrado:\n");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); //responsavel por fazer uma pausa na tela 
	
	
}

int consultar()
{
	
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("arquivo n�o localizado ou n�o existente\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int gerenciar()
{
	char cpf[40];
	
	printf("Digite o CPF do pedido que deseja deletar:\n");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL);
	{
		printf("CPF inexistente, tente novamente\n");
		system("pause");
	}
}

int main()
    {
	int opcao=0; //definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
	    setlocale(LC_ALL, "Portuguese"); //definindo linguagens
	
    	printf("### Lista de alunos EBAC ###\n\n"); //inicio do menu
    	printf("\tEscolha a op��o desejada:\n\n");
    	printf("\t1: Registro\n");
    	printf("\t2: Consulta\n");
	    printf("\t3: Gerenciar\n\n");
    	printf("op��o:"); //fim do menu
	
    	scanf("%d", &opcao); //armazenando escolha do usu�rio
 	
    	system("cls"); //limpa a tela ap�s uma a��o
   	
         switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); //chama a fun��o
      		break;
      		
      		case 2:
      		consultar();
        	break;
        	
        	case 3:
        	gerenciar();
    		break;
    		
    		default:
    		printf("Essa op��o n�o disponivel\n");
    		system("pause");
    		break;
    		
        	
		}
	
    }
	
}
