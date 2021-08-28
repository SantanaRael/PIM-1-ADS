#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SIZE 200
#include <string.h>
#include <conio.h>
#define length(array) ( sizeof (array) / sizeof (array)[i] )
#include <locale.h>

typedef struct{
	char nome[25];
	char sobrenome[25];
	char cpf [12];
	char telefone[25];
	char rua[25];
	int numero;
	char bairro[25];
	char cidade[25];
	char estado[25];
    char cep [25];
	char dataDeNascimento[25];
	char email[25];
	int dataDoDiagnostico;
	int comorbidade[25];
    int diaHoje,mesHoje,anoHoje,diaNasc,mesNasc,anoNasc;
    int dia, mes, ano;
}Cadastro;

Cadastro pessoa[SIZE];

char login[15] = "Unip";
char login1[15];
char senha[15] = "123";
char senha1[15];
char email[SIZE] [50];
char nome [SIZE] [50];
char sobrenome [SIZE] [50];
char rua [SIZE] [50];
int numero [SIZE];
int cep [SIZE] [50];
char bairro [SIZE] [50];
char cidade [SIZE] [50];
char estado [SIZE] [50];
int telefone [SIZE];
char dataDeNascimento [SIZE] [50];
int idade [SIZE];
int cpf [SIZE];
int diaHoje,mesHoje,anoHoje,diaNasc,mesNasc,anoNasc;
int dia, mes, ano;
int comorbidade;
int comor;
int op;
void cadastro();
void lista();
int main(void) {



    setlocale(LC_ALL, "Portuguese");
    printf("LOGIN: ");
    scanf("%s",login1);
    if (strcmp(login, login1) != 0)
    {
    	printf("Login invalido\n");
    	return;
    }

    printf("SENHA: ");
   	*senha1 = scanf("Password: ");
   scanf("%s",senha1);
    if (strcmp(senha, senha1) != 0)
    {
       	printf("Senha invalida");
    	return;
    }
	do{

		system("cls");
		printf("SEJA BEM-VINDO!\nNOSSO PROGRAMA VAI COLETAR ALGUMAS INFORMACOES PARA ENCAMINHAR A SECRETARIA DE SAUDE.\nFIQUE ATENTO E ATUALIZANDO O E-MAIL CADASTRADO PERIODICAMENTE PARA MAIS INFORMACOES.");
	    printf("\n--MENU--\n1 - PARA SE CADASTRAR\n3 - FECHAR O PROGRAMA.\nDIGITE UMA OPCAO:");
	    scanf(" %d", &op);
	    switch(op){
	    	case 1:
	    		cadastro();
	    		break;
	    	case 2:
	    		system("exit");
	    	    break;
	    	default:
	    		printf("SAINDO...");
	    		break;
		}

	}while(op!=3);
}

void cadastro() {
    setlocale(LC_ALL, "Portuguese");
	int linha = 0;
	do{

		fflush(stdin);

		printf("\nDIGITE O NOME COMPLETO DO PACIENTE:");
		gets(&pessoa[linha].nome);

		printf("DIGITE o CPF:");
		gets(&pessoa[linha].cpf);

		printf("DIGITE O TELEFONE PARA CONTATO COM DDD:");
		gets(&pessoa[linha].telefone);

		printf("DIGITE A RUA:");
		gets(&pessoa[linha].rua);

		printf("DIGITE O NUMERO:");
		gets(&pessoa[linha].numero);

		printf("DIGITE O BAIRRO:");
		gets(&pessoa[linha].bairro);

		printf("DIGITE A CIDADE:");
		gets(&pessoa[linha].cidade);

		printf("DIGITE O ESTADO:");
		gets(&pessoa[linha].estado);

		printf("DIGITE O CEP DA LOCALIDADE:");
		gets(&pessoa[linha].cep);

		printf("DIGITE SEU E-MAIL:");
		gets(&pessoa[linha].email);

		printf("DIGITE A DATA DO DIAGNOSTICO:(dd mm aaaa)");
		gets(&pessoa[linha].dataDoDiagnostico);
		printf("\n----Data de Entrada do Paciente----\nDigite o dia:");
	    scanf("%d", &diaHoje);
		printf("\n1 - Janeiro\n2 - Fevereiro\n3 - Março\n4 - Abril\n5 - Maio\n6 = Junho\n7 - Julho\n8 - Agosto\n9 - Setembro\n10 - Outubro\n11 - Novembro\n12 - Dezembro\nDigite o mês:");
		scanf("%d", &mesHoje);
		printf("\nDigite o ano de Entrada do Paciente:(4 digitos)");
		scanf("%d", &anoHoje);
		printf("\n----Data de Nascimento do Paciente----\n\nDigite o dia :");
	    scanf("%d", &diaNasc);
		printf("\n1 - Janeiro\n2 - Fevereiro\n3 - Março\n4 - Abril\n5 - Maio\n6 = Junho\n7 - Julho\n8 - Agosto\n9 - Setembro\n10 - Outubro\n11 - Novembro\n12 - Dezembro\nDigite o mês:");
		scanf("%d", &mesNasc);
		printf("\nDigite o ano de nascimento do paciente:(4 digitos)");
		scanf("%d", &anoNasc);
		printf("\nO PACIENTE POSSUI ALGUMA COMORBIDADE?\n");
		printf("\n--COMORBIDADES--\n1 - DIABETES\n2 - OBESIDADE\n3 - HIPERTENSAO\n4 - TUBERCULOSE\n5 - OUTROS\n6 - NENHUM .\nDIGITE UMA OPCAO:");
        scanf("%d", &comor);

    anoHoje=anoHoje-anoNasc;
    if  (anoNasc >=  65 || (comor <= 5 )){
		FILE *arq = fopen ("testepim.txt","w");
	fprintf(arq,"NOME:%s\nCPF: %s\nTELEFONE: %s\nRUA: %s\nNUMERO:%d\nBAIRRO: %s\nCIDADE: %s\nESTADO:%s\nCEP:%s\nE-MAIL: %s\nDATA DE DIAGNOSTICO:%d", pessoa[linha].nome, pessoa[linha].cpf, pessoa[linha].telefone, pessoa[linha].rua, pessoa[linha].numero, pessoa[linha].bairro, pessoa[linha].cidade, pessoa[linha].estado, pessoa[linha].cep, pessoa[linha].email, pessoa[linha].dataDoDiagnostico);
	printf("\nSALVO EM testepim.txt");
  fclose(arq);

	}

    else{
        printf("\n\nNAO ESTA NO GRUPO DE RISCO");

	}
		printf("\n\n1 - PARA CADASTRAR OUTRA PESSOA.\n0 - PARA VOLTAR PARA O MENU.\nDIGITE UMA OPCAO:");
		scanf("%d",&op);
		linha++;
	}while(op==1);

}

