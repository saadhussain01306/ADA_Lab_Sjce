//warshall algorithm
#include<stdio.h>
#define MAX 20

int g[MAX][MAX];
int count=0;


int warshall(int n){
  int i,j,k;
  for(k=1;k<=n;k++){
      for(i=1;i<=n;i++){
       	 if(g[i][k]==1)
   	   for(j=1;j<=n;j++){
      	     g[i][j]=(g[i][j] || g[k][j]);
      	     count=count+1;
      			}
      			
             }
     }
     return count;
     
  }

void main(){
int i,j,n;
printf("Enter the number of vertices:\n");
scanf("%d",&n);
printf("Enter the adjacency matrix \n");

for(i=1;i<=n;i++){
   for(j=1;j<=n;j++){
   scanf("%d",&g[i][j]);
  }
 }

 int x=warshall(n);
  printf("Transitive closure of the matrix is:\n");
   for(i=1;i<=n;i++){
     for(j=1;j<=n;j++){
      printf("%d\t",g[i][j]);
     }
     printf("\n");
    }
    printf("The count of the %d vertices matrix is %d\n",n,x);
    
   
    
  }
  
 /* Enter the number of vertices:
4
Enter the adjacency matrix 
0 1 0 0
0 0 0 1
0 0 0 0
1 0 1 0
Transitive closure of the matrix is:
1	1	1	1	
1	1	1	1	
0	0	0	0	
1	1	1	1	
The count of the 4 vertices matrix is 28
*/

 
  
 

  
  
  

