#define max 5
void insert(int q[],int *r,int *f)
{
 int ele;
 if((*r==max-1&&*f==0)||*r==*f-1)
 {
  printf("\nQueue is Full");
 }
 else
 {
  printf("\nEnter new Element");
  scanf("%d",&ele);
  if(*r==max-1)
  {
   *r=-1;
  }
  *r+=1;
  q[*r]=ele;
  if(*r==0 && *f==-1)
    *f=0;
 }
}
void del(int q[],int *r,int *f)
{
 if(*f==-1)
   printf("\nQueue is Empty");
 else
 {
  printf("Remove : %d",q[*f]);
  q[*f]=0;
  if(*f==max-1 && *r<*f)
   *f=0;
  else if(*f==*r)
  {
   *f=-1;*r=-1;
  }
  else
   *f+=1;
 }
}
void display(int q[],int *r,int *f)
{
 int i=0;
 printf("\n");
 if(*f==-1)
 {
  printf("\nQueue is empty");
 }
 else
 {
  for(i=*f;i<max;i++)
  {
   printf(" %d ",q[i]);
 //  printf(" i=%d r=%d",i,*r);

  if(i==max-1 && *r<*f)
     i=-1;
   if(i==*r)
     break;
  }
 }
}
void main()
{
 int q[max],r1=-1,f1=-1,*r=&r1,*f=&f1;
 int choice;
 clrscr();
 while(1)
 {
  printf("\n1.insert");
  printf("\n2.delete");
  printf("\n3.display");
  printf("\n4.end");
  printf("\nenter your choice");
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

 getch();

}