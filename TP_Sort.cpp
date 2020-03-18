#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

class Topo_Graph
{
public:
	map< int,list<int> > M;

public:
	Topo_Graph(int N);
	void addEdge(int f, int t);
	void Topo_Sort();
	void Topo_Sort_Visit(int v,map<int,bool> *vis,queue<int> &Q);

};

int main()
{
	int N;
	while(cin >> N)
	{
		Topo_Graph G(N);
		int a;
		cin >> a;
		while(a--)
		{
			int f,t;
			char c;
			cin >> f >> c >> t;
			if(c=='<')
				swap(f,t);
			G.addEdge(f,t);
		}
		G.Topo_Sort();
	}
}

Topo_Graph::Topo_Graph(int N)
{
	while(N--)
	{
		int tmp;
		list<int> l;
		cin >> tmp;
		M[tmp]=l;
	}
}

void Topo_Graph::addEdge(int f, int t)
{
    M[f].push_back(t);
}

void Topo_Graph::Topo_Sort_Visit(int v,map<int,bool> *vis,queue<int> &Q)
{
	vis->at(v)=true;
	list<int>::iterator i;
	for(i=M[v].begin();i!=M[v].end();i++)
	{
		if(!vis->at(*i))
			Topo_Sort_Visit(*i, vis, Q);
	}
	Q.push(v);
}

void Topo_Graph::Topo_Sort()
{
	queue<int> Q;
	map<int,bool> vis;
	map< int,list<int> >::iterator i;
	for(i=M.begin();i!=M.end();i++)
	{
		vis[i->first]=false;
	}
	for(i=M.begin();i!=M.end();i++)
	{
		if(vis[i->first]==false)
			Topo_Sort_Visit(i->first,&vis,Q);
	}
	ofstream out("TP_Sort_0516046.txt",ios::app);
	while(!Q.empty())
	{
		out << Q.front() << " ";
		Q.pop();
	}
	out << endl;
}