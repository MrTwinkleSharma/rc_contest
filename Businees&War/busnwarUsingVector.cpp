#include<bits/stdc++.h>
using namespace std;

bool is_Valid_Move(int m, int n, int x, int y, vector< vector<char> > &ArrayMatrix , vector< vector<bool> > &visited)
{
	if (x<1 || x>m || y<1 || y>n) return false;
	
	if(visited[x][y] == true || ArrayMatrix[x][y]== '#') return false;
	
	return true;
}

void DFS(int m, int n, int x, int y, vector< vector<char> > &ArrayMatrix , vector< vector<bool> > &visited)
{
	visited[x][y] = true;
	if(is_Valid_Move(m,n,x-1,y,ArrayMatrix,visited))
	DFS(m,n,x-1,y,ArrayMatrix,visited);
	
	if(is_Valid_Move(m,n,x,y+1,ArrayMatrix,visited))
	DFS(m,n,x,y+1,ArrayMatrix,visited);
	
	if(is_Valid_Move(m,n,x+1,y,ArrayMatrix,visited))
	DFS(m,n,x+1,y,ArrayMatrix,visited);
	
	if(is_Valid_Move(m,n,x,y-1,ArrayMatrix,visited))
	DFS(m,n,x,y-1,ArrayMatrix,visited);
}

int main()
{
	int m,n;
	cin>>m>>n;
	vector< vector<char> > ArrayMatrix(n+1, vector<char> (m+1, 'G'));
	vector< vector<bool> > visited(n+1 , vector<bool> (m+1, false));
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		cin>>ArrayMatrix[i][j];		
	}
	
	int count = 0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		if(ArrayMatrix[i][j] =='.' && visited[i][j] == false)
		{
			DFS(m,n,i,j,ArrayMatrix,visited);
			count++;			
		}
	}
	cout<<count;
	return 0;
}
















