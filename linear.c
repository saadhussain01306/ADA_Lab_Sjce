//linear search algorithm
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int linear(int n,int *arr,int key){
  int count=0;
  for(int i=0;i<n;i++){
     count++;
     if(arr[i]==key)
        return count;
        
    }
    return count;
  }
  
void main(){
   srand(time(NULL));
   int x,size=1,i;
   FILE *fptr=fopen("linear.dat","a");  
   while(size<=40000){
     if(size<=10000) size*=10;
     else size*=2;
     fprintf(fptr,"%d\t",size);
     int *arr=(int *)malloc(size*(sizeof(int)));
     for(i=0;i<size;i++) arr[i]=rand();
     
     //best case
     x=linear(size,arr,arr[0]);
     fprintf(fptr,"%d\t",x);
     
     //worst case
     x=linear(size,arr,arr[size-1]);
     fprintf(fptr,"%d\n",x);
   
   }
   fclose(fptr);
 
}      
