#include<stdio.h>
#include<conio.h>
struct node
{
 int data;
 struct node *next;
};
struct node* in_sort(struct node *head,int ele)
{
 struct node *n = (struct node*)malloc(sizeof(struct node));
 struct node *temp,*s;
 n->data=ele;
 if(head==NULL)
 {
   n->next=NULL;
   head=n;
 }
 else
 {
   temp=head;
   if(head->data>ele)
   {
    n->next=head;
    head=n;
   }
   else
   {
     while(temp->data<ele && temp->next!=NULL)
     {
      s=temp;
      temp=temp->next;
     }
     if(temp->next==NULL && temp->data<ele)
     {
      n->next=NULL;
      temp->next=n;
     }
     else
     {
      n->next=temp;
      s->next=n;
     }
   }
 }
 return head;
}
void display(struct node *head)
{
 struct node *temp=head;
 printf("\n");
 while(temp!=NULL)
 {
   printf(" %d ",temp->data);
   temp=temp->next;
 }
}
void main()
{
 struct node *head=NULL;
 int ele,choice;
 clrscr();
 while(1)
 {
  printf("\n1.insert");
  printf("\n2.end");
  printf("\nenter your choice");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:printf("\nEnter New element");
	  scanf("%d",&ele);
	  head=in_sort(head,ele);
	  display(head);
	  break;
   case 2:exit(0);
   default:printf("\nplease,enter valid choice");
  }
 }
 getch();
}