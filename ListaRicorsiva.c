#include <stdio.h>
#include <stdlib.h>

struct elem{
  int k;
  struct elem *next;
};

struct elem *insInOrdineR(struct elem *top, int k);
void stampaLista(struct elem *top);

int main(){
  int n,i,k;
  struct elem *top=NULL;
  printf("Quanti elementi vuoi inserire: \n");
  scanf("%d", &n);
  for(i=0; i<n; ++i){
  printf("Dammi elemento da inserire: \n");
  scanf("%d", &k);
  top=insInOrdineR(top,k);
  }
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

struct elem *insInOrdineR(struct elem *top, int k){
  struct elem *tmp;
  if(top==NULL) //CASO BASE
  top=newElem(k);
  else {
  if(k < top->k){
  tmp=newElem(k);
  tmp->next=top;
  top=tmp;
  } else {
  //inserisco in ordine nel resto della lista mettendo da parte il top,
  //quindi la nuova lista top->next è costituita dall'intera lista senza il primo elemento
  //(ho ridotto il problema ad n-1 elementi)
  tmp=insInOrdineR(top->next, k);
  //avendo la soluzione per il problema ad n-1 elementi risolvo il problema con n elementi:
  top->next=tmp;
  }
  }
return top;
}

void stampaLista(struct elem *t){
  while(t!=NULL){
  printf("%d --> ", t->k);
  t=t->next;
  }
  printf("NULL\n");
}
