//knapsack problem 


#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
 int max;
 max=(a>b)?a:b;
 return max;
  
 }
 
 void composition(int n,int wt,int weight[],int knap[][wt+1]){
    int num=0;
    int subset[n];
    int rc=wt;
    for(int i=n;i>=1;i--){
    if(knap[i][rc]!=knap[i-1][rc]){
        subset[num++]=i;
        rc-=weight[i-1];
        }
        if(rc==0){
        break;
        }  
    } 
        printf("The composition is\n");
        for(int i=0;i<num;i++){
         printf("%d\t",subset[i]);
         
         
         }  
         
  }       
         
 

void knapsack(int n,int wt,int weight[],int value[]){
  int i,j,k;
  int knap[n+1][wt+1];
  for(i=0;i<=n;i++){
     for(j=0;j<=wt;j++){
       if(j==0 || i==0){
          knap[i][j]=0;
        }
        else if(j<weight[i-1]){
          knap[i][j]=knap[i-1][j];
          }
          else{
            knap[i][j]=max(value[i-1]+(knap[i-1][j-weight[i-1]]),knap[i-1][j]);
          }
          printf("%d\t",knap[i][j]);
          }
          printf("\n");
                 
}
printf("The optimisation knapsack value is %d\n",knap[n][wt]);
composition(n,wt,weight,knap);

}

void main(){
 int wt,i,j,n,capacity,*weight,*value;
 printf("Enter the number of items\n");
 scanf("%d",&n);
 value=(int*)malloc(n*sizeof(int));
 weight=(int*)malloc(n*sizeof(int));
 printf("Enter the capacity\n");
 scanf("%d",&capacity);
 printf("Enter the weights and values respectively\n");
 printf("Weight || Value\n");
 for(i=0;i<n;i++){
    
       scanf("%d%d",&weight[i],&value[i]);
       
       
       }
       knapsack(n,capacity,weight,value);
 }
       
/*
output:-
Enter the number of items
4
Enter the capacity
5
Enter the weights and values respectively
Weight || Value
2 12
1 10
3 20
2 15
0	0	0	0	0	0	
0	0	12	12	12	12	
0	10	12	22	22	22	
0	10	12	22	30	32	
0	10	15	25	30	37	
The optimisation knapsack value is 37
The composition is
4 2 1   
*/
       
