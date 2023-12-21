// write a menu-driven program to perform the following operations on a directed graph
// DFS, BFS, display using adjacency list & matrix

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct graph
{
	int vertices;
	struct node *adjacencylist[100];
};

int visited[100];

struct graph *create(int vertices)
{
	struct graph *graph = (struct graph*)malloc(sizeof(struct graph));
	graph->vertices = vertices;

	for(int i = 0; i < vertices; i++)
	{
		graph->adjacencylist[i] = NULL;
	}

	return graph;
}

void addedge(struct graph *graph, int src, int dest)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = dest;
	node->next = graph->adjacencylist[src];
	graph->adjacencylist[src] = node;
}

void dfs(struct graph *graph, int vertex)
{
	visited[vertex] = 1;
	printf("%d ", vertex);
	struct node *temp = graph->adjacencylist[vertex];

	while(temp != NULL)
	{
		int adjvertex = temp->data;

		if(!visited[adjvertex])
		{
			dfs(graph, adjvertex);
		}

		temp = temp->next;
	}
}

void bfs(struct graph *graph, int startvertex)
{
	int queue[100];
	int front = -1, rear = -1;
	visited[startvertex] = 1;
	printf("%d ", startvertex);
	rear++;
	queue[rear] = startvertex;

	while(front != rear)
	{
		front++;
		int currentvertex = queue[front];
		struct node *temp = graph->adjacencylist[currentvertex];

		while(temp != NULL)
		{
			int adjvertex = temp->data;

			if(!visited[adjvertex])
			{
				visited[adjvertex] = 1;
				printf("%d ", adjvertex);
				rear++;
				queue[rear] = adjvertex;
			}

			temp = temp->next;
		}
	}
}

void list(struct graph *graph)
{
	printf("\nAdjacency list:\n\n");

	for(int i = 0; i < graph->vertices; i++)
	{
		printf("%d -> ", i);
		struct node *temp = graph->adjacencylist[i];
		
		while(temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}

		printf("\n");
	}
}

void matrix(struct graph *graph)
{
	printf("\nAdjacency matrix:\n\n");

	for(int i = 0; i < graph->vertices; i++)
	{
		for(int j = 0; j < graph->vertices; j++)
		{
			int isedge = 0;
			struct node *temp = graph->adjacencylist[i];

			while(temp != NULL)
			{
				if(temp->data == j)
				{
					isedge = 1;
					break;
				}

				temp = temp->next;
			}

			printf("%d ", isedge);
		}

		printf("\n");
	}
}

void main()
{
	int vertices, ch, startvertex;
	printf("Enter number of vertices:\n");
	scanf("%d", &vertices);
	struct graph *graph = create(vertices);

	while(1)
	{
		printf("\nMenu:\n");
		printf("1. Add edge\n");
		printf("2. DFS\n");
		printf("3. BFS\n");
		printf("4. Adjacency list\n");
		printf("5. Adjacency matrix\n");
		printf("Any other value to exit\n");
		printf("Enter choice:\n");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
				printf("\nEnter source and destination vertices:\n");
				int src, dest;
				scanf("%d %d", &src, &dest);
				addedge(graph, src, dest);
				break;

			case 2:
				printf("\nEnter starting vertex:\n");
				scanf("%d", &startvertex);
				printf("DFS:\n");

				for(int i = 0; i < 100; i++)
				{
					visited[i] = 0;
				}

				dfs(graph, startvertex);
				printf("\n");
				break;

			case 3:
				printf("\nEnter starting vertex:\n");
				scanf("%d", &startvertex);
				printf("BFS:\n");

				for(int i = 0; i < 100; i++)
				{
					visited[i] = 0;
				}

				bfs(graph, startvertex);
				printf("\n");
				break;

			case 4:
				list(graph);
				break;

			case 5:
				matrix(graph);
				break;

			default:
				return;
		}
	}
}

