#include <stdio.h>
#include <stdlib.h>

struct elem{
  int k;
  struct elem *next;
};

//eliminare elementi minori di k
struct elem *eliminaElemeniMinoreR(struct elem *top, int k);
struct elem *inserisciInCodaR(struct elem *top, int k);
void stampaLista(struct elem *top);

int main(){
  int n,i,k;
  struct elem *top=NULL;
  printf("Quanti elementi vuoi inserire: \n");
  scanf("%d", &n);
  for(i=0; i<n; ++i){
  printf("Dammi elemento da inserire: \n");
  scanf("%d", &k);
  top=inserisciInCodaR(top,k);
  }
  printf("\nLista ottenuta: \n");
  stampaLista(top);
  printf("elemento k: \n");
  scanf("%d", &k);
  top = eliminaElemeniMinoreR(top,k);
  printf("\nLista ottenuta: \n");
  stampaLista(top);
return 0;
}

struct elem *newElem(int k){
  struct elem *tmp=(struct elem *) malloc(sizeof(struct elem));
  tmp->k=k;
  tmp->next=NULL;
  return tmp;
}

struct elem *inserisciInCodaR(struct elem *top, int k){

}

struct elem *eliminaElemeniMinoreR(struct elem *top, int k){
  struct elem *res=NULL;
  struct elem *tmp;
/*  if(top==NULL){
  res=NULL;
} else*/
  if(top!=NULL){ //considero tutta la lista escluso il primo
  tmp = top->next;
  //suppongo che la mia funzione sia coretta su tmp, restituisce la lista senza gli elementi minori di k
  eliminaElemeniMinoreR(tmp,k);
  //adesso posso considerare che il res ci sia la lista tmp senza gli elementi minori di k
  //allora se il top della mia lusta completa(cioè l'elemento che ho escluso, è maggiore o uguale a k lo devo aggiungere a re, altrimenti eliminarlo)
  if(top->k < k){
    free(top);
  } else {
    top->next = res;
    res=top;
  }
}
return res;
}

void stampaLista(struct elem *t){
  while(t!=NULL){
  printf("%d --> ", t->k);
  t=t->next;
  }
  printf("NULL\n");
}
