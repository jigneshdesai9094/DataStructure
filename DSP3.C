#define max 10

void push(int stack[],int *top1,int *top2,char s[])
{
  int ele,t;
  if(*top1==(*top2-1))
  {
    printf("\nStack is Overflow");
  }
  else
  {
    printf("\nEnter new Element");
    scanf("%d",&ele);
    if(strcmp(s,"stack1")==0)
      t=++*top1;
    else
      t=--*top2;
    stack[t]=ele;
  }
}
void pop(int stack[],int *tp,char s[])
{
 int t=-2;

   if(strcmp(s,"stack1")==0)
   {
      t=*tp;
      *tp=*tp-1;
   }
   else
   {
       t=*tp;
       *tp=*tp+1;
   }
   if(t!=-2)
    printf("\nPop Element is %d",stack[t]);

}
void modify(int stack[],int *tp,char s[])
{
  int ind,pre,ne;
  printf("\nEnter Previous and New element both,previous element replce to new element\n");
  scanf("%d%d",&pre,&ne);
  if(strcmp(s,"stack1")==0)
   ind=simple_Search(stack,*tp,pre,0);
  else
   ind=simple_Search(stack,max,pre,*tp);
  if(ind!=-1)
     stack[ind]=ne;
   else
    printf("\nPrevious Element is not in %s",s);
}
int simple_Search(int arr[],int t,int ele,int start)
{
 int i,j=-1;
   for(i=start;i<=t;i++)
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
void peep(int stack[],int *t)
{
    printf("\n Top Element is %d",stack[*t]);

}
void display(int stack[],int *t,char s[])
{
 int i;
 printf("\nElements : ");
 if(strcmp(s,"stack2")==0)
 {
  for(i=*t;i<max;i++)
   printf("%d ",stack[i]);
 }
 else
 {
   for(i=*t;i>=0;i--)
    printf("%d ",stack[i]);
 }

}
void main()
{
 int stack[max],t1=-1,t2=max,*top1=&t1,*top2=&t2,choice;
 clrscr();
 do
 {
  printf("\n1.Push stack1");
  printf("\n2.Push stack2");
  printf("\n3.Pop stack1");
  printf("\n4.Pop stack2");
  printf("\n5.Peep stack1");
  printf("\n6.Peep stack2");
  printf("\n7.Modify stack1");
  printf("\n8.Modify stack2");
  printf("\n9.Display stack1");
  printf("\n10.Display stack2");
  printf("\n11.exit");

  printf("\nEnter Your Choice");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:push(stack,top1,top2,"stack1");
	  break;
   case 2:push(stack,top1,top2,"stack2");
	  break;
   case 3:if(*top1==-1)
	    printf("\nStack1 is Underflow");
	  else
	    pop(stack,top1,"stack1");
	  break;
   case 4:if(*top2==max)
	    printf("\nStack2 is Underflow");
	  else
	   pop(stack,top2,"stack2");
	  break;
   case 5:if(*top1==-1)
	    printf("\nStack1 is Underflow");
	  else
	   peep(stack,top1);
	  break;
   case 6:if(*top2==max)
	     printf("\nStack2 is Underflow");
	  else
	    peep(stack,top2);
	  break;
   case 7:modify(stack,top1,"stack1");
	  break;
   case 8:modify(stack,top2,"stack2");
	  break;
   case 9:display(stack,top1,"stack1");
	  break;
   case 10:display(stack,top2,"stack2");
	  break;
   default:printf("\nPlease,enter valid choice");
  }
 }while(choice!=11);
}