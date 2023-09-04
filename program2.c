#include<stdio.h>
#include<stdlib.h>
void swap(int* a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int* arr,int low,int high)
{
    for(int i=low;i<=high;i++)
    {
        for(int j=low;j<=high-i-1;j++)
        {
            if(arr[j] > arr[j+1])
                swap(&arr[j],&arr[j+1]);        
        }
    }
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

void ModifiedQuickSort(int arr[],int low,int high)
{
    
    if(low < high)
    {
        
        int q = Partition(arr,low,high);
        if(high - low <= 30)
        {
            BubbleSort(arr,low,q-1);
             BubbleSort(arr,q+1,high);
            return;
        }
        else{
             ModifiedQuickSort(arr,low,q-1);
        ModifiedQuickSort(arr,q+1,high);
        }
        
    }
}
void main()
{
    int arr[2000];
    // for(int i=0;i<20;i++)
    // {
    //     arr[i] = rand();
    // }

    for(int i=0;i<200;i++)
    {
        arr[i] = 2000-i;
    }

    for(int i=200;i<1000;i++)
    {
        arr[i] = i+1;
    }

    for(int i=1000;i<2000;i++)
    {
        arr[i] = i+123;
    }

    ModifiedQuickSort(arr,0,1999);

    for(int i=0;i<2000;i++)
        printf("%d ",arr[i]);
}