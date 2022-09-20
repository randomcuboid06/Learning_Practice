#include<stdio.h>
#include<stdlib.h>

void mergesort(int a[], int l, int h)
{
    if(l<h)
    {
        int m = (l+h)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,h);
        merge(a,l,m,h);
    }
}

void merge(int a[], int l, int m, int h)
{
    int b[20],i,j,k;
    i=l;
    j=m+1;
    k=l;
    while(k<=m &&j<=h)
    {
        if(a[k]<=a[j])
        {
            b[i]=a[k];
            k++;
        }
        else
        {
            b[i]=a[j];
            j++;
        }
        i++;
    }
    if(k>m)
    {
        for(;j<=h;j++,i++)
        {
            b[i]=a[j];
        }
    }
    else
    {
        for(;k<=m;k++,i++)
        {
            b[i]=a[k];
        }
    }
    for(i=l;i<=h;i++)
    {
        a[i]=b[i];
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
    mergesort(a,0,n-1);
    printf("\nArray after sorting: \n");
    printarray(a,n);
    return(0);
}
