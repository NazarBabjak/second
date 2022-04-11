
typedef char elementtype;
typedef struct A {
    elementtype element;
    struct A* next;
    struct A* prev;
} celltype;

typedef celltype* LIST;
typedef celltype* position;

LIST MAKENULL(LIST L);
position END(LIST L);
position FIRST(LIST L);
LIST INSERT(elementtype x, position p, LIST L);
LIST DELETE(position p, LIST L);
elementtype RETRIEVE(position p, LIST);
position LOCATE(elementtype x, LIST L);
position NEXT(position p, LIST L);
position PREV(position p, LIST L);
void PRINTLIST(LIST);

#define newnode() (celltype*)malloc(sizeof(celltype*))
#define printlist(L) {for (position _t=L;(_t->next!=NULL)||(!printf("\n"));_t=_t->next) {printf ("%c, ",_t->next->element);}} 
#define NONE (celltype*)NULL