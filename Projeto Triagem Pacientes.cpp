#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
struct pessoa{
	char cpf[16];
	char nome[100];
	char sexo[1];
	int idade;
};
//variaveis globais
struct pessoa paciente;
int total_pontos, sintomas_pontos[10]={5,1,1,1,3,10,1,1,10,3};
char sintomas_descricao[10][200]={"Tem febre?"
,"Tem dor de cabeça?"
,"Tem secreçao nasal ou espirros?"
,"Tem dor/irritaçao na garganta?"
,"Tem tosse seca?"
,"Tem dificuldade respiratória?"
,"Tem dores no corpo?"
,"Tem diarréia?"
,"Esteve em contato com alguém positivado covid-19?"
,"Esteve em locais com grande aglomeraçao?"};

cadastro_paciente(){
	printf("\nPara atendimento, faça seu cadastro:");
	printf("\nDigite seu CPF: ");
	fflush(stdin);
	gets(paciente.cpf);
	printf("\nDigite seu nome: ");
	fflush(stdin);
	gets(paciente.nome);
	printf("\nDigite seu sexo: ");
	fflush(stdin);
	gets(paciente.sexo);
	printf("\nDigite sua idade: ");
	scanf("%d",&paciente.idade);
	system("cls");
	printf("Confira seus dados: ");
	printf("\nCPF: %s",paciente.cpf);
	printf("\nNome: %s",paciente.nome);
	printf("\nSexo: %s",paciente.sexo);
	printf("\nIdade: %d",paciente.idade);	
}

void coleta_sintomas(){
	char resposta;
	total_pontos=0;
	int i=0;
	printf("\nResponda as próximas perguntas para saber a qual ala deve se dirigir");
	while(i<10){
		printf("\n%s | S-sim N-nao: ",sintomas_descricao[i]);
		fflush(stdin);
		scanf("%c",&resposta);
		if((resposta=='s')||(resposta=='S')){
			total_pontos=total_pontos+sintomas_pontos[i]; //variavel mais o que tem nela e soma o i
			i++;
		}else if((resposta=='n')||(resposta=='N')){
			i++;
		}else{
			printf("\nValor inválido, digite novamente");
		}
	}
}

void triagem(){
	system("cls");
	printf("O total de pontos foi: %d", total_pontos);
	if(total_pontos<=9){
		printf("\nEncaminhe-se para a ala de risco BAIXO");
	}else if(total_pontos>=20){
		printf("\nEncaminhe-se para a ala de risco ALTO");
	}else{
		printf("\nEncaminhe-se para a ala de risco MÉDIO");
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	cadastro_paciente();
	coleta_sintomas();
	triagem();
		
	
	return 0;
}
