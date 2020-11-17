#include<bits/stdc++.h>
using namespace std;
int m,n;
	
bool visited[10001][10001];
char ArrayMatrix[10001][10001];
int move_in_x[] = {-1,0,1,0};
int move_in_y[] = {0,1,0,-1};


bool is_Valid_Move(int x, int y)
{
	if (x<1 || x>m || y<1 || y>n) return false;
	
	if(visited[x][y] == true || ArrayMatrix[x][y]== '#') return false;
	
	return true;
}

void DFS(int x, int y)
{
	visited[x][y] = true;
	for(int i=0;i<4;i++)
	{
		if(is_Valid_Move(x + move_in_x[i], y + move_in_y[i]))
			DFS(x + move_in_x[i], y+ move_in_y[i]);	
	}
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
		if(ArrayMatrix[i][j] =='.' && visited[i][j] == false)
		{
			DFS(i,j);
			count++;			
		}
	}
	cout<<count;
	return 0;
}
















