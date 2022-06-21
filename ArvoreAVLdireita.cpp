#include <iostream>

using namespace std;

struct no {
  int info;
  struct no * esq, * dir;
 }; 
 typedef struct no * noPtr;
 
 
 
 /*Explicação geral do código:
 É um programa que o usuário insere um número após o outro e ele vai balanceando sozinho. Foi realizado uma função para verificar a posição de cada numero e quem está à sua esquerda e direita.
 A função remover retira do programa o menor número do lado direito. 
 A função menu2 você pode escolher entre duas opções: Listar Infixo e ListarEspecial, que mostra a posição de cada numero e quem está à sua esquerda e direita.
 Essa função é crucial pois mostra que está sendo realizado uma arvore AVL. 
 
 
 */

int menu();
int menu2();
void inserir(noPtr *, int);
void remover(noPtr *, int);
bool buscar(noPtr, int);
void maior(noPtr p, noPtr *aux);
void listarEmOrdem(noPtr);
void listarPreOrdem(noPtr);
void listarPosOrdem(noPtr);
bool arvoreVazia(noPtr);
void listarzero(noPtr);
int menorElementoDireita(noPtr);
int menorEsquerda(noPtr);
void listarEspecial (noPtr);


int main() {
  int op1, op2, x; bool achei; noPtr raiz = NULL;
  do
	{
  	op1 = menu();
  	switch(op1) {
	  	case 1:
	  		cout << "\nDigite o elemento que voce deseja inserir: ";
	   	 	cin >> x;
	    	inserir(&raiz, x); break;
	  	case 2:
	    	if (raiz == NULL)
	    		cout << "Lista vazia!";
	    	else{
	    		if(raiz->dir != NULL){
		    		int menorDir = menorElementoDireita(raiz);
		    		cout<<"\nElemento Removido foi o:  "<<menorDir<<endl;
		    		remover (&raiz, menorDir);
		    	}
		    	else{
		    		cout<<"Nenhum elemento a direita";
		    	}
	    	}
			break;
	  	case 3: 
	  		op2 = menu2();
	    	if (op2 == 1) listarEmOrdem(raiz);
	    	if (op2 == 2) listarEspecial(raiz);
	    	break;
	} 
  }while(op1 != 4);
  
  return 0;
}


int menu() {  // Complexidade O(1).
    int opcao;
    cout << "\n\n\n---- Menu Principal ----\n\n"
        << "\n1.Inserir no na arvore"
        << "\n2.Remover no na arvore"
         << "\n3.Listar todos os nos da arvore"
         << "\n4.Sair"
         << "\nDigite uma opcao: ";
    cin >> opcao;
 return opcao;
}

//Criação de um 2 função menu por motivos de que eu quis, para ver se a árvore AVL funciona, criar uma Lista Especial que mostra as posições dos numeros e seus nós filhos.
int menu2() { // Complexidade O(1)
int opcao;
cout << "\n\nTipos de listagem:"
 << "\n\t1.Em Ordem" 
 << "\n\t2.Listar Especial" <<endl;
cin >> opcao;
return opcao;
}

int max(int a, int b){ // Complexidade: O (1) pois é a mais simples. Apenas 1 troca.
    if (a > b)
    	return a;
    	else
    	return b;
}

int altura(noPtr p){  // Complexidade: O(n) pois é variável em relação a n +  Complexidade de max: O(1) = O (n + 1). Entretanto, esse "+1" é irrelevante, portanto, é melhor O(n).
    if (p == NULL)
        return 0;
    return max(altura(p->dir),altura(p->esq))+1;
}

void rodarEsquerda(noPtr *p){ //Complexidade: O(3) pois da 3 trocas, logo, 3.

	noPtr y = (*p)->dir; 
	noPtr m = y->esq; 
	
	y->esq = *p; 
	(*p)->dir = m; 

	*p = y;

} 
	
void rodarDireita(noPtr *p){  // Complexidade: O(3) pois da 3 trocas.

	noPtr x = (*p)->esq; 
	noPtr m = x->dir; 

	
	x->dir = *p; 
	(*p)->esq = m; 

	*p = x;

} 

int get_grau(noPtr N){  // Complexidade: O(n), pois é variável em relação a n.

    if (N == NULL){
        return 0;  
    }
    return altura(N->esq) - altura(N->dir);  

} 

void balancear(noPtr * p){ // Complexidade: O(3n) + 4,5 = O (3n + 4,5). // Entretanto, como essa conta não é, de fato, decisiva, o melhor é usar-se da Complexidade: O (n).
	
	int grau = get_grau(*p);

	int grauFe = get_grau((*p)->esq);
	int grauFd = get_grau((*p)->dir);

	// Caso Esquerda Esquerda
	if (grau == 2 && (grauFe == 1 || grauFe == 0)) // Complexidade: 3
		rodarDireita(&*p); 

	// Caso Direita Direita 
	if (grau == -2 && (grauFd == -1 || grauFd == 0)) // Complexidade: 3
		rodarEsquerda(&*p); 

	// Caso Esquerda Direita 
	if (grau == 2 && grauFe == -1){ // Complexidade: 3.2 = 6
		rodarEsquerda(&((*p)->esq)); 
		rodarDireita(&*p); 
	} 

	// Caso Direita Esquerda 
	if (grau == -2 && grauFd == 1){  // Complexidade: 3.2 = 6
		rodarDireita(&((*p)->dir)); 
		rodarEsquerda(&*p); 
	} 

}

void inserir(noPtr * p, int x) { //Complexidade: O [(log n) + complexidade balanceada: (3n) + (18/4)] = O [(log n + 3n + 4,5)] // Essa conta não é decisiva, para tal, o melhor é O(Log n + n)
	if (arvoreVazia(*p)) {
  		*p = new no;
  		(*p)->info = x;
  		(*p)->esq = NULL;
  		(*p)->dir = NULL;
 	}else{
 		if (x < ((*p)->info)){
   			inserir(&((*p)->esq), x);
 		}
   		else{
   		 	if(x >((*p)->info)){
   				inserir(&((*p)->dir), x);
   		 	}
   			else{
			   cout << "Numeros iguais";
   			}
		}
		balancear(&*p);
	}
}

bool arvoreVazia(noPtr p){ // Complexidade: O (1)
	if (p != NULL)
		return false;
	else
 		return true;
}

/*
bool buscar(noPtr p, int x){ // Complexidade: O(n)
	bool achei = false;
	if(arvoreVazia(p))
		cout << "\nArvore vazia " << endl;
	else{
  		if (x == (p-> info)){
   			cout << "\nO elemento: " << p->info << " foi encontrado na arvore: \n";
   			achei = true;
  		}else
   			if (x < (p->info))
   				buscar((p->esq), x);
  			else
   				buscar((p->dir), x);
	}
	return achei; 
}
*/
int menorElementoDireita(noPtr p){ // Complexidade: O(1)

	return menorEsquerda (p->dir);
	
}
int menorEsquerda(noPtr p){  // Complexidade: O(3)

	if(p->esq != NULL){
		return menorEsquerda (p->esq);
	}
	else{
		return p->info;
	}
	
}
// função para saber os valores da direita / esquerda 
void listarEspecial(noPtr p){  // Complexidade: O(2)
	cout<<"__________________________________"<<endl;
	if (p !=NULL){
		cout <<"Info: " << p->info << endl;
		if (p->esq != NULL){
			cout <<"Esq: " <<p->esq->info<< endl;
		}
		else{
			cout <<"Esq: NULL"<< endl;
		}
		if (p->dir !=NULL){
			cout <<"Dir: " <<p->dir->info<< endl;
		}
		else{
			cout <<"Dir: NULL"<< endl;
		}
		listarEspecial (p->esq);
		listarEspecial (p->dir);
	}
}

void remover(noPtr *p, int x){ //Complexidade: O (Log n) + Complexidade Baleanceada: O(3n + 4,5) + Complexidade maior // Novamente, caso de Complexidade calculada. O melhor é usar Complexidade O (n).
	noPtr aux;

	if(!arvoreVazia(*p)){
   		if (x == ((*p)->info)){
	    	aux = *p;
   			if (((*p)->esq) == NULL){
	   			*p = (*p)->dir;
   			}
   			else{
   		 		if (((*p)->dir) == NULL){
	    	 		*p = (*p)->esq;
   		 		}
    			else {
	    	 		maior((*p)->esq, &aux);
	    	 		cout<<"AUX: ----{"<<aux->info<<endl;
    	 			(*p)->info = aux->info;
    			}
    		}
			delete(aux);
 			cout << "\nO elemento foi removido\n";
  		}
  		else{
  			remover(&((*p)->esq), x); 
	   		remover(&((*p)->dir), x);
			
			balancear(&*p);
		}
	}	
}


void maior(noPtr p, noPtr *aux){  // Complexidade (1)  pois duas trocas.
	noPtr t;
	t = p;
	if ((t->dir) == NULL) {
   		*aux = t;
	}
	else
		return maior(t->dir, &(*aux));
}

void listarEmOrdem(noPtr p) { // Complexidade (1).
 if (!arvoreVazia(p)) {
 listarEmOrdem(p->esq);
 cout << "\t"<< p->info;
 listarEmOrdem(p->dir);
 }
}

/*void listarPosOrdem(noPtr p) {
 if (!arvoreVazia(p)) {
 listarPosOrdem(p->esq);
 listarPosOrdem(p->dir);
 cout << "\t" << p->info;
 }
}

void listarPreOrdem(noPtr p) {
 if (!arvoreVazia(p)) {
 cout << "\t" << p->info;
 listarPreOrdem(p->esq);
 listarPreOrdem(p->dir);
 }
}

void listarzero(noPtr aux) {
  if (aux != NULL){
    if (aux -> esq == NULL && aux -> dir == NULL)
      cout << aux -> info << "\t";
    else{
      listarzero(aux -> esq);
      listarzero(aux -> dir);
    }
  }
}

*/

