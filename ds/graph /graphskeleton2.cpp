
#include <iostream>
#include <vector>
#include <list>
# define k 4

using namespace std;

void printgraph(vector< list<int> > adjlist)
{
	vector< list<int> >::iterator it;
	int c = 0;

	for (it = adjlist.begin(); it != adjlist.end(); ++it)
	{
		
		cout << "vertex " << c << " is connected to: ";
		list<int> li = *it;
		list<int>::iterator lit;
		for (lit = li.begin(); lit != li.end(); ++lit)
			cout << *lit << ", ";
		cout << endl;
		c++;
	} 
}

int main(int argc, char const *argv[])
{
	vector< list<int> > adjlist(k);

	adjlist[0].push_back(1);
	adjlist[0].push_back(2);
	adjlist[0].push_back(3);
	adjlist[2].push_back(3);
	adjlist[3].push_back(1);

	printgraph(adjlist);

	return 0;
}