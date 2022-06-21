#include <iostream>
#include <bits/stdc++.h> 

using namespace std;
struct no {
  int info;
  struct no * esq, * dir;
 }; 
 typedef struct no * noPtr;
 

 
 //Estrutura AVL
//struct Node
//{
  //  int chave;
    //struct Node *esquerda;
    //struct Node *direita;
    //int tam;
//}; 
//typedef struct Node * NodePtr;

//PRECISO FAZER 4 ROTAÇÕES PARA CODIGO COMPLETO
// POR SER DIREITA, FOCAR EM DIREITA;
// criar uma função Rotação Direita Direita, Direita Esquerda, Esquerda Esquerda, Direita Direita.


int menu();
int menu2();
void inserir(noPtr *, int);
void remover(noPtr *, int);
bool buscar(noPtr, int);
noPtr maior(noPtr *);
void listarEmOrdem(noPtr);
void listarPreOrdem(noPtr);
void listarPosOrdem(noPtr);
bool arvoreVazia(noPtr);
void listarzero(noPtr);
int max (int,int);
void rodarEsquerda(noPtr *); 
void rodarDireita(noPtr *); 
int menorElementoDireita(noPtr);
int menorEsquerda(noPtr);
void listarEspecial (noPtr);


int main() {
  int op1, op2, x; bool achei; noPtr raiz = NULL;
  do
	{
  	op1 = menu();
  	switch(op1) {
  	case 1: cout << "\nDigite o elemento que voce deseja inserir: ";
   	 		cin >> x;
    		inserir(&raiz, x); break;
  	case 2: cout << "\nElemento Removido foi o:  ";
    		/*if (raiz == NULL)
    		cout << "Lista vazia!";
    		else */
			remover (&raiz,x); break;
  	case 3: op2 = menu2();
    	if (op2 == 1) listarEmOrdem(raiz);
    	if (op2 == 2) listarPreOrdem(raiz);
    	if (op2 == 3) listarPosOrdem(raiz); break;
 	case 4: cout << "\nDigite o elemento que voce deseja consultar: ";
    		cin >> x;
    		achei = buscar(raiz, x);
  			if (!achei)
    		cout << "Elemento nao encontrado" << endl; break;
  	case 5:
    listarzero(raiz);
  } 
  } 
  while(op1 != 6);
  return 0;}

int menu() {
    int opcao;
    cout << "\n\n\n---- Menu Principal ----\n\n"
        << "\n1.Inserir no na arvore"
        << "\n2.Remover no na arvore"
         << "\n3.Listar todos os nos da arvore"
         << "\n4.Buscar no"
         << "\n5.Listar nÃ³s com grau 0"
         << "\n6.Sair"
         << "\nDigite uma opcao: ";
    cin >> opcao;
 return opcao;
}

int menu2() {
int opcao;
cout << "\n\nTipos de listagem:"
 << "\n\t1.Em Ordem"
 << "\n\t2.Pre Ordem"
 << "\n\t3.Pos Ordem"
 << "\n\nEscolha o tipo de listagem: ";
cin >> opcao;
return opcao;
}

int max(int a, int b){
    if (a > b)
    	return a;
    	else
    	return b;
}

int altura(struct no * N){
    if (N == NULL)
        return 0;
    return max(altura(N->dir),altura(N->esq))+1;
}
/* int alturaNova(noPtr *p){
//	(*p)->altura = 1 - max(altura((*p)->esq), altura((*p)->dir));
	
	return (*p);
} */
//Rotação para a esquerda


void rodarEsquerda(noPtr *p) 
{ 
	noPtr y = (*p)->dir; 
	noPtr m = y->esq; 
	
	y->esq = *p; 
	(*p)->dir = m; 

} 
	
void rodarDireita(noPtr *p) 
{ 
	noPtr x = (*p)->esq; 
	noPtr m = x->dir; 

	//RROTACAO
	x->dir = *p; 
	(*p)->esq = m; 
	
//Rodando
} 


int balancear(noPtr N)  
{  
    if (N == NULL)  
        return 0;  
    return altura(N->esq) -
		   altura(N->dir);  
} 





void inserir(noPtr * p, int x) {
 if (arvoreVazia(*p)) {
  *p = new no;
  (*p)->info = x;
  (*p)->esq = NULL;
  (*p)->dir = NULL;
 } else {
   if (x < ((*p)->info))
   inserir(&((*p)->esq), x);
   else if (x >((*p)->info) )
   inserir(&((*p)->dir), x);
   else 
   cout << "Numeros iguais";
   // Precisa balancear e calcular a altura do nó.
   //
  // (*p)->altura = 1 + max(altura((*p)->esq), altura((*p)->dir));
   int balanceado = balancear(*p);
   //falta definir qnd tiver altura 1 / -1
   int alturaFe = balancear((*p)->esq);
 
   int alturaFd = balancear((*p)->dir);

	// Left Left Case 
	if (balanceado == 2 && alturaFe == 1 )// x < (*p)->esq->info/) 
		rodarDireita(&*p); 

	// Right Right Case 
	if (balanceado == -2 && alturaFd == -1) // (*p)->dir->info) 
		rodarEsquerda(&*p); 

	// Left Right Case 
	if (balanceado == 2 && alturaFe == -1)//x > (*p)->esq->info) 
	{ 
		rodarEsquerda(&((*p)->esq)); 
		rodarDireita(&*p); 
	} 

	// Right Left Case 
	if (balanceado == -2 && alturaFd == 1)// x < (*p)->dir->info) 
	{ 
		rodarDireita(&((*p)->dir)); 
		rodarEsquerda(&*p); 
	} 
   
   
   
  }
}

bool arvoreVazia(noPtr p)
{
 if (p !=NULL)
 return false;
 else
 return true;
}

bool buscar(noPtr p, int x)
{
bool achei = false;
 if(arvoreVazia(p))
  cout << "\nArvore vazia " << endl;
 else {
  if (x == (p-> info)) {
   cout << "\nO elemento: " << p->info << " foi encontrado na arvore: \n";
   achei = true;
  } else
   if (x < (p->info))
   buscar((p->esq), x);
  else
   buscar((p->dir), x);
} return achei; 
}

int menorElementoDireita(noPtr p)
{
	cout << p->info << endl;
	return menorEsquerda (p->dir);
	
}
int menorEsquerda(noPtr p)
{
	if(p->esq != NULL){
	cout <<p->info << endl;
	return menorEsquerda (p->esq);
}
	else
	return p->info;
	
}
void listarEspecial(noPtr p)
{
	if (p !=NULL){
	cout <<"End: "<< p << endl;
	cout << "Info: " << p->info << endl;
	cout <<"Esq: " <<p->esq << endl;
	cout << "Dir: " <<p->dir << endl;
	if (p->esq != NULL){
		listarEspecial (p->esq);
	}
	if (p->dir !=NULL){
		listarEspecial (p->dir);
	}

	}
	cout << "chegou no final  " <<endl;
}


void remover(noPtr *p, int x){
 noPtr aux;
 if (arvoreVazia(*p))
  	cout << "\nArvore vazia" << endl;
 else 
	{ 
   if (x == ((*p)->info))
    {
    	aux = *p;
   		if (((*p)->esq) == NULL)
   			*p = (*p)->dir;
   		else
   		 	if (((*p)->dir) == NULL)
     		*p = (*p)->esq;
    else {
    	 aux = maior(&((*p)->esq));
    	 (*p)->info = aux->info;
    }
   delete(aux);
   
   cout << "\nO elemento foi removido\n";
  } else {
  
   		if ((x < ((*p)->info)))
   			remover(&((*p)->esq), x);
   else
   		 remover(&((*p)->dir), x);
	int balanceado = balancear(*p);
   //falta definir qnd tiver altura 1 / -1
   int alturaFe = balancear((*p)->esq);
   int alturaFd = balancear((*p)->dir);

	// Left Left Case 
	if (balanceado == 2 && alturaFe == 1 )// x < (*p)->esq->info/) 
		rodarDireita(&*p); 

	// Right Right Case 
	if (balanceado == -2 && alturaFd == -1) // (*p)->dir->info) 
		rodarEsquerda(&*p); 

	// Left Right Case 
	if (balanceado == 2 && alturaFe == -1)//x > (*p)->esq->info) 
	{ 
		rodarEsquerda(&((*p)->esq)); 
		rodarDireita(&*p); 
	} 

	// Right Left Case 
	if (balanceado == -2 && alturaFd == 1)// x < (*p)->dir->info) 
	{ 
		rodarDireita(&((*p)->dir)); 
		rodarEsquerda(&*p); 
	} 
    }

	}

}
/*Node* deleteNode(Node* root, int key)  
{  
      
    // STEP 1: PERFORM STANDARD BST DELETE  
    if (root == NULL)  
        return root;  
  
    // If the key to be deleted is smaller  
    // than the root's key, then it lies 
    // in left subtree  
    if ( key < root->key )  
        root->left = deleteNode(root->left, key);  
  
    // If the key to be deleted is greater  
    // than the root's key, then it lies  
    // in right subtree  
    else if( key > root->key )  
        root->right = deleteNode(root->right, key);  
  
    // if key is same as root's key, then  
    // This is the node to be deleted  
    else
    {  
        // node with only one child or no child  
        if( (root->left == NULL) || 
            (root->right == NULL) )  
        {  
            Node *temp = root->left ?  
                         root->left :  
                         root->right;  
  
            // No child case  
            if (temp == NULL)  
            {  
                temp = root;  
                root = NULL;  
            }  
            else // One child case  
            *root = *temp; // Copy the contents of  
                           // the non-empty child  
            free(temp);  
        }  
        else
        {  
            // node with two children: Get the inorder  
            // successor (smallest in the right subtree)  
            Node* temp = minValueNode(root->right);  
  
            // Copy the inorder successor's  
            // data to this node  
            root->key = temp->key;  
  
            // Delete the inorder successor  
            root->right = deleteNode(root->right,  
                                     temp->key);  
        }  
    }  
  
    // If the tree had only one node 
    // then return  
    if (root == NULL)  
    return root;  
  
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE  
    root->height = 1 + max(height(root->left),  
                           height(root->right));  
  
    // STEP 3: GET THE BALANCE FACTOR OF  
    // THIS NODE (to check whether this  
    // node became unbalanced)  
    int balance = getBalance(root);  
  
    // If this node becomes unbalanced,  
    // then there are 4 cases  
  
    // Left Left Case  
    if (balance > 1 &&  
        getBalance(root->left) >= 0)  
        return rightRotate(root);  
  
    // Left Right Case  
    if (balance > 1 &&  
        getBalance(root->left) < 0)  
    {  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  
  
    // Right Right Case  
    if (balance < -1 &&  
        getBalance(root->right) <= 0)  
        return leftRotate(root);  
  
    // Right Left Case  
    if (balance < -1 &&  
        getBalance(root->right) > 0)  
    {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  
  
    return root;  
}  
*/






noPtr maior(noPtr *p) {
 noPtr t;
 t = *p;
 if ((t->dir) == NULL) {
    *p = (*p)->esq;
    return(t);
 }
 else
 return (maior(&((*p)->dir)));
}

void listarEmOrdem(noPtr p) {
 if (!arvoreVazia(p)) {
 listarEmOrdem(p->esq);
 cout << "\t" << p->info;
 listarEmOrdem(p->dir);
 }
}

void listarPosOrdem(noPtr p) {
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
