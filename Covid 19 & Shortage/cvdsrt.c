#include<stdio.h>
#include<stdlib.h>
//Defining Graph Structure

struct node
{
	//for nodes of adjacency list
    int vertex;
    struct node* next;
};

struct Graph
{
	//for adjacency list
    int num_of_Vertices;
    
    //strucutre to store address of another structure node
    struct node** adjLists;
    
    //just a array to denote visited nodes for DFS
    int* visited;

};

//Declaration of Function to be Used to Create a node for adjacency List
struct node* createNode(int v);

struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->num_of_Vertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));

  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL; //Initializing Empty Graph 
    graph->visited[i] = 0;     //Setting a variable Visited to 0 if not visited 
  }
  return graph;
}

void addEdge(struct Graph* graph, int source, int destination) {
  // Add edge from source to destination in which transportation is not banned 
  struct node* newNode = createNode(destination);
  newNode->next = graph->adjLists[source];
  graph->adjLists[source] = newNode;
}

int main() {
  struct Graph* graph = createGraph(4);
  addEdge(graph, 4, 1);
  addEdge(graph, 1, 2);
  addEdge(graph, 3, 1);
  addEdge(graph, 2, 3);

  printGraph(graph);
  
  return 0;
}
