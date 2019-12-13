#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <time.h>

#define BUFSIZE 50

typedef struct node* node_p;
typedef struct node {
	node_p left; //Left child within RB tree.
	node_p right; //Right child within RB tree.
	node_p parent; //Parent within RB tree.
	node_p nil;
	char clr; // r,b color

	char name[BUFSIZE];
	int cost; //50 - 300 random select * 1000

}node;


void create_nilnode(node_p* T) {
	node_p Null = (node_p)malloc(sizeof(node));
	Null->clr = 'B';
	(*T) = Null;
	(*T)->nil = Null;
}

void Left_Rotate(node_p* T, node_p z) {
	node_p temp;

	temp = z->right;
	z->right = temp->left;

	if (temp->left != (*T)->nil) {
		temp->left->parent = z;
	}

	temp->parent = z->parent;

	if (z->parent == (*T)->nil) {
		(*T) = temp;
	}
	else if (z == z->parent->left) {
		z->parent->left = temp;
	}
	else {
		z->parent->right = temp;
	}

	temp->left = z;
	z->parent = temp;
}

void Right_Rotate(node_p* T, node_p z) {
	node_p temp;

	temp = z->left;
	z->left = temp->right;

	if (temp->right != (*T)->nil) {
		temp->right->parent = z;
	}

	temp->parent = z->parent;

	if (z->parent == (*T)->nil) {
		(*T) = temp;
	}
	else if (z == z->parent->left) {
		z->parent->left = temp;
	}
	else {
		z->parent->right = temp;
	}
	temp->right = z;
	z->parent = temp;
}

void insert_fixup(node_p* T, node_p z) {
	node_p y = NULL;
	while (z->parent->clr == 'R') {
		if (z->parent == z->parent->parent->left) {
			y = z->parent->parent->right;
			if (y->clr == 'R') {
				z->parent->clr = 'B';
				y->clr = 'B';
				z->parent->parent->clr = 'R';
				z = z->parent->parent;
			}
			else {
				if (z->parent->right == z) {
					z = z->parent;
					Left_Rotate(T, z);
				}
				z->parent->clr = 'B';
				z->parent->parent->clr = 'R';
				Right_Rotate(T, z->parent->parent);
			}
		}

		else {
			y = z->parent->parent->left;

			if (y->clr == 'R') {
				z->parent->clr = 'B';
				y->clr = 'B';

				z->parent->parent->clr = 'R';

				z = z->parent->parent;
			}
			else {
				if (z == z->parent->left) {
					z = z->parent;
					Right_Rotate(T, z);
				}

				z->parent->clr = 'B';
				z->parent->parent->clr = 'R';
				Left_Rotate(T, z->parent->parent);
			}
		}
	}
	(*T)->clr = 'B';
}

void RB_INSERT(node_p* T, char* name, int z) {
	node_p new_Node = (node_p)malloc(sizeof(node));
	strcpy(new_Node->name, name);
	new_Node->cost = z;
	new_Node->left = (*T)->nil; new_Node->right = (*T)->nil; new_Node->parent = NULL;
	new_Node->clr = 'R';
	new_Node->nil = (*T)->nil;
	node_p y = (*T)->nil;
	node_p x = *T;

	while (x != (*T)->nil) {
		y = x;
		if (z < x->cost)
			x = x->left;
		else if (z > x->cost)
			x = x->right;
		else
			return;
	}
	new_Node->parent = y;

	if (y == (*T)->nil)
		* T = new_Node;
	if (z < y->cost)
		y->left = new_Node;
	else
		y->right = new_Node;
	insert_fixup(T, new_Node);
}


void tree_transplant(node_p* T, node_p t, node_p c)
{
	if (t->parent == (*T)->nil)
	{
		(*T) = c;
	}
	else if (t == (t->parent)->left)
	{
		(t->parent)->left = c;
	}
	else
	{
		(t->parent)->right = c;
	}

	c->parent = t->parent;
}

void delete_fixup(node_p* T, node_p x)
{
	node_p s = NULL;

	while ((x != *T) && (x->clr == 'B'))
	{
		if (x == (x->parent)->left)
		{
			s = (x->parent)->right;


			if (s->clr == 'R')
			{
				s->clr = 'B';
				(x->parent)->clr = 'R';
				Left_Rotate(T, x->parent);

				s = (x->parent)->right;
			}


			if ((s->left)->clr == 'B' && (s->right)->clr == 'B')
			{
				s->clr = 'R';
				x = x->parent;
			}

			else if ((s->left)->clr == 'R' && (s->right)->clr == 'B')
			{
				s->clr = 'R';
				(s->left)->clr = 'B';
				Right_Rotate(T, s);

				s = (x->parent)->right;
			}


			if ((s->right)->clr == 'R')
			{
				s->clr = (x->parent)->clr;
				(s->right)->clr = 'B';
				(x->parent)->clr = 'B';
				Left_Rotate(T, x->parent);

				x = *T;
			}

		}
		else
		{
			s = (x->parent)->left;


			if (s->clr == 'R')
			{
				s->clr = 'B';
				(x->parent)->clr = 'R';
				Right_Rotate(T, x->parent);
				// update x's sibling
				s = (x->parent)->left;
			}


			if ((s->left)->clr == 'B' && (s->right)->clr == 'B')
			{
				s->clr = 'R';
				x = x->parent;
			}

			else if ((s->right)->clr == 'R' && (s->left)->clr == 'B')
			{
				s->clr = 'R';
				(s->right)->clr = 'B';
				Left_Rotate(T, s);
				// update x's sibling
				s = (x->parent)->left;
			}


			if ((s->left)->clr == 'R')
			{
				s->clr = (x->parent)->clr;
				(s->left)->clr = 'B';
				(x->parent)->clr = 'B';
				Right_Rotate(T, x->parent);

				x = *T;
			}
		}
	}

	x->clr = 'B';
}

void RB_DELETE(node_p* T, int key)
{
	node_p target = *T;
	node_p temp = NULL;
	node_p x = NULL;
	char t_clr;


	while (key != target->cost)
	{
		if (target == (*T)->nil)
			return;
		if (target->cost > key)
		{
			target = target->left;
		}
		else if (target->cost < key)
		{
			target = target->right;
		}

	}
	t_clr = target->clr;


	if (target->left == (*T)->nil)
	{
		x = target->right;
		tree_transplant(T, target, target->right);
	}

	else if (target->right == (*T)->nil)
	{
		x = target->left;
		tree_transplant(T, target, target->left);
	}
	else
	{
		temp = target->right;


		while (temp->left != (*T)->nil)
		{
			temp = temp->left;
		}

		t_clr = temp->clr;
		x = temp->right;

		tree_transplant(T, temp, temp->right);
		temp->right = target->right;
		(temp->right)->parent = temp;

		tree_transplant(T, target, temp);
		temp->left = target->left;
		(temp->left)->parent = temp;
		temp->clr = target->clr;
	}

	if (t_clr == 'B')
	{
		delete_fixup(T, x);
	}

	free(target);
}


void inorder(node_p* h_T, node_p s) {
	if (s != (*h_T)->nil) {
		inorder(h_T, s->left);
		printf("%s[%d]\n", s->name, s->cost);
		inorder(h_T, s->right);
	}
}

node_p make_rbt(node_p* h_T) {
	srand(time(NULL));
	char node_name[10]; strcpy(node_name, "node-");
	int cost[100];
	//node key
	for (int i = 0; i < 100; i++) {
		cost[i] = (rand() % 250 + 51) * 1000;
		for (int j = 0; j < i; j++) {
			if (cost[i] == cost[j])
				i--;
		}
	}

	create_nilnode(h_T);
	//node-1 ~ node-100
	for (int i = 1; i <= 100; i++) {
		int j = 0;
		char num[10];
		_itoa(i, num, 10);
		for (j = 0; num[j] != '\0'; j++) {
			node_name[j + 5] = num[j]; // ex) node-1, node-78
		}
		node_name[j + 5] = '\0';

		RB_INSERT(h_T, node_name, cost[i - 1]);
	}
	return *h_T;
}
