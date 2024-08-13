#include <stdio.h>  
#include <stdlib.h>  
#define SIZE 5  
 
int push(int [],int);  
int pop(int [],int);  
void show(int [],int);  
int main()  
{  
    int choice; 
    int top = -1,stack[SIZE]; 
    while (1)  
    {  
        printf("\nPerform operations on the stack:");  
        printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.End");  
        printf("\n\nEnter the choice: ");  
        scanf("%d", &choice);  
        switch (choice)  
        {  
        case 1:  
            top=push(stack,top);  
            break;  
        case 2:  
            top=pop(stack,top);  
            break;  
        case 3:  
            show(stack,top);  
            break;  
        case 4:  
            exit(0);  
        default:  
            printf("\nInvalid choice!!");  
        }  
    }  
}  
int push(int stack[],int top)  
{  
    int x;  
    if (top == SIZE - 1)  
    {  
        printf("\nOverflow!!");  
    }  
    else  
    {  
        printf("\nEnter the element to be added into the stack: ");  
        scanf("%d", &x);  
        top = top + 1;  
        stack[top] = x;  
    }  
    return top;
}  
int pop(int stack[],int top)  
{  
    if (top == -1)  
    {  
        printf("\nUnderflow!!");  
    }  
    else  
    {  
        printf("\nPopped element: %d", stack[top]);  
        top = top - 1;  
    }  
    return top;
}  
void show(int stack[],int top)  
{  
    if (top == -1)  
    {  
        printf("\nUnderflow!!");  
    }  
    else  
    {  
        printf("\nElements present in the stack: \n");  
        for (int i = top; i >= 0; --i)  
            printf("%d\n", stack[i]);  
    }  
}  