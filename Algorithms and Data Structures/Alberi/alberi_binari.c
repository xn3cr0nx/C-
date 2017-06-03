#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct SNode {
	int info;
	struct SNode *left;
	struct SNode *right;
};
typedef struct SNode TNode;
typedef struct SNode *TBinaryTree;


TNode *create_node(int info) {
	TNode *new;
	new = (TNode*)malloc(sizeof(TNode));
	if(!new) return NULL;	
	new->info = info;
	new->left = NULL;
	new->right = NULL;
	return new;
}


void node_destroy(TNode *node) {
	free(node);
}


TBinaryTree binarytree_create() {
	return NULL;
}


TBinaryTree binarytree_destroy(TBinaryTree bt) {
	if(!bt);
	else if(!bt->left && !bt->right) free(bt);
	else {
		bt->left = binarytree_destroy(bt->left);
		bt->right = binarytree_destroy(bt->right);
		node_destroy(bt);
	}
	return NULL; 
}


void binarytree_visit(TBinaryTree bt) {
	if(bt) {
		binarytree_visit(bt->left);
		printf("%i\n", bt->info);
		binarytree_visit(bt->right);
	}
	
	
}

void binarytree_visit_preorder(TBinaryTree bt) {
	if(bt) {
		printf("%i\n", bt->info);
		binarytree_visit_preorder(bt->left);
		binarytree_visit_preorder(bt->right);
	}
}


void binarytree_visit_postorder(TBinaryTree bt) {
	if(bt) {
		binarytree_visit_preorder(bt->left);
		binarytree_visit_preorder(bt->right);
		printf("%i\n", bt->info);
	}
}


TNode *binarytree_search(TBinaryTree bt, int info) {
	while(bt && bt->info != info) {
		if(info < bt->info) bt = bt->left;
		else bt = bt->right;
	} 
	return bt;
}


TNode *binarytree_search_recursive(TBinaryTree bt, int info) {
	if(!bt || bt->info == info) return bt;
	else {
		if(info < bt->info) return binarytree_search(bt->left, info);
		else return binarytree_search(bt->right, info);
	}
}


TNode *binarytree_min(TBinaryTree bt) {
	if(!bt) return NULL;
	else if(!bt->left) return bt;
	else {
		TNode *min = binarytree_min(bt->left);
		return min;
	}
}


TNode *binarytree_max(TBinaryTree bt) {
	if(!bt) return NULL;
	else if(!bt->right) return bt;
	else {
		TNode *max = binarytree_max(bt->right);
		return max;
	}
}


TBinaryTree binarytree_insert_recursive(TBinaryTree bt, int info) {
	if(!bt) {
		TNode *new = create_node(info);
		return new;
	}
	else if (info < bt->info) {
		bt->left = binarytree_insert_recursive(bt->left, info);
		return bt;
	}
	else {
		bt->right = binarytree_insert_recursive(bt->right, info);
		return bt;
	}
}



TBinaryTree binarytree_delete(TBinaryTree bt, int info) {
	if(!bt) return NULL;
	else if(info < bt->info) {
		bt->left = binarytree_delete(bt->left, info);
		return bt;
	}
	else if(info > bt->info) {
		bt->right = binarytree_delete(bt->right, info);
		return bt;
	}	
	else {
		if(!bt->left && !bt->right) {
			node_destroy(bt);
			return NULL;
		}
		if(!bt->right) {
			TNode *alias = bt->left;
			node_destroy(bt);
			return alias;
		}
		if(!bt->left) {
			TNode *alias = bt->right;
			node_destroy(bt);
			return alias;
		}
		TNode *min_right = binarytree_min(bt->right);
		bt->info = min_right->info;
		bt->right = binarytree_delete(bt->right, bt->info);
		return bt;
	}
}


int tree_leaves_count(TBinaryTree bt) {
	if(!bt) return 0;
	else if(!bt->left && !bt->right) return 1;
	else return tree_leaves_count(bt->left) + tree_leaves_count(bt->right);
}

int tree_nodes_count(TBinaryTree bt) {
	if(!bt) return 0;
	else return tree_nodes_count(bt->left) + tree_nodes_count(bt->right) + 1;
}

int tree_depth(TBinaryTree bt) {
	if(!bt) return 0;
	else {
		int depth_right = tree_depth(bt->right);
		int depth_left = tree_depth(bt->left);
		if(depth_right > depth_left) return depth_right + 1;
		else return depth_left + 1;
	}
}

bool tree_balanced(TBinaryTree bt) {
	if(!bt) return true;
	else { return tree_balanced(bt-> left) &&
								tree_balanced(bt-> right) &&
								abs(tree_depth(bt->left) - tree_depth(bt->right) <= 1);
	}
}

int main() {

}











