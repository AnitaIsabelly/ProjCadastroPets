#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <time.h>

using namespace std;

void cabecalho();
void inserir (struct pet **);
void remover (struct pet **);
void alterar (struct pet **);
void pertence_nome (struct pet **inicio);
void pertence_especie (struct pet **inicio);
void pertence_especie_raca (struct pet **inicio);
void pertence_especie_raca_sexo (struct pet **inicio);
void contagem_especie (struct pet *inicio);
void listagem (struct pet *inicio);
void adotados (struct pet **inicio);

int contanimal = 0, contCachorro=0, contGato=0, contFurao=0, contChinchila=0, contHamster=0, contCoelho=0;

struct pet{
  	int codigo, idade, especie, status;
  	char nome[32], raca[30], sexo[2], descricao[120];
  	struct pet *prox;
};

void cabecalho(){
	cout<<"\n--------------------------------------------------------";
	cout<<"\nPontificia Universidade Catolica de Campinas\n";
	cout<<"\nCurso de Engenharia de Software";
	cout<<"\nDisciplina: Algoritmos e Estruturas de Dados A\n";
	cout<<"\nAlunos: \nAnita Isabelly Gabionetta de Souza (20002515)\nNicole Conti Bertin (20070744)\n";
	cout<<"\n--------------------------------------------------------";
	cout<<"\nOpcionais funcionando: \n";
	cout<<"Valor do Projeto: __  pontos";
	cout<<"\n--------------------------------------------------------\n\n";
}

int main(){
  	setlocale (LC_ALL,"Portuguese");
  	system("title Sistema de Cadastro de Pets");
  	system("color fd");

  	cabecalho();

  	int opcao;
	struct pet *inicio=NULL;

	do{
		cout<<"\n\nSistema de cadastro de animais\n\n";
		cout<<"1- Incluir novo\n";
		cout<<"2- Remover\n";
		cout<<"3- Alterar informações\n";
		cout<<"4- Buscar pelo nome\n";
		cout<<"5- Buscar por espécie\n";
		cout<<"6- Buscar por espécie e raça\n";
		cout<<"7- Buscar por espécie, raça e sexo\n";
    	cout<<"8- Buscar animais já adotados\n";
		cout<<"9- Quantidade de animais no sistema\n";
    	cout<<"10- Quantidade de espécies no sistema\n";
    	cout<<"11- Listar todos os animais cadastrados\n";
		cout<<"0- Sair\n\n";
		cout<<"Digite sua opcao: ";
		cin>>opcao;

		switch (opcao){
			case 1: {
        		inserir (&inicio);
				break;
			} case 2:{
        		remover(&inicio);
				break;
			} case 3:{
        		alterar(&inicio);
				break;
			} case 4: {
        		pertence_nome(&inicio);
				break;
			} case 5: {
        		pertence_especie(&inicio);
				break;
			} case 6:{
        		pertence_especie_raca(&inicio);
				break;
			} case 7: {
        		pertence_especie_raca_sexo(&inicio);
				break;
			} case 8:{
        		adotados(&inicio);		
				break;
			} case 9:{
            	cout<<"\nQuantidade de animais no sistema: "<<contanimal;
        		break;
      		} case 10: {
            	contagem_especie (inicio);
        		break;
      		} case 11: {
          		listagem(inicio);
        		break;
      		}
		}
	}while (opcao!=0);
	return (1);
}

void inserir(struct pet **inicio){
    system("clear");
  	FILE* arquivo;
  	pet *aux;
  	arquivo = fopen ("arquivo.txt", "a");
	aux=(pet *) malloc (sizeof(pet));

	time_t inicial, ultima;
	struct tm data;
  	struct tm dataUltima;
  	inicial = time(NULL);
    ultima = time(NULL);
  	data = *localtime(&inicial);
  	dataUltima = *localtime(&ultima);
  	
  	if (arquivo == NULL){
    	cout<<"\n\nErro na abertura do arquivo!";
  	} else {
	  	if (aux!=NULL){
    		cout<<"\n\nCadastro de novo Animal";
    		cout<<"\n--------------------------------------------------------";
		  	cout<<"\nInsira o código: ";
		  	cin>>aux->codigo;
    		cout<<"\nInsira o nome: ";
    		cin>>aux->nome;
    		cout<<"\n\n Lista de espécies no sistema";
    		cout<<"\n--------------------------------------------------------";
    		cout<<"\n Informação        Insira";
    		cout<<"\n Cachorro            1";
    		cout<<"\n Gatos               2";
    		cout<<"\n Furão               3";
    		cout<<"\n Chinchila           4";
    		cout<<"\n Hamster             5";
    		cout<<"\n Coelho              6";
    		cout<<"\n\nInsira o número correspondente da espécie: ";
		  	cin>>aux->especie;
    		if(aux->especie==1){
      			contCachorro++;
    		} else if (aux->especie==2){
      			contGato++;
    		} else if (aux->especie==3){
      			contFurao++;
    		} else if (aux->especie==4){
      			contChinchila++;
    		} else if (aux->especie==5){
      			contHamster++;
    		} else if (aux->especie==6){
      			contCoelho++;
    		} else {
      			cout<<"\n\nNúmero digitado inválido.";
    		}
    		cout<<"\nInsira a raça: ";
		  	cin>>aux->raca;
    		cout<<"\nInsira o sexo: ";
		  	cin>>aux->sexo;
    		cout<<"\nInsira a idade: ";
		  	cin>>aux->idade;
    		cout<<"\nInsira as descrição: ";
		  	cin>>aux->descricao;
        	cout<<"\n\nLista de status do animal";
    		cout<<"\n--------------------------------------------------------";
        	cout<<"\n Informação        Insira";
    		cout<<"\n Adotado            1";
    		cout<<"\n Para adoção        2";
        	cout<<"\n\nInsira o número correspondente do status: ";
		  	cin>>aux->status;
      		
		  	aux->prox=(*inicio);
		  	(*inicio)=aux;
        
    		contanimal++;

      		fprintf(arquivo, "\n Código: %d\n", aux->codigo);
      		fprintf(arquivo, " Nome do animal: %s\n", aux->nome);
      		fprintf(arquivo, " Número correspondente da espécie: %d \n", aux->especie);
      		fprintf(arquivo, " Raça: %s\n", aux->raca);
      		fprintf(arquivo, " Idade: %d\n", aux->idade);
      		fprintf(arquivo, " Descrição: %s \n", aux->descricao);
          	fprintf(arquivo, " Status: %d", aux->status);
          	fprintf(arquivo, "\n Inserção feita em: %d/%d/%d ás %d:%d",data.tm_mday,data.tm_mon+1,data.tm_year+1900,data.tm_hour-3,data.tm_min);
          	fprintf(arquivo, "\n Ultima alteração feita em: %d/%d/%d ás %d:%d \n-----------------------------------------------",dataUltima.tm_mday,dataUltima.tm_mon+1,dataUltima.tm_year+1900,dataUltima.tm_hour-3,dataUltima.tm_min);
          
      		system("clear");
          	cout<<"\nInserção feita em: "<<data.tm_mday<<"/"<<data.tm_mon+1<<"/"<<data.tm_year+1900<<" ás "<<data.tm_hour-3<<":"<<data.tm_min;
      		cout<<"\n\nDados gravados com sucesso!\n";
    	}
	}fclose(arquivo);
}

void remover (struct pet **inicio){
	system("clear");
	int cod_remove;
	pet *aux, *aux2;
	aux=*inicio;
	aux2=NULL;
	cout<<"\nDigite o código do animal que deseja remover: ";
	cin>>cod_remove;
	if ((aux!= NULL)&&(aux->codigo == cod_remove)){
		(*inicio)=aux->prox;
		free(aux);
	} while ((aux != NULL)&&(aux->codigo != cod_remove)){
		aux2=aux;
		aux=aux->prox;
    	contanimal--;
	} if (aux==NULL){
		cout<<"\nNão se encontra no sistema!\n";
	}else{
		aux2->prox = aux->prox;
		free(aux);
	}
}

void alterar (struct pet **inicio){
  	time_t ultima;
	struct tm dataUltima;
  	ultima = time(NULL);
  	dataUltima = *localtime(&ultima);

	system("clear");
	pet *aux;
	aux=(*inicio);
	int valor_pesquisa;
	char inserir;
	cout<<"\n\nAlterar informações\n";
	cout<<"\nInsira o código do animal que deseja editar informações: ";
	cin>>valor_pesquisa;
	if (aux->codigo == valor_pesquisa){
    	cout<<"\n\nInformações do animal:";
        cout<<"\nCódigo: "<<aux->codigo;
        cout<<"\nNome: "<<aux->nome;
        cout<<"\nEspécie: "<<aux->especie;
        cout<<"\nRaça: "<<aux->raca;
        cout<<"\nSexo: "<<aux->sexo;
        cout<<"\nIdade: "<<aux->idade;
        cout<<"\nDescrição: "<<aux->descricao;
        cout<<"\n\nInformação        Insira";
        cout<<"\nCódigo              A";
        cout<<"\nNome                B";
        cout<<"\nEspécie             C";
        cout<<"\nRaça                D";
        cout<<"\nSexo                E";
        cout<<"\nIdade               F";
        cout<<"\nDescrição           G";
        cout<<"\nStatus              H";
        
        cout<<"\nQual informação deseja editar?\n";
        cin>>inserir;
        inserir = toupper(inserir);
        switch (inserir){
        	case 'A':{
            	cout<<"\n\nEntre com um outro código: ";
            	cin>>aux->codigo;
              	system("clear");
            	break;
          	} case 'B':{
            	cout<<"\n\nEntre com um outro nome: ";
            	cin>>aux->nome;
              	system("clear");
            	break;
          	}case 'C':{
            	cout<<"\n\nEntre com um outra espécie: ";
            	cin>>aux->especie;
              	system("clear");
            	break;
          	}case 'D':{
            	cout<<"\n\nEntre com um outra raça: ";
            	cin>>aux->raca;
              	system("clear");
            	break;
          	}case 'E':{
            	cout<<"\n\nEntre com um outro sexo: ";
            	cin>>aux->sexo;
              	system("clear");
            	break;
          	}case 'F':{
            	cout<<"\n\nEntre com um outra idade: ";
            	cin>>aux->idade;
              	system("clear");
            	break;
         	}case 'G':{
            	cout<<"\n\nEntre com um outra descrição: ";
            	cin>>aux->descricao;
              	system("clear");
            	break;
          }case 'H':{
            	cout<<"\n\nEntre com um outro status: ";
            	cin>>aux->status;
              	system("clear");
            	break;
          	} default:{
              	system("clear");
          		cout<<"\n\nLetra inserida não pertence ao sistema.";
          		break;
          	}
        }
        cout<<"\nAlteração feita em: "<<dataUltima.tm_mday<<"/"<<dataUltima.tm_mon+1<<"/"<<dataUltima.tm_year+1900<<" ás "<<dataUltima.tm_hour-3<<":"<<dataUltima.tm_min<<"\n";
  	}
  	if (aux==NULL){
		cout<<"\nNão se encontra no sistema!\n";
  	} else {
    	aux=aux->prox;
  	}
}

void pertence_nome (struct pet **inicio){
  	pet *aux;
	system("clear");
  	if ((*inicio)->prox==NULL){
		cout<<"\nLista vazia!\n";
	}
    char pesquisa_nome [32];
    cout<<"Digite o nome do animal que deseja buscar: ";
    cin>>pesquisa_nome;
    aux = (*inicio)->prox;

    while (aux != NULL){
      	if(strcmp(aux->nome, pesquisa_nome)==0){
        	cout<<"\n\nCódigo: "<<aux->codigo;
        	cout<<"\nNome: "<<aux->nome;
        	cout<<"\nEspécie: "<<aux->especie;
        	cout<<"\nRaça: "<<aux->raca;
        	cout<<"\nSexo: "<<aux->sexo;
        	cout<<"\nIdade: "<<aux->idade;
        	cout<<"\nDescrição: "<<aux->descricao;
          cout<<"\nStatus: "<<aux->status;
      	} else{
        	cout<<"\n\nNão se encontra no sistema!\n";
      	}
        aux=aux->prox;
    }
}

void pertence_especie (struct pet **inicio){
  	pet *aux;
	system("clear");
  	if ((*inicio)->prox==NULL){
		cout<<"\nNão se encontra no sistema!\n";
	}
    int pesquisa_especie;
    cout<<"Digite a espécie do animal que deseja buscar: ";
    cin>>pesquisa_especie;
    aux = (*inicio)->prox;
    while (aux != NULL){
      	if(aux->especie==pesquisa_especie){
        	cout<<"\n\n\nCódigo: "<<aux->codigo;
        	cout<<"\nNome: "<<aux->nome;
        	cout<<"\nEspécie: "<<aux->especie;
        	cout<<"\nRaça: "<<aux->raca;
        	cout<<"\nSexo: "<<aux->sexo;
        	cout<<"\nIdade: "<<aux->idade;
        	cout<<"\nDescrição: "<<aux->descricao;
          cout<<"\nStatus: "<<aux->status;
      	} else{
        	cout<<"\n\nNão se encontra no sistema!\n";
      	}
        aux=aux->prox;
    }
}

void pertence_especie_raca (struct pet **inicio){
  	pet *aux;
	system("clear");
  	if ((*inicio)->prox==NULL){
		cout<<"\nNão se encontra no sistema!\n";
	}
    char pesquisa_raca[30];
    int pesquisa_especie;
    cout<<"Digite a espécie do animal que deseja buscar: ";
    cin>>pesquisa_especie;
    cout<<"Digite a raça do animal que deseja buscar: ";
    cin>>pesquisa_raca;
    aux = (*inicio)->prox;

    while (aux != NULL){
      	if((aux->especie==pesquisa_especie)&&(strcmp(aux->raca, pesquisa_raca)==0)){
        	cout<<"\n\n\nCódigo: "<<aux->codigo;
        	cout<<"\nNome: "<<aux->nome;
        	cout<<"\nEspécie: "<<aux->especie;
        	cout<<"\nRaça: "<<aux->raca;
        	cout<<"\nSexo: "<<aux->sexo;
        	cout<<"\nIdade: "<<aux->idade;
        	cout<<"\nDescrição: "<<aux->descricao;
          cout<<"\nStatus: "<<aux->status;
      	}else {
        	cout<<"\n\nNão se encontra no sistema!\n";
      	}
        aux=aux->prox;
    }
}

void pertence_especie_raca_sexo (struct pet **inicio){
  	pet *aux;
	system("clear");
  	if ((*inicio)->prox==NULL){
		cout<<"\nNão se encontra no sistema!\n";
	}
    char pesquisa_raca[30], pesquisa_sexo[2];
    int pesquisa_especie;

    cout<<"Digite a espécie do animal que deseja buscar: ";
    cin>>pesquisa_especie;
    cout<<"Digite a raça do animal que deseja buscar: ";
    cin>>pesquisa_raca;
    cout<<"Digite o sexo do animal que deseja buscar: ";
    cin>>pesquisa_sexo;
    aux = (*inicio)->prox;
    while (aux != NULL){
      	if((aux->especie==pesquisa_especie)&&(strcmp(aux->raca, pesquisa_raca)==0)&&(strcmp(aux->sexo, pesquisa_sexo)==0)){
        	cout<<"\n\n\nCódigo: "<<aux->codigo;
        	cout<<"\nNome: "<<aux->nome;
        	cout<<"\nEspécie: "<<aux->especie;
        	cout<<"\nRaça: "<<aux->raca;
        	cout<<"\nSexo: "<<aux->sexo;
        	cout<<"\nIdade: "<<aux->idade;
        	cout<<"\nDescrição: "<<aux->descricao;
          cout<<"\nStatus: "<<aux->status;
      	}else {
        	cout<<"\n\nNão se encontra no sistema!\n";
      	}
        aux=aux->prox;
    }
}

void contagem_especie (struct pet *inicio){
  	system("clear");
  	int especie_pesquisa;
  	cout<<"\n\n Lista de espécies no sistema";
  	cout<<"\n--------------------------------------------------------";
  	cout<<"\n Informação        Insira";
  	cout<<"\n Cachorro            1";
  	cout<<"\n Gatos               2";
  	cout<<"\n Furão               3";
  	cout<<"\n Chinchila           4";
  	cout<<"\n Hamster             5";
  	cout<<"\n Coelho              6";
  	cout<<"\n\nInsira a espécie que deseja visualizar: ";
  	cin>>especie_pesquisa;

    switch (especie_pesquisa){
      	case 1:{
        	cout<<"\nCachorros no sistema: "<<contCachorro;
        	break;
      	} case 2:{
        	cout<<"\nGatos no sistema: "<<contGato;
        	break;
      	} case 3:{
        	cout<<"\nFurões no sistema: "<<contFurao;
        	break;
      	} case 4:{
        	cout<<"\nChinchila no sistema: "<<contChinchila;
        	break;
      	} case 5:{
        	cout<<"\nHamsters no sistema: "<<contHamster;
        	break;
      	} case 6:{
        	cout<<"\nCoelhos no sistema: "<<contCoelho;
        	break;
      	} default:{
        	cout<<"\nNúmero inserido inválido.";
        	break;
      	}
    }
}
void listagem (struct pet *inicio){
  system("clear");
  FILE* arquivo;
  arquivo = fopen ("arquivo.txt", "r");
  cout<<"\nListagem dos animais cadastrados: ";
	while (inicio!=NULL){
    fread(&inicio, sizeof(pet), 200, arquivo);
    cout<<"\nCódigo: "<<inicio->codigo;
    cout<<"\nNome: "<<inicio->nome;
    cout<<"\nEspécie: "<<inicio->especie;
    cout<<"\nRaça: "<<inicio->raca;
    cout<<"\nSexo: "<<inicio->sexo;
    cout<<"\nIdade: "<<inicio->idade;
    cout<<"\nDescrição: "<<inicio->descricao;
    cout<<"\nStatus: "<<inicio->status;
    cout<<"\n--------------------------------------------------------\n";
		inicio=inicio->prox;
	}
  fclose(arquivo);
}

void adotados (struct pet **inicio){
  	pet *aux;
	system("clear");
  	if ((*inicio)->prox==NULL){
		cout<<"\nLista vazia!\n";
	}
    aux = (*inicio)->prox;
    while (aux != NULL){
      	if(aux->status==1){
        	cout<<"\n\nCódigo: "<<aux->codigo;
        	cout<<"\nNome: "<<aux->nome;
        	cout<<"\nEspécie: "<<aux->especie;
        	cout<<"\nRaça: "<<aux->raca;
        	cout<<"\nSexo: "<<aux->sexo;
        	cout<<"\nIdade: "<<aux->idade;
        	cout<<"\nDescrição: "<<aux->descricao;
          	cout<<"\nStatus: "<<aux->status;
      	} else if (aux->status!=1){
        	cout<<"\n\nNão se encontra no sistema!\n";
      	}
        aux=aux->prox;
    }
}
