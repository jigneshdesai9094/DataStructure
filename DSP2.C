#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int push(int [],int);
int pop(int [],int);
void show(int [],int);
void modify(int [],int);
int simple_Search(int [],int,int);
int peep(int [],int);
int main()
{
    int choice;
    int top = -1,stack[SIZE],ele;
    clrscr();
    while (1)
    {
	printf("\nPerform operations on the stack:");
	printf("\n1.Push the element\n2.Pop the element\n3.Peep the Element\n4.Modify\n5.Display\n6.End");
	printf("\n\nEnter the choice: ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
	    top=push(stack,top);
	    break;
	case 2:
	    top=pop(stack,top);
	    break;
	case 3:
	       ele=peep(stack,top);
	       if(ele!=-1)
		 printf("\nTop Of Element is %d",ele);
	       else
		 printf("\nStack is Empty");
	       break;
	case 4:
	       modify(stack,top);
	       break;
	case 5:
	    show(stack,top);
	    break;
	case 6:
	    exit(0);
	default:
	    printf("\nInvalid choice!!");
	}
    }
}
int push(int stack[],int top)
{
    int x;
    if (top == SIZE - 1)
    {
	printf("\nOverflow!!");
    }
    else
    {
	printf("\nEnter the element to be added into the stack: ");
	scanf("%d", &x);
	top = top + 1;
	stack[top] = x;
    }
    return top;
}
int pop(int stack[],int top)
{
    if (top == -1)
    {
	printf("\nUnderflow!!");
    }
    else
    {
	printf("\nPopped element: %d", stack[top]);
	top = top - 1;
    }
    return top;
}
void modify(int arr[],int t)
{
  int ind,ne,pe;
   printf("\nEnter Previous and New element both,previous element replce to new element\n");
   scanf("%d%d",&pe,&ne);
   ind=simple_Search(arr,t,pe);
   if(ind!=-1)
     arr[ind]=ne;
   else
     printf("\nElement is not present in array");

}
int simple_Search(int arr[],int t,int ele)
{
 int i,j=-1;
   for(i=0;i<=t;i++)
   {
    if(arr[i]==ele)
      { j=i;
	break;
      }
   }
   if(i==t+1)
      j=-1;
 return j;
}
int peep(int stack[],int top)
{
  if(top==-1)
    return top;
  else
   return stack[top];
}
void show(int stack[],int top)
{
    int i;
    if (top == -1)
    {
	printf("\nUnderflow!!");
    }
    else
    {
	printf("\nElements present in the stack: \n");
	for (i = top; i >= 0; --i)
	    printf("%d\n", stack[i]);
    }
}  