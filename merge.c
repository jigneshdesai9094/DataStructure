void sort(int arr[],int start,int mid,int end)
{
    int lf=start,rf=mid+1;
    int sArr[10],k=0,i,l=0;
    while(lf<=mid && rf<=end)
    {
           if(arr[lf]<arr[rf])
            {
                sArr[k]=arr[lf];
                lf++;
            }
            else
            {
                sArr[k]=arr[rf];
                rf++;
            }
            k++;
    }
    if(lf<=mid)
    {
        while(lf<=mid)
        {
            sArr[k]=arr[lf];
            lf++;
            k++;
        }
    }
    else
    {
        while(rf<=end)
        {
            sArr[k]=arr[rf];
            rf++;
            k++;
        }
    }
    for(i=start;i<=end;i++)
    {
        if(l<=k)
        {
         arr[i]=sArr[l];
         l++;
        }
    }
    printf("\n");
    for(i=0;i<10;i++)
    {
        printf(" %d ",arr[i]);
    }
}
void merge(int arr[],int start,int end)
{
    int mid;
    if(start<end)
    {
        mid=(start+end)/2;
        merge(arr,start,mid);
        merge(arr,mid+1,end);
        sort(arr,start,mid,end);
    }
//     int i,j,k;
//     for(i=2;i<size;i*=2)
//     {
//           for(j=0;j<=size-i;j+=i)
//           {
//               sort(arr,j,(j+i/2-1),j+i-1);
//           }
//    } 
//    sort(arr,0,size/2-1,9);
}
void main()
{
     int arr[]={55,100,20,90,80,70,10,50,110,60};
     int i;
         printf("\n");
    for(i=0;i<10;i++)
    {
        printf(" %d ",arr[i]);
    }
    merge(arr,0,9);
    
}