#include<stdio.h>
#include<stdlib.h>

void merge(int *a,int size_a,int *b,int size_b,int *c)
{
    int i,j,k;
    for(i=0,j=0,k=0;i<size_a && j<size_b;k++)
    {
        if(a[i]<=b[j])
        {
            c[k]=a[i];
            i++;
        }
        else if(b[j]<a[i])
        {
            c[k]=b[j];
            j++;
        }
    }

    if(i>=size_a)
    {
        for(;j<size_b;j++,k++)
            c[k]=b[j];
    }
    else if(j>=size_b)
    {
        for(;i<size_a;i++,k++)
            c[k]=a[i];
    }
}

void mergesort(int *arr,int n)
{
    if(n==1)
        return;

    int *arr1=(int *)malloc(10000*sizeof(int));
    int *arr2=(int *)malloc(10000*sizeof(int));

    for(int i=0;i<n/2;i++)
        arr1[i]=arr[i];
    for(int i=n/2;i<n;i++)
        arr2[i-n/2]=arr[i];

    int x=(n%2==0)?(n/2):(n/2+1);
    mergesort(arr1,n/2);
    mergesort(arr2,x);
    merge(arr1,n/2,arr2,x,arr);
}

int main()
{
    int *a=(int *)malloc(100000*sizeof(int));
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    mergesort(a,n);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}