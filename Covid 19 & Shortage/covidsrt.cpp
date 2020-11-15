#include<bits/stdc++.h>
using namespace std;

unordered_map<int,vector<int>> adjList_Graph,adjList_revGraph;
int cities_covered = 0;
void DFS1(int i,vector<bool>& visited, stack<int>& mystack)
{
	visited[i]=true;
	for(int j: adjList_Graph[i])
		if(visited[j]==false)
			DFS1(j,visited,mystack);

	mystack.push(i);
}
int DFS2(int i,vector<bool>& visited)
{
	cities_covered++;
	visited[i] = true;
	for(int j: adjList_revGraph[i])
		if(!visited[j])
			DFS2(j,visited);
	return cities_covered;
}

int main()
{
	int n,p,city_i, city_j,max_cities_covered = 0;
	stack<int> mystack;
	cin>>n>>p;
	for(int i=0;i<p;i++)
	{
		cin>>city_i>>city_j;
	    adjList_Graph[city_i].push_back(city_j); 
	}
	

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

	while(!mystack.empty())
	{
		int curr = mystack.top();
		mystack.pop();
		if(visited[curr]==false)
		{
			cities_covered = DFS2(curr,visited);
			//cout<<cities_covered<<"\n";
			if (max_cities_covered==0) max_cities_covered = cities_covered;
			max_cities_covered = cities_covered>=max_cities_covered?cities_covered:max_cities_covered;
		
		    cities_covered = 0;
		}
	}
	cout<<"Max Cities He can cover is:- "<<max_cities_covered;

	return 0;
}
