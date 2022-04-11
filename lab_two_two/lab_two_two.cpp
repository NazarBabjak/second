#include <stdio.h>
#include <stdlib.h>
#include "lincedlist.h"


//створює порожній список
LIST MAKENULL(LIST L) {
	L = newnode();
	L->next = NULL;
	L->prev = NULL;
	return L;
}
//повертає позицію, яка слідує одразу після позиціх n в n-елементному списку
position END(LIST L) {
	position q = L;
	while (q->next != NULL)
		q = q->next;
	return q;
}

//оператор вставляє елемент x в позицію p в списку L
LIST INSERT(elementtype x, position p, LIST L) {
	position temp;
	temp = newnode();
	temp->element = x;
	temp->next = p->next;
	p->next = temp;
	temp->prev = p;
	if (temp->next != NULL)
		temp->next->prev = temp;
	return L;
}

//видаляє елемент в позиції p із списку L
LIST DELETE(position p, LIST L) {
	if (p->prev != NULL)
		p->prev->next = p->next;
	if (p->next != NULL)
		p->next->prev = p->prev;
	return L;
}


//повертає першу позицію в списку
position FIRST(LIST L) {
	return L;
}

//визначає позицію елемента x в списку L
position LOCATE(elementtype x, LIST L) {
	position p = L;
	while (p->next != NULL) {
		if (p->next->element == x)
			return p->next;
		else p = p->next;
	}
	return END(L);
}

//повертає елемент, що знаходиться в позиції p в списку L
elementtype RETRIEVE(position p, LIST L) {
	return p->element;
}

//повертає наступну позицію від позиції p в списку L
position NEXT(position p, LIST L) {
	if (p->next != NULL)
		return p->next;
	return NONE;
}

//повертає попередню позицію від позиції p в списку L
position PREV(position p, LIST L) {
	if (p->prev != NULL)
		return p->prev;
	return NONE;
}


int main() {
	LIST L = *new LIST;
	L = MAKENULL(L);
	INSERT('d', FIRST(L), L);
	INSERT('a', FIRST(L), L);
	INSERT('c', END(L)->prev, L);
	INSERT('e', END(L), L);
	INSERT('b', FIRST(L)->next, L);
	DELETE(LOCATE('x', L), L);
	printlist(L);
	system("pause");
	return 0;
}