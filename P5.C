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
 clrscr();
 while(1)
 {
  printf("\n1.insert");
  printf("\n2.delete");
  printf("\n3.dipslay");
  printf("\n4.end");
  printf("\nEnter your choice");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:insert(q,r,f);
	    break;
    case 2:del(q,r,f);
	   break;
    case 3:display(q,r,f);
	  break;
    case 4:exit(0);
    default:printf("\nPlease,enter valid choice");
  }
 }

}