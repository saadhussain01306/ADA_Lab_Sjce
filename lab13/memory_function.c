//memory function to implemnt knapsac


#include<stdio.h>
#define MAX 20
int weight[MAX],value[MAX],knap[MAX][MAX];


int maximum(int a,int b){
  int max=(a>b)?a:b;
  return max;
  }
  
int knapsac(int i,int j){
     int v=0;
     if(knap[i][j]==-1){
        if(j<weight[i]){
           v=knapsac(i-1,j);
           }
        else{
           v=maximum(knapsac(i-1,j),(value[i-1]+knapsac(i-1,j-weight[i-1])));
          
        }
        knap[i][j]=v;   
     
     }
     return knap[i][j];
}  

void composition(int wt,int n,int weight[]){
   int i,j;
   int set[n];
   int num=0;
   int rc=wt;
   for(i=n;i>=1;i--){
   if(knap[i][rc]!=knap[i-1][rc]){
       set[num++]=i;
       rc-=weight[i-1];
       }
       if(rc==0){
       break;
       }
  }
  printf("The composition set is \n");
  for(int i=0;i<num;i++){
       printf("%d\t",set[i]);
       }
     printf("\n");  
  
}
  

void main(){
  int i,j,k,n,cap;
  printf("Enter the number of items\n");
  scanf("%d",&n);
  printf("Enter the capacity\n");
  scanf("%d",&cap);
  printf("Enter the weights and values\n");
  for(i=0;i<n;i++){
    scanf("%d%d",&weight[i],&value[i]);
    }
  for(i=0;i<=n;i++){
    for(j=0;j<=cap;j++){
        if(j==0 || i==0){
           knap[i][j]=0;
           }
          else{
             knap[i][j]=-1;
             }
         }
      }
    int x=knapsac(n,cap);
    printf("The optimised knapsac value is %d\n",x);
    composition(cap,n,weight);
    
    } 
    
    
    /*output
    Enter the number of items
4
Enter the capacity
5
Enter the weights and values
2 12
1 10
3 20
2 15
The optimised knapsac value is 37
The composition set is 
4	2	1
*/    
