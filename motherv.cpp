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
	void addEdge(int u,int v,bool bidir=false)
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
		//cout<<s<<" ";
		for(auto i:g[s])
		{
			if(!vis[i])
			{
				dfs(i,vis);
			}
		}
		return;
	}

	int motherV(bool* vis)
	{
		int lv;
		for(int i=0;i<v;i++)
		{
			if(!vis[i])
			{
				dfs(i,vis);
				lv=i;
			}
		}
		for(int i=0;i<v;i++) 
    	vis[i]=false;
    	dfs(lv,vis);
    	for(int i=0;i<v;i++) 
    	if(!vis[i])
    		return -1;
    	return lv;
	}
};

int main()
{
	Graph g(7); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(4, 1); 
    g.addEdge(6, 4); 
    g.addEdge(5, 6); 
    g.addEdge(5, 2); 
    g.addEdge(6, 0);
    bool *vis=new bool[7];
    for(int i=0;i<7;i++) 
    	vis[i]=false;
    cout<<g.motherV(vis)<<endl;
    
	return 0;
}