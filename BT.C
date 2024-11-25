
#include<string.h>
#include<conio.h>
#include<stdio.h>
struct tree
{
  int data;
  struct tree *left,*right;
};
struct combo
{
 struct tree *addr;
 int check;
};
struct tree* insert(struct tree *root,int ele)
{
 struct tree *temp=root,*pre=NULL,*n=(struct tree *)malloc(sizeof(struct tree));
 n->data=ele;
 n->left=NULL;
 n->right=NULL;
 if(root==NULL)
   root=n;
 else
 {
   while(temp!=NULL)
   {
       pre=temp;
       temp = temp->data<ele?temp->right:temp->left;
   }
   if(pre->data<ele)
     pre->right=n;
   else
     pre->left=n;
 }
 return root;
}
int push(struct tree *root,struct combo arr[],int *top)
{
  if(root!=NULL)
  {
   while(!(root->left==NULL && root->right==NULL))
   {
     *top+=1;
     arr[*top].addr=root;
     arr[*top].check=0;
     if(root->left==NULL)
      {
       root=root->right;
       arr[*top].check=1;
      }
     else
       root=root->left;
   }
   return root->data;
  }
  return 0;
}
void push2(struct tree *root,struct combo arr[],int *top)
{
  if(root!=NULL)
  {
     while(!(root->left==NULL && root->right==NULL))
     {
	printf(" %d ",root->data);
	if(root->right!=NULL)
	{
	 *top+=1;
	 arr[*top].addr=root->right;
	 arr[*top].check=0;
	}
       if(root->left==NULL)
       root=root->right;
     else
       root=root->left;
     }
     printf(" %d ",root->data);
  }
}
struct tree* push3(struct tree *root,struct combo arr[],int *top)
{
  if(root!=NULL)
  {
    while(root->left!=NULL)
    {
      *top+=1;
      arr[*top].addr=root;

      root=root->left;
    }
    printf(" %d ",root->data);
  }
  return root;
}
void inOrder(struct tree *root)
{
   struct combo arr[30];
   struct tree *temp=NULL,*t1;
   int t=-1,*top=&t;
   t1=push3(root,arr,top);
   while(t1!=NULL && t1->right!=NULL)
       t1=push3(t1->right,arr,top);
   while(t!=-1)
{
      temp=arr[t].addr;
       printf(" %d ",temp->data);
       t--;
       t1=push3(temp->right,arr,top);
       while(t1!=NULL && t1->right!=NULL)
	t1=push3(t1->right,arr,top);

   }
}
void preOrder(struct tree *root)
{
   struct combo arr[30];
   int t=-1,*top=&t;
   if(root!=NULL)
   {
     printf(" %d ",root->data);
     push2(root->left,arr,top);
     while(t!=-1)
     {

       if(arr[t].check==0)
       {
	   arr[t].check=1;
	push2(arr[t].addr,arr,top);
       }
       t--;
     }
     push2(root->right,arr,top);
     while(t!=-1)
     {

       if(arr[t].check==0)
       {
	   arr[t].check=1;
	push2(arr[t].addr,arr,top);
       }
       t--;
     }
   }
}
void postOrder(struct tree *root)
{
   struct combo arr[20];
   int t=-1,*top=&t;
   printf(" %d ",push(root,arr,top));
   while(t!=-1)
   {
   if(arr[t].check==0)
   {
	 arr[t].check=1;
      printf(" %d ",push((arr[t].addr)->right,arr,top));
   }
   else
   {
     printf(" %d ",(arr[t].addr)->data);
     t--;
   }
   }
}
void remove1(struct tree *root,int sele)
{
  struct tree *temp=root,*pre=NULL,*s=NULL,*p=NULL;
  char str[20]="";
  //int x=0;
  while(temp!=NULL)
  {
   //x++;
   //if(x==5)
    //break;
    printf("%d comapre to %d ",sele,temp->data);
    if(temp->data>sele)
    {
       strcpy(str,"left");
       p=temp;
       temp=temp->left;
    }
    else if(temp->data<sele)
    {
      strcpy(str,"right");
      p=temp;
      temp=temp->right;
    }
    else
    {
      if(temp->left!=NULL && temp->right!=NULL)
      {
	 s=temp->right;
	 while(s->left!=NULL)
	 {
	 pre=s;
	 s=s->left;
	 }
	 pre->left=s->right;
	 temp->data=s->data;
	 free(s);
      }
      else
      {
	  s=temp->left!=NULL?temp->left:temp->right;
	  if(strcmp(str,"left")==0)
	     p->left=s;
	  else
	     p->right=s;
	  free(temp);
      }
      temp=NULL;
    }
  }
}
void main()
{
 struct tree *root=NULL;
 int choice,ele;
 int count=0;
 clrscr();
 while(1)
 {
  printf("\n1.Insert");
  printf("\n2.PostOrder");
  printf("\n3.PreOrder");
  printf("\n4.InOrder");
  printf("\n5.delete");
  printf("\n6.exit");
  printf("\nEnter your choice");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
   printf("\nEnter New Element");
   scanf("%d",&ele);
   root=insert(root,ele);
   count++;
   break;
   case 2:
   postOrder(root);
   break;
   case 3:
   preOrder(root);
   break;
   case 4:
   inOrder(root);
   break;
   case 5:
   printf("\nEnter element you want to delete");
   scanf("%d",&ele);
   remove1(root,ele);
   break;
   case 6:
   exit(0);
  }
 }
}