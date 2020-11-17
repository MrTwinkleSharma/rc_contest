#include<bits/stdc++.h>
using namespace std;

bool is_Valid_Move(int x, int y, char ArrayMatrix[][] , bool visited[][])
{
	if (x<1 || x>N || y<1 || y>M) return false;
	
	if(visited[x][y] == true || ArrayMatrix[x][y]== 'G') return false;
	
	return true;
}

void DFS(int x, int y, char ArrayMatrix[][] , bool visited[][])
{
	visited[x][y] = true;
	if(is_Valid_Move(x-1,y,ArrayMatrix,visited))
	DFS(x-1,y);
	
	if(is_Valid_Move(x,y+1,ArrayMatrix,visited))
	DFS(x,y+1);
	
	if(is_Valid_Move(x+1,y,ArrayMatrix,visited))
	DFS(x+1,y));
	
	if(is_Valid_Move(x,y-1,ArrayMatrix,visited))
	DFS(x,y-1);
}

int main()
{
	int m,n;
	cin>>m>>n;
	bool visited[m][n];
	char ArrayMatrix[m][n];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		cin>>ArrayMatrix[i][j];		
	}
	
	int count = 0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		if(ArrayMatrix[i][j] =='P' && visited[i][j] == false)
		{
			DFS(i,j,ArrayMatrix,visited);
			count++;			
		}
	}
	cout<<count;
	return 0;
}
















