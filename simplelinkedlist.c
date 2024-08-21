//linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};

struct node* insert(struct node *head,int pos,int ele)
{
    struct node *curr=head,*p=NULL,*t=(struct node*)malloc(sizeof(struct node));
    int c=1;
    t->data=ele;
    if(head==NULL)
    {
        t->next=NULL;
        head=t;
    }
    else
    {
        while(curr!=NULL && c!=pos)
        {
            p=curr;
            curr=curr->next;
            c++;
        }
        if(curr==NULL)
        {
            t->next=NULL;
            p->next=t;
        }
        else
        {
            t->next=curr;
            if(p!=NULL)
              p->next=t;
            else
              head=t;
        }
    }
	
	return head;
}
struct node* insert_sort(struct node *head,int ele)
{
	struct node *curr=head,*p=NULL,*t=(struct node*)malloc(sizeof(struct node));
	t->data=ele;
	if(head==NULL)
	{
		t->next=NULL;
		head=t;
	}
	else
	{
		while(curr!=NULL && curr->data<ele)
		{
			p=curr;
			curr=curr->next;
		}
		if(head==curr)
		{
			t->next=head;
			head=t;
		}
		else if(curr==NULL)
		{
			t->next=NULL;
			p->next=t;
		}
		else
		{
			t->next=curr;
			p->next=t;
		}
	}
	
	return head;
}
struct node* sort(struct node *head)
{
	struct node *temp=head,*n=head,*p;
	int c=0;
	if(head!=NULL)
	{
         while((temp->next)->next==NULL)
		 {
			 while(n!=NULL)
			 {
				 if((n->data) > ((n->next)->data))
				 {
                   c=(n->next)->data;
				   (n->next)->data=n->data;
				   n->data=c;
				 }
				 n=n->next;
			 }
			 temp=temp->next;
		 }
	}
	return head;
}
struct node* del(struct node * head,int ele)
{
	struct node *t=head,*s=NULL;
	if(head==NULL)
	{
		printf("\nList is empty");
	}
	else
	{
        while(t!=NULL && t->data!=ele)
		{
			s=t;
			t=t->next;
		}
		if(head==t)
		{
			head=t->next;
		}
		else if(t!=NULL)
		{
			if(t->next!=NULL)
			{
			  s->next=t->next;
			}
			else
			{
				s->next=NULL;
			}
		}
		else
		{
			printf("\nElement is not present");
		}
		printf("\nRemove %d ",t->data);
		free(t);
	}

	return head;
}
void display(struct node *head)
{
	struct node *t=head;
	if(head==NULL)
	{
		printf("\nList is empty");
	}
	else
	{
		while(t!=NULL)
		{
			printf(" %d ",t->data);
			t=t->next;
		}
	}
}
void main()
{
    struct node *head=NULL;
    int choice,pos,ele;
    while(1)
    {
        printf("\n1.insert specific position element");
        printf("\n2.delete");
        printf("\n3.display");
		printf("\n4.insertion sort");
		printf("\n5.sort");
        printf("\n6.end");
        printf("\nenter Your choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("\nEnter New Element");
                   scanf("%d",&ele);
                   printf("\nEnter Position where element insert");
                   scanf("%d",&pos);
                   head=insert(head,pos,ele);
                   break;
            case 2:printf("\nEnter Element you want to delete");
                   scanf("%d",&ele);
                   head=del(head,ele);
                   break;
            case 3:display(head);
                   break;
			case 4:printf("\nEnter New Element");
                   scanf("%d",&ele);
				   head=insert_sort(head,ele);
				   break;
			case 5:head=sort(head);
				   break;
            case 6:exit(0);
            default:printf("\nPlease,enter valid choice");
        }
    }
}