#include <iostream>
using namespace std;


struct no {
	int info;
	struct no * prox;
};

typedef struct no * noPtr;
struct no *primeiro;
struct no *ultimo;



//
void inserirNo(){
	noPtr novo= new no();
	cout<< "Insira o numero para inserir: ";
	cin >> novo->info; 
	
	if(primeiro==NULL){ //Quando está vazia;
		primeiro = novo;
		primeiro->prox = primeiro;
		ultimo = primeiro;
	}else{
		ultimo->prox = novo;
		novo->prox = primeiro;
		ultimo = novo;
	}
	cout<<endl<<"\tNo "<<novo->info<<" adicionado"<<endl<<endl;
	cout <<endl<< "\tEndereco ("<< novo << ")" <<endl<<endl;
}



void removerNo(){

	int excluir;
	cout<< "Insira o numero para remover: "; 
	cin >> excluir; 

	if (primeiro != NULL){ //Só existe caso info tenha 1 membro ao menos.

		noPtr aux = primeiro, ant = ultimo;

		while(aux != ultimo && aux->info != excluir){
	        ant = aux;
	        aux = aux->prox;
		}

		if (aux->info == excluir){

	       	if(primeiro == ultimo){

	       		primeiro = NULL;
	       		ultimo = NULL;
	       		delete(aux);

	       	}
	       	else{

	       		ant->prox = aux->prox;
	       	
		       	if(aux == ultimo){
		       	    ultimo = ant;
		        }
			    if(aux == primeiro){
		            primeiro = ant->prox;
		      	}

		       	aux->prox = NULL;
			    delete(aux);

	       	}
	       	cout<< "\n\tNo "<<excluir<<" removido"<<endl<<endl;
		}
		else{
		    cout<<"elemento nao encontrado"<<endl;
		}
	}
	else{
       cout<< "elemento nao encontrado"<<endl;
	}
	
}

void listar(){
	
	if(primeiro == NULL){
		cout<<"--[NULL] "<<endl;
	}
	else{

		noPtr aux = primeiro;

		cout<< aux->info;
		cout<<"\t("<<aux<<")";
		cout<<"\t->\t";

		aux = aux->prox;

		while(aux!= ultimo){
	        cout<<aux->info;
	        cout<<"\t->\t";
	        aux = aux->prox;
		}

		cout<< aux->info;
		cout<<"\t("<< aux<<")"<<endl;

	}
	
}


main (){
	int opcao_lista = 0;
	do 
	{
	cout <<"--------------Comandos-------------";
	cout <<"\n 1-Inserir" ;
	cout <<"\n 2-Remover";
	cout <<"\n 3-Listar";
	cout <<"\n 4-Sair do Programa";
	cout <<"\nEscolha uma opcao: ";
	cin >> opcao_lista;
	switch (opcao_lista){
		case 1: 
			
			inserirNo();
			break;
		case 2: 
			
			removerNo();
			break;
		case 3: 
			cout << "\nMostrando a lista abaixo: \n";
			listar();
			break;
		case 4:
			cout << "\nSaindo do programa";
			break;
		default:
			cout << "\nOpção Invalida";
		}
		
		
		}
		while (opcao_lista !=4);
		
	
	return 0;
	
}
