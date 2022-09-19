#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low-1;
    int j;
    for(j = low;j < high;j++)
    {
        if(a[j] <= pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return(i+1);
}

void quicksort(int a[], int low, int high)
{
    if(low<high)
    {
        int pi = partition(a,low,high);
        quicksort(a,low,pi-1);
        quicksort(a,pi+1,high);
    }
}

void printarray(int a[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("\nHow many elements do you want in your array? : ");
    scanf("%d",&n);
    int a[n],i;
    printf("\nEnter the elements of your array : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Array before sorting: \n");
    printarray(a,n);
    quicksort(a,0,n-1);
    printf("\nArray after sorting: \n");
    printarray(a,n);
    return(0);
}

