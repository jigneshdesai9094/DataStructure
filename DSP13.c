#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    struct node *pre;
    int data;
    struct node *next;
};
struct node * ins(struct node *head,int ele,int pos)
{
    struct node *c=head,*l=head,*n =(struct node*)malloc(sizeof(struct node));
    int co=1;
    n->data=ele;
 
    if(head==NULL)
    {
       n->next=n;
       n->pre=n;
       head=n;
    }
    else
    {
        do
        {
            c=c->next;
            co++;
        } while (c!=head && co<pos);
        if(c==head || pos==1)
        {
            (head->pre)->next=n;
            n->pre = head->pre;
            n->next=head;
            head->pre=n;
            if(pos==1)
              head=n;
        }  
        else
        {
            (c->pre)->next=n;
            n->pre=c->pre;
            n->next=c;
            c->pre=n;
        }
    }
    return head;
}
struct node* del(struct node *head)
{
    int ele;
    struct node *c=head;
    if(head==NULL)
       printf("\nList is empty ");
    else
    {
      printf("\nEnter element you want to delete");
      scanf("%d",&ele);
      if(head->next==head && head->data==ele)
           head=NULL;
     else if(head->data==ele)
        {
           (head->pre)->next=head->next;
           (head->next)->pre=head->pre;
           head=head->next;
        } 
     else
     { 
      printf("\nElse Block is Exceute");
      do
      {
        if(c->data==ele)
           break;
        c=c->next;
      }while (c!=head);
      if(c==head)
         printf("\nElement is not present");
      else
      {
         (c->pre)->next=c->next;
         (c->next)->pre=c->pre;
      }
     }
     free(c);
    }
    return head;
}
void modify(struct node *head)
{
    int per,nele;
    struct node *c=head;
    if(head==NULL)
    {
        printf("\nList is empty ");
    }
    else
    {
          printf("\nEnter Previous and New Element : ");
          scanf("%d%d", &per, &nele);  
          do
          {
             if(c->data==per)
              break;
            c=c->next;
          } while (c!=head);
         if(c==head)
           printf("\nprevious element is not present");
        else
           c->data=nele;  
        
    }
}
void display(struct node *head)
{
    struct node *t=head;
        if(head==NULL)
    {
        printf("\nList is empty ");
    }
    else
    {
            do
    {
        printf(" %d ",t->data);
        t=t->next;
      
    } while (t!=head);
    }

    
}
void main()
{
    struct node *head=NULL;
    int choice,ele,pos;
    while(1)
    {
        printf("\n1.Insert");
        printf("\n2.delete");
        printf("\n3.modify");
        printf("\n4.display");
        printf("\n5.exit");
        printf("\nenter your choice");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter New element and Position : ");
            scanf("%d%d",&ele,&pos);
            head=ins(head,ele,pos);
            break;
        case 2:
            head=del(head);
            break;
        case 3:
             modify(head);
             break;
        case 4:
            display(head);
            break;
        case 5:
               exit(0);
        default:printf("\nPlease,enter valid choice");
            break;
        }
    }
    getch();
}
