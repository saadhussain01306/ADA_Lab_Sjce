#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int merge(int *arr,int low,int high,int mid,int size)
{
    int i,j,k,b[size],count=0;
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(arr[i]<arr[j])
        {
            b[k]=arr[i];
            i++;k++;count++;
        }
        else{
            b[k]=arr[j];
            j++;k++;count++;
        }
    }
    while(i<=mid)
    {
        b[k]=arr[i];
        k++;i++;
    }
    while(j<=high)
    {
        b[k]=arr[j];
        j++;
        k++;
    }
    for(int l=low;l<=high;l++)
    {
        arr[i]=b[i];
    }
    return count;
}
void mergesort(int *a,int low,int high,int size,int *c)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid,size,c);
        mergesort(a,mid+1,high,size,c);
        *(c)+=merge(a,low,high,mid,size);
    }
}
void worst(int *arr,int beg,int end)
{
    if(beg<end)
    {
        int mid=(beg+end)/2;
        int i,j,k;
        int n1=(mid-beg)+1;
        int n2=(end-mid);
        int a[n1],b[n2];
        for(i=0;i<n1;i++)
            a[i]=arr[(2*i)];
        for(j=0;j<n2;j++)
            b[j]=arr[(2*j)+1];
        worst(a,beg,mid);
        worst(b,mid+1,end);
        for(i=0;i<n1;i++)
        {
            arr[i]=a[i];
        }
        for(j=0;j<n2;j++)
        {
            arr[i+j]=b[j];
        }
    }
}
void main()
{
    srand(time(NULL));
    FILE *fptr=fopen("mergedata.txt","a");
    int i;
    int size=4,c=0;
    while(size<4097)
    {
        c=0;
        size*=2;
        fprintf(fptr,"%d\t",size);
        int *arr=malloc(sizeof(int)*size);
        // Best case
        for(i=0;i<size;i++)
        {
            arr[i]=i+1;
        }
        mergesort(arr,0,size-1,size,&c);
        fprintf(fptr,"%d\t",c);
        //Worst case
        c=0;
        worst(arr,0,size-1);
        mergesort(arr,0,size-1,size,&c);
        fprintf(fptr,"%d\n",c);
        free(arr);
    }
     fclose(fptr);
}
