#include<stdio.h>
void swap(int* a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int arr[],int low,int high)
{
    int pivot = arr[high];
    int i = low-1;
    for(int j=low;j<high;j++)
    {
        if(arr[j] <= pivot)
        {
            ++i;
            swap(&arr[j],&arr[i]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

void QuickSort(int arr[],int low,int high)
{
    if(low < high)
    {
        int q1 = Partition(arr,low,high);
        int q2 = Partition(arr,low,high);
        int min = (q1 > q2) ? q2 : q1;
        int max = (q1 < q2) ? q2 : q1;
        QuickSort(arr,low,min-1);
        QuickSort(arr,min+1,max-1);
        QuickSort(arr,min+1,high);
    }
}

void main()
{
    int size;
    printf("Enter size: ");
    scanf("%d",&size);

    int arr[size];
    for(int i=0;i<size;i++)
        scanf("%d",&arr[i]);
    
    QuickSort(arr,0,size-1);

    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}