#include<bits/stdc++.h>
using namespace std;
int m,n;
	
bool visited[10001][10001];
char ArrayMatrix[10001][10001];


bool is_Valid_Move(int x, int y)
{
	if (x<1 || x>m || y<1 || y>n) return false;
	
	if(visited[x][y] == true || ArrayMatrix[x][y]== 'G') return false;
	
	return true;
}

void DFS(int x, int y)
{
	visited[x][y] = true;
	if(is_Valid_Move(x-1,y))
	DFS(x-1,y);
	
	if(is_Valid_Move(x,y+1))
	DFS(x,y+1);
	
	if(is_Valid_Move(x+1,y))
	DFS(x+1,y);
	
	if(is_Valid_Move(x,y-1))
	DFS(x,y-1);
}

int main()
{
	cin>>m>>n;
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
			DFS(i,j);
			count++;			
		}
	}
	cout<<count;
	return 0;
}
















