// write a menu-driven program to implement a binary tree using a linked list & perform insertion, deletion & traversal

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left, *right;
};

struct node *create()
{
	int data;
	struct node *p;
	p = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data (-1 for no insertion):\n");
	scanf("%d", &data);

	if(data == -1)
	{
		return 0;
	}

	p->data = data;
	printf("Left child of %d", data);
	p->left = create();
	printf("Right child of %d", data);
	p->right = create();
	return p;
}

void delnode(int data, struct node *root)
{
	if(root == NULL)
	{
		return;
	}

	if(root->left->data == data)
	{
		root->left = NULL;
		return;
	}

	else if(root->right->data == data)
	{
		root->right = NULL;
		return;
	}

	delnode(data, root->left);
	delnode(data, root->right);
}

void inorder(struct node *root)
{
	if(root == NULL)
	{
		return;
	}

	inorder(root->left);
	printf("%d\t", root->data);
	inorder(root->right);
}

void preorder(struct node *root)
{
	if(root == NULL)
	{
		return;
	}

	printf("%d\t", root->data);
	preorder(root->left);
	preorder(root->right);
}

void main()
{
	struct node *root = NULL;
	int ch, data;

	while(1)
	{
		printf("Menu\n");
		printf("1. Insertion\n");
		printf("2. Deletion\n");
		printf("3. Inorder traversal\n");
		printf("4. Preorder traversal\n");
		printf("Any other value to exit\n");
		printf("Enter choice:\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: root = create();
				printf("\n");
				break;

			case 2: printf("\nEnter node to delete:\n");
				scanf("%d", &data);
				delnode(data, root);
				printf("\n");
				break;

			case 3: printf("\n");
				inorder(root);
				printf("\n");
				break;

			case 4: printf("\n");
				preorder(root);
				printf("\n");
				break;

			default: return;
		}
	}
}
