// write a menu-driven c program to implement a bst using a linked list & perform the following operations
// insertion, deletion, traversal, search for a specified node

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
    	struct node *left, *right;
};

struct node *root, *ptr;

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
    	ptr = root;

    	if(root == NULL)
        {
        	root = p;
        	create();
        	return 0;
        }

    	while(1)
        {
        	while(ptr->data >= p->data)
            	{
            		if(ptr->left != NULL)
                	{
                		ptr = ptr->left;
                	}

            		else
                	{
                		ptr->left = p;
                		create();
                		return 0;
               	 	}
            	}

        	while(ptr->data < p->data)
            	{
            		if(ptr->right != NULL)
                	{
                		ptr = ptr->right;
                	}

            		else
                	{
                		ptr->right = p;
                		create();
                		return 0;
                	}
            	}
        }
}

void search(int item)
{
	if(root==NULL)
	{
		printf("Node not found");
	}

	else if(ptr->data < item)
	{
		if(ptr->right != NULL)
		{
			ptr = ptr->right;
			search(item);
		}

		else
		{
			printf("Node not found");
			return;
		}
	}

	else if(ptr->data > item)
	{
		if(ptr->left != NULL)
	    	{
			ptr = ptr->left;
			search(item);
		}

		else
		{
			printf("Node not found");
			return;
		}
	}

	else
	{
		printf("Node found");
	}

	return;
}

void inorder(struct node *p)
{
	if(p == NULL)
	{
		return;
	}

	inorder(p->left);
	printf ("%d\t", p->data);
	inorder(p->right);
}

void preorder(struct node *p)
{
	if(p == NULL)
	{
		return;
	}

	printf ("%d\t", p->data);
	preorder(p->left);
	preorder(p->right);
}

void postorder(struct node* p)
{
	if(p == NULL)
	{
		return;
	}

	postorder(p->left);
	postorder(p->right);
	printf ("%d\t", p->data);
}

struct node *delete(struct node* ptr, int item)
{
	if(ptr == NULL)
	{
		return ptr;
	}

	struct node *temp;

	if(item < ptr->data)
	{
		ptr->left = delete(ptr->left, item);
	}

	else if(item > ptr->data)
	{
		ptr->right = delete(ptr->right, item);
	}

	else
	{
		if(ptr->left == NULL)
		{
			temp = ptr->right;
			free(ptr);
			return temp;
		}

		else if(ptr->right == NULL)
		{
			temp = ptr->left;
			free(ptr);
			return temp;
		}

		ptr->data = temp->data;
		ptr->right = delete(ptr->right, temp->data);
	}

	return ptr;
}

void main()
{
	int ch, item;
	root = NULL;

	while(1)
	{
	    	ptr = root;
		printf("Menu\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Inorder traversal\n");
		printf("4. Preorder traversal\n");
		printf("5. Postorder traversal\n");
		printf("6. Search\n");
		printf("Any other value to exit\n");
		printf("Enter choice:");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1: create();
				printf("\n");
		                break;

		        case 2: printf("Enter node to delete:");
		                scanf("%d", &item);
		                ptr = delete(ptr, item);
		                printf("\n");
		        	break;

		        case 3: inorder(ptr);
		        	printf("\n\n");
		        	break;

			case 4: preorder(ptr);
		        	printf("\n\n");
		        	break;

			case 5: postorder(ptr);
		        	printf("\n\n");
		        	break;

			case 6: printf("Enter node to search:");
		        	scanf("%d", &item);
		        	search(item);
		        	printf("\n\n");
		        	break;

			default: return;
		}
	}
}
