#include<bits/stdc++.h>
using namespace std;

unordered_map<int,vector<int>> adjList_Graph,adjList_revGraph;
void DFS1(int i,vector<bool>& visited, stack<int>& mystack)
{
	visited[i]=true;
	for(int j: adjList_Graph[i])
		if(visited[j]==false)
			DFS1(j,visited,mystack);

	mystack.push(i);
}
void DFS2(int i,vector<bool>& visited)
{
	cout<<i<<" ";
	visited[i] = true;
	for(int j: adjList_revGraph[i])
		if(!visited[j])
			DFS2(j,visited);
}

int main()
{
	int n,p,city_i, city_j;
	cin>>n>>p;
	for(int i=0;i<p;i++)
	{
		cin>>city_i>>city_j;
	    adjList_Graph[city_i].push_back(city_j); 
	}
	stack<int> mystack;

	vector<bool> visited(n,false);
	for(int i=0;i<n;++i)
		if(!visited[i])
			DFS1(i,visited,mystack);

	for(int i=0;i<n;++i)
	{
		for(int j: adjList_Graph[i])
			adjList_revGraph[j].push_back(i);
	}

	for(int i=0;i<n;++i)
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
