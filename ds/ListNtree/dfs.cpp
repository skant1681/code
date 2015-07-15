// Breath-First Search

#include <iostream>
#include <list>

using namespace std;

class Graph
{

	int v;
	list<int> *adj;
public:
	Graph(int v);
	void addedge(int source, int dest);
	void dfsgraph(int source);
	void print();
};

Graph::Graph(int v)
{
	this->v = v;
	adj = new list<int> [v];
}

void Graph::addedge(int source, int dest)
{
	adj[source].push_back(dest);
}

void Graph::print(){cout << "yaba, dabba, dooo!!" << endl ;}

void Graph::dfsgraph(int source)
{

}

int main(int argc, char const *argv[])
{
	Graph g(4);
	/*Graph g2(7);*/

	g.addedge(0,1);
	g.addedge(0,2);
	g.addedge(1,2);
	g.addedge(2,0);
	g.addedge(2,3);
	g.addedge(3,3);

	g.dfsgraph(2);
/*
	g2.addedge(0,2);
	g2.addedge(0,3);
	g2.addedge(2,4);
	g2.addedge(2,6);
	g2.addedge(3,6);
	g2.addedge(3,5);
	g2.addedge(3,0);
	g2.addedge(5,6);
	g2.addedge(1,4);

	g2.bfsgraph(3);*/

	

	return 0;
}