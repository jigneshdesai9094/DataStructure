#include<stdio.h>
#include<stdlib.h>
struct tree
{
    struct tree *left,*right;
    int data;
};
struct tree* del(struct tree *root,int ele)
{
    struct tree *curr=root,*pre=NULL,*temp,*pres,*succe;
    int l=0;
    while(curr!=NULL && curr->data!=ele)
    {
        pre=curr;
        curr=curr->data<ele?curr->right:curr->left;
    }
    if(curr==NULL)
      printf("\nElement is not present ");
    else
    {
        if(curr->left==NULL && curr->right==NULL)
          (pre->data)<(curr->data)?((pre->right)=NULL):((pre->left)=NULL);
        else if(curr->left==NULL && curr->right==NULL)
        {
          temp=curr->left==NULL?curr->right:curr->left;
          (pre->data)<(curr->data)?((pre->right)=temp):((pre->left)=temp);
        }
        else
        {
            pres=curr->right;
            succe=pres->left;
            if(succe==NULL)
            {
                pres->left=curr->left;
                pre->data<curr->data?(pre->right=pres):(pre->left=pres);
            }
            else
            {
                while(succe->left!=NULL)
                {
                    pres=succe;
                    succe=succe->left;
                }
                pres->left=succe->right;
                pre->data<curr->data?(pre->right=succe):(pre->left=succe);
            }
        }
        free(curr);
    }
    return root;
}
struct tree* insert(struct tree *root,int data)
{
    struct tree *n=(struct tree*)malloc(sizeof(struct tree)),*curr=root;
    int l=1;
    n->left=NULL;
    n->right=NULL;
    n->data=data;
    if(root==NULL)
      root=n;
    else
    {
        while(l)
        {
            if(curr->data<data)
                (curr->right==NULL)?curr->right=n:(curr=curr->right);
            else
                (curr->left==NULL)?curr->left=n:(curr=curr->left);
            if(curr->right==n || curr->left==n)
               l=0;
        }
    }
  return root;
}
void postOrder(struct tree *root)
{
   if(root!=NULL)
   {
       postOrder(root->left);
       postOrder(root->right);
       printf(" %d ",root->data);
   }
}
void inOrder(struct tree *root)
{
   if(root!=NULL)
   {
       inOrder(root->left);
       printf(" %d ",root->data);
       inOrder(root->right);
   }
}
void preOrder(struct tree *root)
{
   if(root!=NULL)
   {
       printf(" %d ",root->data);
       preOrder(root->left);
       preOrder(root->right);
   }
}
void main()
{
    struct tree *root=NULL;
    int ele,choice;
    while(1)
    {
        printf("\n1.insert");
        printf("\n2.postOrder");
        printf("\n3.inOrder");
        printf("\n4.preOrder");
        printf("\n5.delete");
        printf("\n6.exit");
        printf("\nEnter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("\nEnter new Element : ");
            scanf("%d",&ele);
            root=insert(root,ele);
            break;
            
            case 2:
            postOrder(root);
            break;
            
            case 3:
            inOrder(root);
            break;
        
            case 4:
            preOrder(root);
            break;
            
            case 5:
            printf("\nEnter Element you want to delete : ");
            scanf("%d",&ele);
            root=del(root,ele);
            break;
            case 6:
            exit(0);
            default:printf("\nplease,enter valid choice");
        }
    }
}
