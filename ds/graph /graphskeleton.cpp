//adjacency list representation of undirected graph

#include <iostream>
#include <stdlib.h>

using namespace std;

struct AdjListNode
{
	int dest;
	struct AdjListNode* next;
};

typedef struct AdjListNode AdjListNode;

struct Graph
{
	int v;
	struct AdjList* array;
};

typedef struct Graph Graph;

struct AdjList
{
	struct AdjListNode* head;
};

typedef struct AdjList AdjList;

AdjListNode* GetListNode(int dest)
{
	AdjListNode* newnode = (AdjListNode* )malloc(sizeof(AdjListNode* )) ;
	newnode->dest = dest;
	newnode->next = NULL;

	return newnode;
}



// Creating an array of adjacency list
Graph* creategraph(int v)
{

	Graph* graph = (Graph* )malloc(sizeof(Graph* ));
	graph->v = v;
	graph->array = (AdjList* )malloc(v*sizeof(AdjList* ));

	for (int i = 0; i < v; ++i)
		graph->array[i].head = NULL;

	return graph;
}

void addedge(Graph* graph, int src, int dest)
{
	AdjListNode* newnode = GetListNode(dest);
	newnode->next = graph->array[src].head;
	graph->array[src].head = newnode;

	newnode = GetListNode(src);
	newnode->next = graph->array[dest].head;
	graph->array[dest].head = newnode;
}

void printgraph(Graph* graph)
{
	for (int i = 0; i < graph->v; ++i)
	{
		AdjListNode* current = graph->array[i].head;
		cout << i << " --> ";
		while(current)
		{
			cout << current->dest << " --> ";
			current = current->next;
		}
		cout << "NULL";
		cout << endl;
	}
}

int main(int argc, char const *argv[])
{
	int v = 4;

	cout << "number of nodes: " << endl;
	cout << v << endl;

	Graph* graph = creategraph(v); 

	addedge(graph, 0, 1);
	addedge(graph, 1, 2);
	addedge(graph, 1, 3);
	addedge(graph, 2, 3);
	addedge(graph, 2, 4);
	addedge(graph, 3, 4);

	printgraph(graph);
	

	return 0;
}