#define max 5
void insert(int q[],int *f,int *r,char s[])
{
 int ele,i;
 if(strcmp(s,"IR")==0 && *r==max-1)
   printf("\nInsert Rear End Queue is full");
 else if(strcmp(s,"IF")==0 && (*f==0||*f==-1))
   printf("\nInsert Front End Queue is full");
 else
 {
   if(strcmp(s,"IR")==0)
   {
   *r=*r+1;
   if(*r==0)
     *f=0;
   i=*r;
   }
   else
   {
    *f=*f-1;
    i=*f;
    }
   printf("\nEnter New Element");
   scanf("%d",&ele);
   q[i]=ele;
 }
}
void del(int q[],int *f,int *r,char s[])
{
  int ele;
  if(*f==-1 && *r==-1)
    printf("\nBoth End Queue is empty");
  else
  {
    if(strcmp(s,"DR")==0)
    {
     ele=q[*r];
     if(*r==*f)
     { *r=-1;*f=-1;}
     else
     *r=*r-1;
    }
    else
    {
    ele=q[*f];
    if(*f==*r)
    {
     *f=-1;
     *r=-1;
    }
    else
    *f=*f+1;
    }
    printf("\nRemoved Element is %d ",ele);
  }
}
void display(int q[],int *f,int *r)
{
 int i;
 if(!(*f==-1 && *r==-1))
 {
  printf("\nElements : ");
  for(i=*f;i<=*r;i++)
  {
   printf("%d ",q[i]);
  }
 }
}
void main()
{
 int q[max],r1=-1,f1=-1,*f=&f1,*r=&r1,choice;
 clrscr();
 while(1)
 {
  printf("\n1.Insert Rear");
  printf("\n2.Insert Front");
  printf("\n3.Delete Rear");
  printf("\n4.Delete Front");
  printf("\n5.exit");
  printf("\nEnter your choice");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:insert(q,f,r,"IR");
	  printf("\nRear : %d Front : %d",*r,*f);
	  display(q,f,r);
	  break;
   case 2:insert(q,f,r,"IF");
	  printf("\nRear : %d  Front : %d",*r,*f);
	  display(q,f,r);
	  break;
   case 3:del(q,f,r,"DR");
	  printf("\nRear : %d Front : %d",*r,*f);
	  display(q,f,r);
	  break;
   case 4:del(q,f,r,"DF");
	  printf("\nRear : %d Front : %d",*r,*f);
	  display(q,f,r);
	  break;
   case 5:exit(0);
	 break;
   default:printf("\nplease,enter valid choice");
  }
 }
}