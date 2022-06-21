#include <iostream>
using namespace std;


typedef struct Nos
  {
     int info;
     struct Nos *prox;
  }NO;


NO *inicio=NULL;
NO *calda=NULL;

void CriaLista()
{
   inicio = NULL; //Sim, fiz uma redundância afim de nao esquecer JAMAIS.
}

//Insere no começudo
int Insere()
{
   int dado;
   cout << "Digite o dado a ser inserido";
   cin >> dado;
   NO *p;
   p = new Nos;
   // isso é em C! p =  (NO *) malloc(sizeof(NO));
   if (p==NULL)
   {
     return 0;
   }
   p->info = dado;
   p->prox = NULL;
   if (inicio==NULL)
      inicio = p;
   else {
	  p->prox = inicio;
	  inicio  = p;
	}
	cout<<&p<<" Inserido com sucesso na memoria ";
   return 1;
}

// void insere(){
//	NO *p;
//	int x;
//	// p = (NO) malloc(sizeof(struct nos));
//	printf ("Digite o valor do elemento");
//	scanf ("%d", x);	
//	p->info =x;
//	p->prox=inicio;
//	inicio=p;
// }


int RemoveDado()
{
  NO *ptr, *antes;
  int dado;
  cout << "Digite o dado a ser removido";
  cin >> dado;
  if (inicio==NULL){
  	return 0;
  }
  else
  {   
      ptr = inicio;
      antes = inicio;
      while (ptr !=NULL)
      {
	 if (ptr->info == dado) 
	 {
	    if (ptr == inicio) 
	    {
	       inicio = inicio->prox;
	       delete(ptr);
	       return 1; // removeu!
	    }
	    else  
	    {
	      antes->prox = ptr->prox;  
	      delete(ptr);                
	      return 1;   // remove!
	    }
	 }
	 else 
	 {
	    antes = ptr;
	    ptr = ptr->prox;
	 }
      }
      cout << "Elemento não achado!";
      return 0; // Nao achou!
  }
}



			
//crescente

void crescente (){
	NO *atual = inicio, *index = NULL;
	int temp;
	if(inicio== NULL) {  
            return;  
        }  
        else {  
            while(atual!= NULL) {  
                index = atual->prox;  
                  
                while(index != NULL) {  
                    
                    if(atual->info > index->info) {  
                        temp = atual->info;  
                        atual->info = index->info;  
                        index->info = temp;  
                    }  
                    index = index->prox;  
                }  
                atual = atual->prox;  
            }      
        }  
    }  

			
// Decrescente
void decrescente (){
	NO *atual = inicio, *index = NULL;
	int temp;
		while (atual !=NULL){
			 index = atual->prox;  
                while(index != NULL) {  
                    
                    if(atual->info <= index->info) {  
                        temp = atual->info;  
                        atual->info = index->info;  
                        index->info = temp;  
                    }  
                    index = index->prox;  
                }  
                atual = atual->prox;  
            }      
        }  
			




int main(){
	{
	
	int op, dado, i, tamanho;
	do {
		cout << "Digite o tamanho do que deseja";
			cin >> tamanho;
		for (i =0; i< tamanho; i++){	
		cout <<"Digite o q vc quer";
		cin >>op;
		

		
		switch(op)
			{
			case 1:
			Insere(); break;
			case 2:
			RemoveDado(); 
			break;
			case 3: 
			crescente();
			break;
			case 4:
			decrescente();
			break;
			}		}}
 		while (op !=0);
			
	return 0;
	
}
}
