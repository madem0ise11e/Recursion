#include <stdio.h>
#define MAXLEN 20

int trovaMassimoR(int A[], int n);
void riempiArray(int A[], int n);
void stampaArray(int A[], int n);
int trovaElemento(int A[], int k, int n);

int main(){
  int A[MAXLEN];
  int n, m, k, i;
  printf("Dimmi quanti elementi vuoi inserire? ");
  scanf("%d", &n);
  riempiArray(A,n);
  stampaArray(A,n);
  m = trovaMassimoR(A,n);
  printf("\nIl massimo e': %d\n", m);
  printf("\nDammi elemento da cercare: \n");
  scanf("%d", &k);
  i = trovaElemento(A,k,n);
  if(i>=0) printf("Elemento %d trovato in posizione di indice %d.\n",k,i);
  else printf("L'elemento non e' presente.");
}

int trovaElemento(int A[], int k, int n){
  int sol=-1;
  if(n>0){ // CASO BASE IMPLICITO
  if(A[n-1] == k) sol=n-1;
  else sol=trovaElemento(A,k,n-1);
  }
  return sol;
}

int trovaMassimoR(int A[], int n){
  int max;
  if(n==1) {//CASO BASE
  max=A[0];
  //printf("\nP(%d) problema di dimensione n=%d CASO BASE\n", n,n);
  } else {
//  printf("P(%d) problema di dimensione n=%d CASO RICORSIVO\n", n,n);
//  printf("Faccio una chiamata ricorsiva \n");
  max=trovaMassimoR(A,n-1); //Tolgo l'ultimo elemento e assumo di avere la soluzione
                              //per lo stesso problema ma con n-1 elementi
//  printf("FINE una chiamata ricorsiva con n=%d\n", n);
  if(A[n-1] > max) max = A[n-1]; //il passo di combinazione tra l'elemento che ho messo
                                //da parte (in questo caso l'ultimo) e la soluzione del
                                //problema con n-1 elementi
                                //il punto più delicato nella struttura di un algoritmo ricorsivo
//  printf("\nCOMBINO la soluzione del problema P(n=%d) con elemento A[n-1]=%d\n", n, A[n-1]);
//  printf("La soluzione del problema P(%d) e': %d\n",n,max);
//  stampaArray(A,n);
  }
  return max;
}

void riempiArray(int A[], int n){
  int i = 0;
  for(i=0; i<n; ++i){
  printf("Dammi l'elemento A[%d]=", i);
  scanf("%d", &A[i]);
  }
}

void stampaArray(int A[], int n){
  int i = 0;
  printf("\n Valori del Array di %d elementi:\n", n);
  for(i=0; i<n; ++i){
  printf("A[%d]=%d\n", i,A[i]);
  }
}
