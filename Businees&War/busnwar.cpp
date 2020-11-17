#include<bits/stdc++.h>
using namespace std;

//Dimension of city
int m,n;

//Just a flag to be used for storing record of place which was visited
bool visited[10001][10001];

//To Represent Mumbai City
char ArrayMatrix[10001][10001];

//Four Direction possible inside city, here we are considering city as matrix
int move_in_x[] = {-1,0,1,0};
int move_in_y[] = {0,1,0,-1};

//Function checks whether it is possible to move to that position inside city
bool is_Valid_Move(int nextPosition_x, int nextPosition_y)
{
	if (nextPosition_x<1 || nextPosition_x>m || nextPosition_y<1 || nextPosition_y>n) return false;
	
	if(visited[nextPosition_x][nextPosition_y] == true || ArrayMatrix[nextPosition_x][nextPosition_y]== 'G') return false;
	
	return true;
}

//Searching for the places 
void SearchingDFS(int nextPosition_x, int nextPosition_y)
{
	visited[nextPosition_x][nextPosition_y] = true;
	for(int i=0;i<4;i++)
	{
		if(is_Valid_Move(nextPosition_x + move_in_x[i], nextPosition_y + move_in_y[i]))
			SearchingDFS(nextPosition_x + move_in_x[i], nextPosition_y+ move_in_y[i]);	
	}
}

int main()
{
	//Input for Dimension
	cin>>m>>n;
	
	//Input for Graphical Representation 
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		cin>>ArrayMatrix[i][j];		
	}
	
	//Counter to be set for finding minimum number of place to be visited
	int Minimum_Number_Places = 0;
	
	//Main loop of algorithm
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		if(ArrayMatrix[i][j] =='P' && visited[i][j] == false)
		{
			SearchingDFS(i,j);
			Minimum_Number_Places++;			
		}
	}
	cout<<Minimum_Number_Places<<"\n";
	return 0;
}
















