#include "rbt.h"

void main() {
	node_p root = NULL;
	node_p* h_T = &root;
	printf("��� Ȯ��\n");
	root = make_rbt(h_T);
	inorder(h_T, root);
	printf("\n\n");
}
