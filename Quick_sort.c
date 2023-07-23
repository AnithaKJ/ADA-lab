#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
int partition(int a[],int low,int high)
{
    int key,i,j,temp;
    key=a[low];
    i=low+1;
    j=high;
    while(1)
    {
        while(i<high && key>=a[i])
            i++;
        while(key<a[j])
            j--;
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        else
        {
            temp=a[low];
            a[low]=a[j];
            a[j]=temp;
            return j;
        }
    }
}
void quicksort(int a[],int low,int high)
{
    int j;
    if(low<high)
    {
        j=partition(a,low,high);
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
    }
}
void main()
{
    int a[10000],n,t,i;
    clock_t end,start;
    printf("Enter the number of array elements:\n");
    scanf("%d",&n);
    printf("Enter the array elements:\n");
    for(i=0;i<n;i++)
    {
      a[i]=rand()%1000;
      printf("%d\n",a[i]);
    }
    start=clock();
    for(int j=0;j<5000000;j++)
        t=900/900;
    quicksort(a,0,n-1);
     end=clock();
    printf("Sorted array:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
     printf("Time taken to search an given element in an array of is %f\n",(((double)(end-start))/CLOCKS_PER_SEC));
}
