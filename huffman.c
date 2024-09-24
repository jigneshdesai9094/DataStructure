#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
  struct node *left,*right;
  char ch;
  int freq;
};
struct item
{
 char ch;
 int count;
};
struct binary
{
  char ch;
  int last_index;
  int bi[20];
};
void inorder(struct node *root)
{
  if(root!=NULL)
  {
    inorder(root->left);
    printf(" %c %d",root->ch,root->freq);
    inorder(root->right);
  }
}
void search(char ch,int count,struct node *root,struct binary b[],int in,int li,int m)
{
    if(root!=NULL && m==0)
    {
        
        if(root->ch==ch && root->freq==count)
        {
          b[in].ch=ch;
          b[in].last_index=li;
          m=1;
        }
        else
        {
          if(m==0)
          { 
           li++;
           b[in].bi[li]=0;
            search(ch,count,root->left,b,in,li,m);
          }
          if(m==0)
          {
           li++;
           b[in].bi[li]=1;
           search(ch,count,root->left,b,in,li,m);
          }
        }
    }
  
     
    
}
struct node* create_tree(struct node *root,struct item it[],int it_count)
{
 int i;
 struct node *n1,*n2,*n3;
  n1=(struct node*)malloc(sizeof(struct node));
  n1->ch=it[0].ch;
  n1->freq=it[0].count;
  n1->left=NULL;
  n1->right=NULL;
 if(it_count>1)
 {
   n2=(struct node*)malloc(sizeof(struct node));
   n3=(struct node*)malloc(sizeof(struct node));
   n2->ch=it[1].ch;
   n2->freq=it[1].count;
   n2->left=NULL;
   n2->right=NULL;
   n3->ch='U';
   n3->freq=(n1->freq)+(n2->freq);
   if(n1->freq>n2->freq)
   {
    n3->right=n1;
    n3->left=n2;
   }
   else
   {
    n3->left=n1;
    n3->right=n2;
   }

   for(i=2;i<it_count;i++)
   {
     n1=(struct node*)malloc(sizeof(struct node));
     n2=(struct node*)malloc(sizeof(struct node));
     n1->left=NULL;
     n1->right=NULL;
     n1->ch=it[i].ch;
     n1->freq=it[i].count;
     n2->ch='U';
     n2->freq=(n1->freq)+(n3->freq);
    // printf("n1= %c %d n3= %c %d n2= %c %d",n1->ch,n1->freq,n3->ch,n3->freq,n2->ch,n2->freq);
     if(n3->freq>n1->freq)
     {
       n2->left=n1;
       n2->right=n3;
     }
     else
     {
      n2->left=n3;
      n2->right=n1;
     }
     n3=n2;
   }
   root=n3;
 }
 else
  root=n1;
 return root;
}
int strtoitem(char str[],struct item it[])
{
 int i=0,j,c,check=1,it_count=0;
 while(str[i]!='\0')
 {
    c=0;
    j=0;
    check=1;
    while(j<it_count)
    {
       //printf("\nexecute : %d",i);
       if(it[j].ch==str[i])
       {
	      check=0;
	      break;
       }
       j++;
    }
    if(check)
    {
     j=0 ;
    while(str[j]!='\0')
    {

     if(str[j]==str[i])
	c++;
     j++;
    }
    it[it_count].ch=str[i];
    it[it_count].count=c;
    it_count++;
    }
   i++;
 }
 return it_count;
}
void sort_item(struct item it[],int it_count)
{
  int i,j,count,l;
  char ch;
  l=it_count-1;
  for(i=0;i<it_count-1;i++)
  {
   for(j=0;j<l;j++)
   {
     if(it[j].count>it[j+1].count)
     {
       ch=it[j].ch;
       count=it[j].count;
       it[j].ch=it[j+1].ch;
       it[j].count=it[j+1].count;
       it[j+1].ch=ch;
       it[j+1].count=count;
     }
   }
   l--;
  }
}
void main()
{
 char str[50];
 int i,j,it_count,last_index=-1;
 struct item it[20];
 struct node *root=NULL;
 struct binary b[20];
 printf("\nEnter Message : \n");
 scanf("%s",str);
 it_count=strtoitem(str,it);
 sort_item(it,it_count);
 root=create_tree(root,it,it_count);
 printf(" address of root : %d ",root);
 inorder(root);
 printf(" address of root : %d ",root);
 for(i=0;i<it_count;i++)
 {
    //printf("\nch %c  count %d",it[i].ch,it[i].count);
    
    search(it[i].ch,it[i].count,root,b,i,last_index,0);
 }
 printf("\nBinary Value For Each Character");
 for(i=0;i<=it_count;i++)
 {
    printf("\n %c : ",b[i].ch);
    for(j=0;j<=b[i].last_index;j++)
    {
      printf(" %d ",b[i].bi[j]);
    }
 }
}