#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
 int data;
 struct node *left,*down;
};
void linkForwad(struct node *rp,struct node *rn,struct node *row)
{
  struct node *t1=row,*temp=row;

 if(rp!=NULL)
	{
	while(rp->left!=NULL)
	    {
	    (rp->left)->down=temp;
	    printf("\n upper Node : %d",(rp->left)->data);
	    temp=temp->left;
	    rp=rp->left;
	    }
	}
	temp=t1;
	if(rn!=NULL)
	{
	if(rn->left==NULL)
	     temp->down=NULL;
	   else
	   {
	    while(rn->left!=NULL)
	    {
	      temp->down=rn->left;
	       printf("\n under Node : %d",(rn->left)->data);
	      temp=temp->left;
	      rn=rn->left;
	    }
	    if(temp!=NULL)
		temp->down=NULL;
	   }
	 }
}
struct node* insert(struct node *head,int r,int c,int d)
{
 struct node *temp,*pre,*row,*rp,*rn,*t1,*n=(struct node*)malloc(sizeof(struct node));
 int t=0;
 n->data=d;
 n->left=NULL;
 n->down=NULL;
 if(head==NULL)
    head=n;
 else
 {
   row=NULL;
   rp=NULL;
   rn=NULL;
   temp=head;
   while(t!=r && temp!=NULL)
   {
     pre=temp;
     temp=temp->down;
     t++;
   }
   if(temp==NULL)
      pre->down=n;
   else
   {
     if(r!=0)
	rp=pre;
     row=temp;
     if(row->down!=NULL)
	rn=row->down;
   }
   if(row!=NULL)
   {
     t=0;
     temp=row;
     while(t!=c && temp!=NULL)
     {
       pre=temp;
       temp=temp->left;
       if(rp!=NULL)
	rp=rp->left;
       if(rn!=NULL)
	rn=rn->left;
       t++;
     }
     if(temp==NULL)
      {
	if(rp!=NULL)
	{
	 rp->down=n;
	 printf("\nupper node: %d ",rp->data);
	}
	pre->left=n;
	if(rn!=NULL)
	{
	  printf("\nlower node: %d ",rn->data);
	  n->down=n;
	}
      }
     else if(c==0)
     {
	if(r==0)
	   head=n;
	if(rp!=NULL)
	  rp->down=n;
	n->down=rn;
	n->left=row;
	linkForwad(rp,rn,row);
     }
     else
     {

	n->left=temp;
	linkForwad(rp,rn,temp);
	pre->left=n;
     }
   }
 }
 return head;
}
void display(struct node *head)
{
   struct node *temp,*row=head;
   printf("\n");
   while(row!=NULL)
   {
     temp=row;
     while(temp!=NULL)
     {
       printf(" %d ",temp->data);
       temp=temp->left;
     }
     printf("\n");
     row=row->down;
   }
}
void main()
{
  struct node *head=NULL;
  int choice,r,c,d;
  clrscr();
  while(1)
  {
    printf("\n1.insert");
    printf("\n2.exit");
    printf("\nenter your choice");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:printf("\nEnter row,column and data");
	     scanf("%d%d%d",&r,&c,&d);
	     head=insert(head,r,c,d);
	     display(head);
	     break;
     case 2:exit(0);
     default:printf("\nplease,enter valid choice");
    }
  }
}