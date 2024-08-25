#include<stdio.h>
#include<stdlib.h>
#define max 5
void insert(int q[],int *r,int *f)
{
 int ele;
 if(*r==max-1)
   printf("\nQueue is full");
 else
 {
  printf("\nEnter New Element");
  scanf("%d",&ele);
  *r+=1;
  q[*r]=ele;
  if(*r==0)
   *f=0;
 }
}
void  del(int q[],int *r,int *f)
{
 if(*f==-1)
  printf("\nQueue if Empty");
 else
 {
  printf("\nRemove : %d",q[*f]);
    if(*f==*r)
    {
     *f=-1;*r=-1 ;
    }
    else
    {
    *f+=1;
    }
 }
}
int simple_Search(int arr[],int f,int r,int ele)
{
 int i,j=-1;
   for(i=f;i<=r;i++)
   {
    if(arr[i]==ele)
      { j=i;
	break;
      }
   }
   if(i==r+1)
      j=-1;
 return j;
}
void modify(int arr[],int f,int r)
{
  int ind,ne,pe;
   printf("\nEnter Previous and New element both,previous element replce to new element\n");
   scanf("%d%d",&pe,&ne);
   ind=simple_Search(arr,f,r,pe);
   if(ind!=-1)
     arr[ind]=ne;
   else
     printf("\nElement is not present in array");

}

void display(int q[],int *r,int *f)
{
  int i=0;
  printf("\n");
  if(*f==-1)
   printf("\nQueue is empty");
  else
  {
    for(i=*f;i<=*r;i++)
   {
    printf(" %d ",q[i]);
   }
  }
}
void main()
{
 int q[max],r1=-1,f1=-1,*f=&f1,*r=&r1;
 int choice;
// clrscr();
 while(1)
 {
  printf("\n1.insert");
  printf("\n2.delete");
  printf("\n3.modify");
  printf("\n4.dipslay");
  printf("\n5.end");
  printf("\nEnter your choice");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:insert(q,r,f);
	    break;
    case 2:del(q,r,f);
	   break;
	case 3:modify(q,*f,*r);
	     break;
    case 4:display(q,r,f);
	  break;
    case 5:exit(0);
    default:printf("\nPlease,enter valid choice");
  }
 }

}
