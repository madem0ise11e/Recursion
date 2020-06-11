#include <stdio.h>
#define MAXLEN 20
int trovaMassimoR(int A[], int n);
void riempiArray(int A[], int n);
void stampaArray(int A[], int n);
int main(){
  int A[MAXLEN];
  int n,m;
  printf("Dimmi quanti elementi vuoi inserire? ");
  scanf("%d", &n);
  riempiArray(A,n);
  stampaArray(A,n);
  m = trovaMassimoR(A,n);
  printf("\nIl massimo e': %d\n", m);
}

int trovaMassimoR(int A[], int n){
  int max;
  if(n==1) //CASO BASE
    max=A[0];
  else{
    max=trovaMassimoR(A,n-1); //Tolgo l'ultimo elemento e assumo di avere la soluzione
                              //per lo stesso problema ma con n-1 elementi
  }
  return 0;
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
  printf("\n Valori del Arrau di %d elementi:\n", n);
  for(i=0; i<n; ++i){
    printf("A[%d]=%d\n", i,A[i]);

  }
}
