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
struct elem *inserisciInOrdineR(struct elem * top, int k);
struct elem *mergeR(struct elem *top1, struct elem *top2);

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
  if (top==NULL) { //passo base
    top=(struct elem *)malloc(sizeof(struct elem));
    top->next=NULL;
    top->k=k;
  } else {
    //faccio chiamata ricorsiva u tuttab la lista, escluso il primo elemento
    //suppongo che la lita restituita sia ben fatta, devo solo aggiungere il primo elemento alla lista così ottenuta

    top->next=inserisciInCodaR(top->next, k);
  }
  return top;
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

void stampaLista(struct elem *top){
  while(top!=NULL){
  printf("%d --> ", top->k);
  top=top->next;
  }
  printf("NULL\n");
  /*if(top==NULL) {
    printf("NULL\n");
  } else {
    printf("%d->\n", top->k);
    stampaLista(top->next); //queta è detta finta ricorsione perche dopo la chiamata ricorsiva non faccio nulla, in questi casi sempre meglio l'iterazione!

  }*/
}

struct elem *inserisciInOrdineR(struct elem * top, int k){
  struct elem *tmp;
  if (top==NULL){
    top=(struct elem *)malloc(sizeof(struct elem));
    top->next=NULL;
    top->k=k;
  } else {
    if (k<top->k){
      tmp=(struct elem *)malloc(sizeof(struct elem));
      tmp->next=top;
      tmp->k=k;
      top=tmp;
    } else {
      top->next=inserisciInOrdineR(top->next, k);
    }
  }
  return top;
}

//versione che distrugge le liste originali
//tale codici può essere scritto in maniera più sintetica
struct elem *mergeR(struct elem *top1, struct elem *top2){
  struct elem *res, *min, *tmp;
  if(top1==NULL) res=top2;
  else if(top2==NULL) res=top1;
  else { //entrambe diverse da null
  //se ho due liste ordinate in maniera crescente il più piccolo di tutti sarà il minimo tra il top della prima lista ed il top della seconda lista
  if(top1->k < top2->k){
  //stacco top1 dalla prima lista e risolvo lo stesso problema senza top1 poi rimetto in testa top1
  min=top1;
  tmp=mergeR(top1->next, top2);
  //assumo che tmp è una lista ordinata composta dagli elementi di top1 senza il primo elemento e top2, allora aggiungo in testa a tale lista l'elementp che avevo escluso;
  min->next=tmp;
  res=min;
} else {
  //stacco top2 dalla seconda lista e risolvo lo stesso problema senza top2 poi rimetto in testa top2
  min=top2;
  tmp=mergeR(top1, top2->next);
  //assumo che tmp è una lista ordinata composta dagli elementi di top2 senza il primo elemento e top1, allora aggiungo in testa a tale lista l'elementp che avevo escluso;
  min->next=tmp;
  res=min;
}
}
return res;
}
