#include<bits/stdc++.h>
using namespace std;

//Graph Data Structure 
unordered_map<int,vector<int>> adjList_Graph,adjList_revGraph;

//Global Variable to be used in Recursive Function
int cities_covered = 0;

//Depth First Search on Original Graph 
void DFS1(int i,vector<bool>& visited, stack<int>& mystack)
{
	visited[i]=true;
	for(int j: adjList_Graph[i])
		if(visited[j]==false)
			DFS1(j,visited,mystack);

	mystack.push(i);
}

//Depth First Search on Reversed Graph (Actually this Gives Answer)
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
	// n = Number of Cities
	// p = Roads which are not Banned
	// city_i --> city_j denotes that there is a path from city_i to city_j
	int n,p,city_i, city_j, max_cities_covered = 0;
	
	// Stack to be used for Algorithm
	stack<int> mystack;
	cin>>n>>p;
	
	//Storing Graph
	for(int i=0;i<p;i++)
	{
	    cin>>city_i>>city_j;
	    adjList_Graph[city_i].push_back(city_j); 
	}
	
	//Initializing visited to false for each cities
	vector<bool> visited(n,false);
	for(int i=0;i<n;++i)
		if(!visited[i])
			DFS1(i,visited,mystack);

	//Reversing The Graph after storing the DFS on original Graph with Stack
	for(int i=0;i<n;++i)
	{
		for(int j: adjList_Graph[i])
			adjList_revGraph[j].push_back(i);
	}
	
	//Again Set visited = False to each city
	for(int i=0;i<n;++i)
		visited[i] = false;
	

	//Main Algorithm to Find the Maximum Cities which can be covered in whole drive
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
