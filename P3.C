#define max 10
int pre(char ch)
{
 if(ch=='*' || ch=='/')
    return 1;
 else
    return 0;
}
int push(char stack[],int top,char ch)
{
  if(top==9)
    printf("\nOverflow");
  else
  {
   top++;
   stack[top]=ch;
  }
  return top;
}
int pop(char stack[],int top)
{
  if(top==-1)
   printf("\nUnderflow");
  else
  {
    printf(" %c ",stack[top]);
    top--;
  }
  return top;
}
void converter(char in[],char stack[],int top)
{
  int i=0;
  while(in[i]!='\0')
  {
    if(in[i]=='+' || in[i]=='-' || in[i]=='*' || in[i]=='/')
    {
      if(top==-1)
	top=push(stack,top,in[i]);
      else
      {

	 while(pre(stack[top])>=pre(in[i]) && top!=-1)
	   top=pop(stack,top);

	top=push(stack,top,in[i]);

      }
    }
    else
    {
      printf(" %c ",in[i]);
    }
    i++;
  }
  while(top!=-1)
  {
   top=pop(stack,top);
  }
}
void main()
{
 char stack[10],in[50];
 int top=-1;
 clrscr();
 printf("\nEnter Your Infix");
 scanf("%s",in);
 converter(in,stack,top);
 getch();
}