#include <stdio.h> //Biblioteca de comunicaçâo com o usuário
#include <stdlib.h> //biblioteca de alocaçâo de espaço em memória
#include <locale.h> //Biblioteca de alocaçoês de texto por região
#include <string.h> // Biblioteca resposável por cuidar das string

 int Registro()//Função responsavel por cadastrar os usuários no sistema
 
{
	//Inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado");//Coletando informações do usuário
	scanf("%s", cpf);//refere-se a string
	
	strcpy(arquivo, cpf); //Resposável por copiar os valores das strig
	
	FILE *file; // cria o arquivo
	file= fopen(arquivo, "w"); // Responsável por criar o arquivo e o "w" significa escrever
	fclose(file);// Encerramentodo do arquivo ( informações do CPF)
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");//responsável por cadastrar o nome do usuário
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");//responsável por cadastrar o sobrenome do usuário
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastado:");//responsável por cadastrar o cargo do usuário
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");//Responsável para abrir o arquivo no sistema
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");//Responsável para pausar a tela no menu escolhido
}

 int Consultar()
 
{
	setlocale(LC_ALL,"portuguese");// definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");//responsável por cadastrar o CPF do usuário
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, arquivo inexistente!\n");// Responsável para quando nao encontrar o usuário no sitema
	}
	
	while(fgets(conteudo,200,file)!= NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");	
	}
	   system ("pause");//Serve para pausar a tela no menu escolhido
	
	
}
 int Deletar()
 {
 	 char cpf[40];
 	 
 	 printf("Digite o CPF a ser deletado:");//responsável por deletar o CPF  do usuário
 	 scanf("%s", cpf);
 	 
 	 remove(cpf);
 	 
 	 FILE *file;
 	 file = fopen(cpf,"r");// "r" significa ler
 	 
 	 if(file == NULL)
 	 {
 	 	printf("O usuário não se encontra no sitema!\n");
 	 	system("pause");//Serve para pausar a tela no menu escolhido
	  }


}
int main()
{

	
	int opcao=0; // definiçoes variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	  system("cls");//Responsável por limpar a tela
	  
	  setlocale(LC_ALL,"portuguese");// definindo a linguagem
	
	  printf("###Cartório da EBAC###\n\n");// inicio do menu
	  printf("Ecolha a opção desejada do menu\n\n");
	  printf("\t1- Registrar nomes\n");
      printf("\t2- Consultar nomes\n");
      printf("\t3- Deletar nomes\n\n");// o final do menu
      printf("\t4- Sair do sistema\n\n");
	  printf("escolha uma opção:");
	  scanf("%d", &opcao); //armazenamento de informações do usuário
	
	  system("cls");//Responsável por limpar a tela
	  
	  switch(opcao)//Inicio da seleção do menu
	  {
	  	 case 1:
	  	  Registro();//Chamada de funções
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
		    printf("Essa opção não está disponível\n");
		    system("pause");	
		    break;
		    // fim da seleção do menu
	  	 }
      
	 
	 
	 }
       

}
