/*Autor: Amanda Umlauf e Jo�o Victor Campregher
Data:05/02/2022
Fun��o: Um programa em C que realiza a grava��o dos dados em um arquivo texto. 
Esse � um sistema de atendimento de uma autoescola, o usu�rio insere seus dados e informa��es referente a idade, caso seja maior de 18 anos, seus dados s�o salvos no arquivo e podem ser consultados pelos atendentes. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct cadastro //Programa��o C - Structs. Structs, tamb�m conhecidas como Registros, definem tipos de dados que agrupam vari�veis sob um mesmo tipo de dado. A ideia de usar uma struct � permitir que, ao armazenar os dados de uma mesma entidade, isto possa ser feito com uma �nica vari�vel.
{
	char nome[50];
    int cpf;
	int telefone;
	char endereco[100];
	char cep[10];
	char diaNasc[10];
	int anoNasc;
    int idade;
    int idadeFaltante;
	char email[50];
}; 

struct cadastro aluno;

FILE *pArq;//cria arquivo

void cadastrar(){ //realiza o cadastro de cada um dos alunos
    
    pArq = fopen("CadastroAlunos.txt", "a");//abre o arquivo ou cria em caso de n�o existir
	if(pArq == NULL)//verifica se arquivo abriu corretamente
	{
		printf("Ocorreu um erro! O arquivo n�o pode ser aberto.\n");
	}
	else
	{
        int idade, idadeFaltante; //declara��o de variaveis 

        printf("\nNome: \n");
        gets(aluno.nome);
        fflush(stdin);

        printf("CPF (Apenas n�meros, sem ponto e caracteres especiais): \n");
        scanf("%d", &aluno.cpf);
        fflush(stdin);

        printf("Telefone (Apenas n�meros, sem ponto e caracteres especiais): \n");
        scanf("%d", &aluno.telefone);
        fflush(stdin);

        printf("Endere�o (Rua e N�mero): \n");
        gets(aluno.endereco);
        fflush(stdin);

        printf("Informe o CEP (Apenas n�meros, sem ponto e caracteres especiais): \n");
        gets(aluno.cep);
        fflush(stdin);

        printf("Informe dia e m�s de nascimento: (dd/mm) \n");
        gets(aluno.diaNasc);
        fflush(stdin);

        printf("Informe o ano de nascimento: \n");
        scanf("%d", &aluno.anoNasc);
        fflush(stdin);

        printf("E-mail: \n");
        gets(aluno.email);
        fflush(stdin);


        idade = 2022 - aluno.anoNasc;
        idadeFaltante = 18 - idade;

        if(idade >= 18){//verifica se idade � maior que 18 anos 
            printf("Aluno pode se matricular e tirar habilita��o.\n");
            printf("Cadastro salvo com sucesso!\n");
            fprintf(pArq, "Nome: %s\n", aluno.nome);//salva informa��es no arquivo 
            fprintf(pArq, "CPF: %d\n", aluno.cpf);
            fprintf(pArq, "Telefone: %d\n", aluno.telefone);
            fprintf(pArq, "Endere�o: %s\n", aluno.endereco);
            fprintf(pArq, "CEP: %s\n", aluno.cep);
            fprintf(pArq, "Data de Nasc: %s %d\n", aluno.diaNasc, aluno.anoNasc);
            fprintf(pArq, "Email: %s\n", aluno.email);
       
        }else{//se n�o for, n�o h� cadastro no arquivo
            printf(" ");
            printf("\nAluno ainda n�o pode tirar habilita��o, a idade m�nima � 18 anos. Matr�cula s� ser� poss�vel em %d anos\n", idadeFaltante);
            }
    }
	fclose(pArq);
}


void listar(){

	pArq = fopen("CadastroAlunos.txt", "r");
	if(pArq == NULL)
	{
		printf("Ocorreu um erro! O arquivo n�o pode ser aberto.\n");
	}else{
   		while(!feof (pArq)){//l� o arquivo at� o seu final 
		fscanf(pArq, "Nome:%s\n", aluno.nome);//l� informa��es do arquivo
        fscanf(pArq, "CPF:%d\n", &aluno.cpf);
        fscanf(pArq, "Telefone:%d\n", &aluno.telefone);
        fscanf(pArq, "Endere�o:%s\n", aluno.endereco);
        fscanf(pArq, "CEP:%s\n", aluno.cep);
        fscanf(pArq, "Data de Nasc:%s %d\n", aluno.diaNasc, &aluno.anoNasc);
        fscanf(pArq, "Email:%s\n", aluno.email);
        printf("Nome: %s\n", aluno.nome);//imprime na tela as informa��es existentes no arquivo
        printf("CPF: %d\n", aluno.cpf);
        printf("Telefone: %d\n", aluno.telefone);
        printf("Endere�o: %s\n", aluno.endereco);
        printf("CEP: %s\n", aluno.cep);
        printf("Data de Nasc: %s %d\n", aluno.diaNasc, aluno.anoNasc);
        printf("Email: %s\n", aluno.email);   
        }
    }
    system("pause");
    fclose(pArq);
}

void excluir(){

    printf("Arquivo Removido\n");    
    remove("CadastroAlunos.txt"); //exclui o arquivo e todas suas informa��es
    system("pause");
}

void pesquisar(){

    int cpf;

    pArq = fopen("CadastroAlunos.txt", "r");
	if(pArq == NULL)
	{
		printf("Ocorreu um erro! O arquivo n�o pode ser aberto.\n");
	}else{
        printf("Informe o cpf do cadastro que deseja consultar:");
        scanf("%d", &cpf);

        while(!feof (pArq)){//l� o arquivo at� o seu final 
            fscanf(pArq, "Nome:%s\n", aluno.nome);
            fscanf(pArq, "CPF:%d\n", &aluno.cpf);
            fscanf(pArq, "Telefone:%d\n", &aluno.telefone);
            fscanf(pArq, "Endere�o:%s\n", aluno.endereco);
            fscanf(pArq, "CEP:%s\n", aluno.cep);
            fscanf(pArq, "Data de Nasc:%s %d\n", aluno.diaNasc, &aluno.anoNasc);
            fscanf(pArq, "Email:%s\n", aluno.email);
        }
        
        if (cpf == aluno.cpf) { //compara se no arquivo h� um struct contendo o cpf informado
            printf("Nome: %s\n", aluno.nome); //imprime as informa��es, caso existam
            printf("CPF: %d\n", aluno.cpf);
            printf("Telefone: %d\n", aluno.telefone);
            printf("Endere�o: %s\n", aluno.endereco);
            printf("CEP: %s\n", aluno.cep);
            printf("Data de Nasc: %s %d\n", aluno.diaNasc, aluno.anoNasc);
            printf("Email: %s\n", aluno.email); 
        }else{
            printf("\nCadastro inexistente ou cpf incorreto\n");
            }
        system("pause");
        fclose(pArq);
    }
}

int main(){
	setlocale(LC_ALL, "Portuguese"); //coloca a linguagem em portugues, permite acentos

        int opcao;

        while (opcao != 5) {
        printf("__________________________________________________________\n");    
	    printf("Sistema de gerenciamento de clientes na Autoescola Velozes\n");
        printf("__________________________________________________________\n");
        printf("Escolha uma op��o:\n");
        printf("1 - Cadastrar\n");
        printf("2 - Pesquisar um cadastro\n");
        printf("3 - Listar todos os cadastros\n");
        printf("4 - Excluir todos os cadastros\n");
        printf("5 - Sair do programa\n");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao) {//cria um sitch, cada um possuindo uma fun��o diferente que pode 
    
            case 1:
                cadastrar();
                break;

            case 2 :
                pesquisar();
                break;
            
            case 3:
                listar();
                break;
            
            case 4:
                excluir();
                break;

            case 5:
                break;
        }
        }
    return 0;
}


