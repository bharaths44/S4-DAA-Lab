// Prim's Algorithm in C

#include<stdio.h>
#include<stdbool.h> 
#include<string.h>
#define INF 9999999

// number of vertices in graph

void main() {
  int V;
  printf("Enter number of edges :");
  scanf("%d",&V);
  int G[V][V];
  for(int i=0;i<V;i++) {
  	printf("Enter the values in the row %d :",i+1);
  	for(int j=0;j<V;j++)
  			scanf("%d",&G[i][j]);
  }
  	
  int selected[V];

  // set selected false initially
for(int i=0;i<V;i++)
{
  selected[i]=false;
}
  selected[0] = true;

  int x,y,total_cost=0;  //  row number , col number
  char a=65;
  char b=65;
  // print for edge and weight
  printf("Edge : Weight\n");

  for (int no_edge=0;no_edge < V - 1;no_edge++) {
    //For every vertex in the set S, find the all adjacent vertices
    // , calculate the distance from the vertex selected at step 1.
    // if the vertex is already in the set S, discard it otherwise
    //choose another vertex nearest to selected vertex  at step 1.

    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) {  // not in selected and there is an edge
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    total_cost+=G[x][y];
    printf("%c - %c : %d\n", a+x, b+y, G[x][y]);
    selected[y] = true;
  }
  printf("Total Cost : %d\n",total_cost);

}
