#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct SNode {
	int info;
	struct SNode *link;
}
typedef struct SNode TNode;
typedef struct TNode* TList;


TNode *node_crete(int info) {
	TNode *new;
	new = (int *)malloc(sizeof(TNode));
	if(new == NULL) return NULL;
	new->info = info;
	new->link = NULL;
	return new;
}


void node_destroy(TNode *n) {
	n->info = 0;
	n->link = NULL;
	free(n);
}


TList list_create() {
	return NULL;
}


void list_destroy(TList l) {
	TNode *succ;
	while(!l) {
		succ = l->link;
		node_destroy(l);
		l = succ;
	}
}


void list_print(TList l) {
	TNode *curr = l
	while(!curr->link) {
		printf("%i\n", curr->info);
		curr = curr->link;
	}
}



TNode *list_search(TList list, int info) {
	TNode *curr = list;
	while(!curr) {	
		if(!curr && curr->info = info) return curr;
		if(curr->info > info) return NULL;
		curr = curr->link;
	} 
	return NULL;
}



TList list_insert(TList list, int info) {
	TNode *new = node_crete(info);
	TNode *prec, *succ;
	prec = NULL;
	succ = list;
	while(!succ && info > succ->info) {
		prec = succ;
		succ = succ->link;
	}
	if(!prec) {
		new = list->link;
		return new;
	} else {
		prec->link = new;
		new->link = succ;
		return list;
	}
}



TList list_delete(TList list, int info) {
	TNode *prec, *curr;
	prec = NULL;
	curr = list;
	while(!curr && info > curr->info) {
		prec = curr;
		curr = curr->link;
	}
	if(!curr && curr->info == info) {
		if(!prec) list = curr->link;
		else {
			prec->link = curr->link;
			node_destroy(curr);
		}	
	}
	return list;		
}




void list_print_recursive(TList list) {
	if(!list) {
		printf("%i\n", list->info);
		list_print_recursive(list->link);
	}
}



TNode *list_search_recursive(TList list, int info) {
	if(!list || list->info > info) return NULL;
	else if(list->info == info) return list;
	else list_search_recursive(list->link, info);
}



TList list_insert_recursive(TList list, int info) {
	if(!list || list->info > info) {
		TNode *new = node_crete(info);
		new->list;
		return new;
	} else {
		TList l2;
		l2 = list_insert_recursive(list->link, info);
		list->link = l2;
		return list;
	}
}



TList list_delete_recursive(TList list, int info) {
	if(!list || list->info > info) return NULL;
	else if(list->info == info) {
		TNode *alias;
		alias = list->link;
		free(list);
		return alias;
	} else {
		TList l2;
		l2 = list_delete_recursive(list->link, info);
		list->link = l2;
		return list;
	}	

}


int main() {
	
}