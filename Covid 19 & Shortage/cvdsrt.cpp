#include<bits/stdc++.h>
using namespace std;
vector<int> *adj, *rev;
void addEdge(vector<int> adj[], int v, int w) 
{ 
    adj[v].push_back(w); 
} 
void DFS1(int i,vector<bool>& visited,stack<int>& mystack)
{
	visited[i]=true;
	vector<int>::iterator j;
	for(j = adj[i].begin();j!=adj[i].end();j++)
		if(visited[*j]==false)
			DFS1(*j,visited,mystack);

	mystack.push(i);
}

void reverse(int V)
{
	for(int i=0;i<V;++i)
	{
		vector<int>::iterator j;
		for(j = adj[i].begin();j!=adj[i].end();j++)
			rev[*j].push_back(i);
	}
}

void DFS2(int i,vector<bool>& visited)
{
	cout<<i<<" ";
	visited[i] = true;
	vector<int>::iterator j;
	for(j = rev[i].begin();j!=rev[i].end();j++)
		if(!visited[*j])
			DFS2(*j,visited);
}
int main()
{
	int V,E;
	cin>>V>>E;
	 
	vector<int> *adj = new vector<int>[V]; 
	
	while(E--)
	{
		int v,w;
		cin>>v>>w;
		addEdge(adj, v, w);
	}
	
	stack<int> mystack;

	vector<bool> visited(V,false);
	for(int i=0;i<V;++i)
		if(!visited[i])
			DFS1(i,visited,mystack);

	reverse(V);

	for(int i=0;i<V;++i)
		visited[i] = false;

	cout<<"Strongly Connected Components are:\n";
	while(!mystack.empty())
	{
		int curr = mystack.top();
		mystack.pop();
		if(visited[curr]==false)
		{
			DFS2(curr,visited);
			cout<<"\n";
		}
	}
	return 0;
}
