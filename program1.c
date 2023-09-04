#include<stdio.h>
void insert(int* arr,int start,int end)
{
    int val = arr[end];
    int j=end-1;
    while(j >= start && arr[j] > val)
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = val;
}
void ModifiedBinarySearch(int* arr,int start,int end,int index)
{
    if(start <= end)
    {
        int mid = (start + end)/2;
        
        if(mid == 0 && arr[mid] > arr[index])
        {
            insert(arr,mid,index);
            return ;
        }
        else if(arr[index] < arr[mid] && arr[index] > arr[mid-1])
        {
            insert(arr,mid,index);
            return;
        }
        else if(arr[end+1] > arr[mid])
            return ModifiedBinarySearch(arr,mid+1,end,index);
        else
            return ModifiedBinarySearch(arr,start,mid-1,index);
    }
}


void main()
{
    int arr[11];
    int size;
    printf("Enter size:");
    scanf("%d",&size);

    printf("Enter array elements:");

    for(int i=0;i<size;i++)
        scanf("%d",&arr[i]);

    printf("Enter value to be inserted: ");
    scanf("%d",&arr[size]) ;

    ModifiedBinarySearch(arr,0,size-1,size);

    for(int i=0;i<=size;i++)
        printf("%d ",arr[i]);
}