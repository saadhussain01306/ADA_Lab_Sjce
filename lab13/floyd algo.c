// Floyd's Algorithm
#include<stdio.h>
#define MAX 20

int w[MAX][MAX];
int count=0;
int minimum(int p,int q){
  int min;
  min=(p>q)? q : p;
  return min;
  }
  
  int floyd(int n){
  int i,j,k,T;
  for(k=1;k<=n;k++){
    for(i=1;i<=n;i++){
         T=w[i][k];
      for(j=1;j<=n;j++){
         if(w[i][j]>T){
             w[i][j]=minimum(w[i][j],(T+w[k][j]));
             count=count+1;
            }
       }  
     }
   }
   return count;
}

void main(){
  int i,j,n;
  printf("Enter the number of vertices\n");
  scanf("%d",&n);
  printf("Enter 999 to represent infinity\n");
  printf("Enter the weight matrix\n");
  
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      scanf("%d",&w[i][j]);
    }
  }   
  
  int x=floyd(n);
  
  printf("\nAll pair shortest pair matrix is :\n");
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
       printf("%d\t",w[i][j]);
       }
       printf("\n");
       }
   printf("the count of given %d vertices matrix is %d\n",n,x);
}

/*
output:-
Enter the number of vertices
4
Enter 999 to represent infinity
Enter the weight matrix
0
999
3
999
2
0
999
999
999
7
0
1
6
999
999
0

All pair shortest pair matrix is :
0	10	3	4	
2	0	5	6	
7	7	0	1	
6	16	9	0	
the count of given 4 vertices matrix is 24

*/



