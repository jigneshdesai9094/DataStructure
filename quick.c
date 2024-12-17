void quick(int arr[],int start,int end)
{
    int left=start,right=end,pivot=start;
    int t,i;
    while (left<right)
    {
     while(arr[pivot]<arr[right])
        right--;
     t=arr[pivot];
     arr[pivot]=arr[right];
     arr[right]=t;
     pivot=right;

     while(arr[left]<arr[pivot])
         left++;
     t=arr[pivot];
     arr[pivot]=arr[left];
     arr[left]=t;
     pivot=left;
    }
    if(start<pivot-1)
     quick(arr,start,pivot-1);
    if(pivot+1<end)
    quick(arr,pivot+1,end);
}
void main()
{
    int arr[]={55,100,20,90,80,70,10,50,60,110};
    int i=0;
    quick(arr,0,9);
    for(i=0;i<10;i++)
    {
        printf(" %d ",arr[i]);
    }
}