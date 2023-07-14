//topological sorting

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 20

int q[MAX],front=0,rear=-1;
int dequeue(){
    return q[front++];
    }
void enqueue(int i){
   q[++rear]=i;
   printf("-->%c",i+65);
}  

int isempty(){
  if(front>rear)
    return -1;
   return 0;
 }
 
int indegree(int src,int n,int g[][MAX]){
  int ct=0;
  for(int k=0;k<n;k++){
    ct+=g[k][src];
  }
  return ct;
}  

void top(int n,int g[][MAX],int indeg[]){
   int count=0,i,j;
    for(i=0;i<n;i++){
         indeg[i]=indegree(i,n,g);
         if(indeg[i]==0)
           enqueue(i);
    }
    while(count<n){
       if(isempty()){
         printf("Cycle exist in the grapgh and is not a direct acyclic graph DAG\n");
         return;
    }
    int src=dequeue();
    
    for(int k=0;k<n;k++){
       if(g[src][k]==1){
         g[src][k]=0;
         indeg[k]--;
         if(indeg[k]==0)
             enqueue(k);
    }
    
}
count++;

}

}


void main(){
  int g[MAX][MAX],indeg[MAX];
  int i,j,n;
  printf("Enter the number of vertices in the graph\n");
  scanf("%d",&n);
  printf("Enter the adjacency matrix\n");
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
       scanf("%d",&g[i][j]);
       }
       indeg[i]=0;
       }
       top(n,g,indeg);
}

/*
Enter the number of vertices in the graph
5
Enter the adjacency matrix
0 0 1 1 0
1 0 0 1 0
0 0 0 0 1
0 0 1 0 1
0 0 0 0 0
-->B-->A-->D-->C-->E

*/

   

