// linked list
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *insert(struct node *head, int pos, int ele)
{
    struct node *curr = head, *p = NULL, *t = (struct node *)malloc(sizeof(struct node));
    int c = 2;
    t->data = ele;
    if (head == NULL)
    {
        t->next = t;
        head = t;
    }
    else if (pos == 1)
    {
        t->next = head;
        curr = curr->next;
        while (curr->next != head)
            curr = curr->next;
        curr->next = t;
        head = t;
    }
    else
    {
        curr = curr->next;
        while (curr != head && c < pos)
        {
            // printf("p = %u and curr=%u",curr,curr->next);
            p = curr;
            curr = curr->next;
            c++;
        }
        if (curr == head && p != NULL)
        {
            t->next = head;
            p->next = t;
        }
        else if (p == NULL)
        {
            t->next = curr;
            head->next = t;
        }
        else
        {
            p->next = t;
            t->next = curr;
        }
    }

    return head;
}
struct node *del(struct node *head, int ele)
{
    struct node *t = head, *s = NULL;
    if (head == NULL)
    {
        printf("\nList is empty");
    }
    else if (head->data == ele)
    {
        s = head;
        t = t->next;
        if (t == head)
        {
            free(s);
            head = NULL;
        }
        else
        {
            while (t->next != head)
            {
                t = t->next;
            }
            t->next = s->next;
            head = s->next;
            free(s);
        }
    }
    else
    {
        t = t->next;
        while (t != head && t->data != ele)
        {
            s = t;
            t = t->next;
        }
        if (t == head)
            printf("\nElement is Not Present IN the List");
        else if (s == NULL)
        {
            head->next = t->next;
            free(t);
        }
        else
        {
            s->next = t->next;
            free(t);
        }
    }
    return head;
}
void modify(struct node *head)
{
    int per, nele;
    struct node *temp = head;
    if (head == NULL)
        printf("\nList is empty");
    else
    {
        printf("\nEnter Previous and New Element : ");
        scanf("%d%d", &per, &nele);
        if (temp->data == per)
        {
            temp->data = nele;
        }
        else
        {
            temp = temp->next;

            while (temp != head && temp->data != per)
            {
                temp = temp->next;
            }
            if (temp == head)
                printf("\nPrevious Element is not found ");
            else
                temp->data = nele;
        }
    }
}
void display(struct node *head)
{
    struct node *t = head;
    if (head == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        printf(" %d ", t->data);
        t = t->next;
        while (t != head)
        {
            printf(" %d ", t->data);
            t = t->next;
        }
    }
}
void main()
{
    struct node *head = NULL;
    int choice, pos, ele;

    while (1)
    {
        printf("\n1.insert specific position element");
        printf("\n2.delete");
        printf("\n3.modify");
        printf("\n4.display");
        printf("\n5.end");
        printf("\nenter Your choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter New Element");
            scanf("%d", &ele);
            printf("\nEnter Position where element insert");
            scanf("%d", &pos);
            head = insert(head, pos, ele);
            break;
        case 2:
            printf("\nEnter Element you want to delete");
            scanf("%d", &ele);
            head = del(head, ele);
            break;
        case 3:
            modify(head);
            break;
        case 4:
            display(head);
            break;
        case 5:
            exit(0);
        default:
            printf("\nPlease,enter valid choice");
        }
    }
}
