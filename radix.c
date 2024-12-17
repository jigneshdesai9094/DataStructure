#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
    int data;
    struct node *next;
};
int maxValueDigit(int arr[],int size)
{
    int maxValue=0,i=0,count=0;
    while(i<size)
    {
        if(arr[i]>maxValue)
            maxValue=arr[i];
        i++;
    }
    while(maxValue>0)
    {
        count++;
        maxValue=maxValue/10;
    }
    return count;
}
struct node* createNode() -
{
    return (struct node*)malloc(sizeof(struct node));
}

void radix(int arr[],int size)
{
   struct node nodeArray[10],*newNode,*t;
   int i=0,mod,j=0,c=0,x=1;
   int maxDigitCount=maxValueDigit(arr,size);
   printf("\nMax value = %d",maxDigitCount);
   while(maxDigitCount!=c)
   {
    j=0;
   for(i=0;i<10;i++)
   {
        nodeArray[i].data=i;
        nodeArray[i].next=NULL;
   }
   for(i=0;i<size;i++)
   {
         mod=(arr[i]/x)%10;
         newNode=createNode();
         newNode->data=arr[i];
         newNode->next=NULL;
         t=&nodeArray[mod];
         while(t->next!=NULL)
               t=t->next;
         t->next=newNode;
   }
     printf("\n");
   for(i=0;i<10;i++)
   {
    t=&nodeArray[i];
    if(t->next!=NULL)
    {
      t=t->next;
       while(t!=NULL)
        {
            arr[j]=t->data;
            printf(" %d ",arr[j]);
            t=t->next;
            j++;
        }
    }
   }
   x=(x==0)?10:x*10;
   c++;
   }
}
void main()
{
    int arr[]={5000,500,50,5,12,56,34,90,78,900,67,890};
    int i=0;
    radix(arr,12);
    printf("\n");
    for(i=0;i<12;i++)
    {
        printf("%d ",arr[i]);
    }
}