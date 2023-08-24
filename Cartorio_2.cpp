#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca�o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registrar() //Fun��o de cadastro 
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem 
	
	 // inicio cria��o das vari�veis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // Final da cria��o de vari�veis 
    
    printf("Digite o CPF a ser cadastrado:\n");
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo,cpf); // Responsavel em copiar os valores das string
    
    FILE *file; // cria o arquivo 
    file = fopen(arquivo, "w");
    fprintf(file,cpf); // salvo o valor da variavel 
    fclose(file); // Fecha o arquivo 
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: \n");
    scanf("%s",nome);
    
    file = fopen (arquivo,"a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o sobrenome: \n");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado\n");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");    
 }

int consultar()
{ 

    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem 
      
      
     char cpf[40];
     char conteudo[200];
     
     printf("Digite o CPF para ser consultado: ");
     scanf("%s",cpf);
     
	 FILE *file;
     file = fopen(cpf,"r");
     
     if(file == NULL)
     { 
             printf("Arquivo n�o localizado! \n");
	 }
	 
	 while(fgets(conteudo, 200, file) !=NULL);
	 {
	 	 printf("\nEssas s�o as informa��es do usu�rio :");
	 	 printf("%s",conteudo);
	 	 printf("\n\n");
	 	 
	 	 system("pause");
	 }
	
}

int deletar()
{
        char cpf[40];
        
        printf("Digite o CPF a ser deletado:");
        scanf("%s",cpf);
        
        remove(cpf);
        
        FILE *file;
        file = fopen(cpf,"r");
        
        if(file == NULL)
        {
        	 printf("O usu�rio n�o se encontra no sistema! \n");
        	 system("pause");
		}
        
}

int main()
{
	int opcao=0; //Definindo as variaveis 
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	   system("cls"); // Responsavel por limpar a tela 
	
	
       setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem 
 
 
       //Titulo App 
       printf("\t### Cart�rio da EBAC ###\n\n");
       //Menu Inicio 
       printf("\tEscolha a op��o desejada do menu: \n\n");
       printf("\t 1 - Registrar nomes \n\n");//Op��es Menu
       printf("\t 2 - Consultar nomes \n\n");//Op��es Menu
       printf("\t 3 - Deletar nomes \n\n");//Op��es Menu
       printf("Op��o: "); // fim do Menu 
       scanf("%d", &opcao); //Armazenamneto a escolha do usuario
   
       system("cls");
       
       switch(opcao)
       { 
	       case 1:
       	     registrar(); // chamar as fun��es 
             break;
             
             case 2: 
             consultar();
             break;
             
             case 3:
             deletar();
             break;
             
             default: 
             printf("Essa opc�o n�o est� disponivel \n");
             system("pause");
             break;
             
	   }
   }
}

