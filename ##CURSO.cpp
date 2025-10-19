#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca�o�s de texto por regi�o
#include <string.h> // Biblioteca respos�vel por cuidar das string

 int Registro()//Fun��o responsavel por cadastrar os usu�rios no sistema
 
{
	//Inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado");//Coletando informa��es do usu�rio
	scanf("%s", cpf);//refere-se a string
	
	strcpy(arquivo, cpf); //Respos�vel por copiar os valores das strig
	
	FILE *file; // cria o arquivo
	file= fopen(arquivo, "w"); // Respons�vel por criar o arquivo e o "w" significa escrever
	fclose(file);// Encerramentodo do arquivo ( informa��es do CPF)
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");//respons�vel por cadastrar o nome do usu�rio
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");//respons�vel por cadastrar o sobrenome do usu�rio
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastado:");//respons�vel por cadastrar o cargo do usu�rio
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");//Respons�vel para abrir o arquivo no sistema
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");//Respons�vel para pausar a tela no menu escolhido
}

 int Consultar()
 
{
	setlocale(LC_ALL,"portuguese");// definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");//respons�vel por cadastrar o CPF do usu�rio
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, arquivo inexistente!\n");// Respons�vel para quando nao encontrar o usu�rio no sitema
	}
	
	while(fgets(conteudo,200,file)!= NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");	
	}
	   system ("pause");//Serve para pausar a tela no menu escolhido
	
	
}
 int Deletar()
 {
 	 char cpf[40];
 	 
 	 printf("Digite o CPF a ser deletado:");//respons�vel por deletar o CPF  do usu�rio
 	 scanf("%s", cpf);
 	 
 	 remove(cpf);
 	 
 	 FILE *file;
 	 file = fopen(cpf,"r");// "r" significa ler
 	 
 	 if(file == NULL)
 	 {
 	 	printf("O usu�rio n�o se encontra no sitema!\n");
 	 	system("pause");//Serve para pausar a tela no menu escolhido
	  }


}
int main()
{

	
	int opcao=0; // defini�oes vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	  system("cls");//Respons�vel por limpar a tela
	  
	  setlocale(LC_ALL,"portuguese");// definindo a linguagem
	
	  printf("###Cart�rio da EBAC###\n\n");// inicio do menu
	  printf("Ecolha a op��o desejada do menu\n\n");
	  printf("\t1- Registrar nomes\n");
      printf("\t2- Consultar nomes\n");
      printf("\t3- Deletar nomes\n\n");// o final do menu
      printf("\t4- Sair do sistema\n\n");
	  printf("escolha uma op��o:");
	  scanf("%d", &opcao); //armazenamento de informa��es do usu�rio
	
	  system("cls");//Respons�vel por limpar a tela
	  
	  switch(opcao)//Inicio da sele��o do menu
	  {
	  	 case 1:
	  	  Registro();//Chamada de fun��es
		  break;
		  
		 case 2:	
		  Consultar();
		  break;
		  
		 case 3:
		  Deletar();
		  break;
		
		 case 4:
		  printf("Obrigado por ultilizar o sistema!\n");
		  return 0;
		  break;	
			
		 default:
		    printf("Essa op��o n�o est� dispon�vel\n");
		    system("pause");	
		    break;
		    // fim da sele��o do menu
	  	 }
      
	 
	 
	 }
       

}
