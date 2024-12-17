void swapParent(int head[],int curr,char p)
{
    int c,t;
     if(p=='l')
        c=curr*2+1;
     else
        c=curr*2+2;
     while(c>0)
        {
            printf("\n curr= %d and child = %d",head[curr],head[c]);
            if(head[curr]<head[c])
            {
                  t=head[curr];
                  head[curr]=head[c];
                  head[c]=t;
            }
            c=curr;
            curr=(curr-1)/2; 
        }
}
void createHeap(int arr[],int start,int end,int heap[])
{
    int i;
    int curr=0,child=0;
    char p;
    heap[0]=arr[start];
    for(i=start+1;i<=end;i++)
    {
        if(child==2)
        {
            curr++;
            child=0;
        }
        if(i%2!=0)
        {
            heap[curr*2+1]=arr[i];
            p='l';
            child++;
        }
        else
        {
            heap[curr*2+2]=arr[i];
            p='r';
            child++;
        }
       if(heap[curr]<arr[i])
       {
         swapParent(heap,curr,p);
       }

    }

}
void heapSort(int arr[],int size)
{
   int i=0,t,j;
   int heap[5];
   for(i=4;i>0;i--)
   {
        createHeap(arr,0,i,heap);
        t=heap[0];
        heap[0]=heap[i];
        heap[i]=t;
           printf("\nafter\n");
    for(j=0;j<=4;j++)
    {
        arr[j]=heap[j];
        printf(" %d ",heap[j]);
    }
   }
    
}
void main()
{
    int arr[]={25,11,33,10,42};
    int i;
    heapSort(arr,5);
}