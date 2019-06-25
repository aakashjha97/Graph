#include<bits/stdc++.h>
using namespace std;

class Graph{
	int v;
	list<int> *g;
public:
	//Constructor
	Graph(int V)
	{
		v=V;
		g=new list<int>[v];
	}

	//Add a new Edge to the graph
	void addEdge(int u,int v,bool bidir=true)
	{
		g[u].push_back(v);
		if(bidir)
			g[v].push_back(u);
	}

	//print the graph
	void print()
	{
		for(int i=0;i<v;i++)
		{
			for(auto j:g[i])
				cout<<j<<" ";
			cout<<endl;
		}
	}

	//dfs traversal
	void dfs(int s,bool *vis)
	{
		vis[s]=true;
		cout<<s<<" ";
		for(auto i:g[s])
		{
			if(!vis[i])
			{
				dfs(i,vis);
			}
		}
	}

	//bfs traversal
	void bfs(int s,bool *vis)
	{
		queue<int> q;
		q.push(s);
		vis[s]=true;
		while(!q.empty())
		{
			int t=q.front();
			cout<<t<<" ";
			q.pop();
			for(auto i:g[t])
			{
				if(!vis[i])
				{
					q.push(i);
					vis[i]=true;
				}
			}
		}
	}
};

int main()
{
	Graph g(5);
	g.addEdge(0, 1); 
    g.addEdge(0, 4); 
    g.addEdge(1, 2); 
    g.addEdge(1, 3); 
    g.addEdge(1, 4); 
    g.addEdge(2, 3); 
    g.addEdge(3, 4);
    g.print();
    bool *vis=new bool[5];
    cout<<"DFS: ";
    for(int i=0;i<=5;i++) 
    	vis[i]=false;
    g.dfs(0,vis);
    cout<<endl<<"BFS: ";
    for(int i=0;i<=5;i++) 
    	vis[i]=false;
    g.bfs(0,vis);

	return 0;
}