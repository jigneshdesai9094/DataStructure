#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
  struct node *left, *right;
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
  int bi[30];
};
void search(struct node *root, struct binary b[], char ch, int i)
{
  int in = 0;
  int l = 0;
  int find = 1;
  while (find)
  {
    if (root->ch == ch)
    {
      b[i].ch = ch;
      b[i].last_index = in;
      find = 0;
    }
    else if ((root->left)->ch == '^')
    {
      if ((root->right)->ch == ch)
      {
        root = root->right;
        l = 1;
      }
      else
      {
        root = root->left;
        l = 0;
      }
    }
    else
    {
      if ((root->left)->ch == ch)
      {
        root = root->left;
        l = 0;
      }
      else
      {
        root = root->right;
        l = 1;
      }
    }
    b[i].bi[in] = l;
    in++;
  }
}
struct node *create_tree(struct node *root, struct item it[], int it_count)
{
  int i;
  struct node *n1, *n2, *n3;
  n1 = (struct node *)malloc(sizeof(struct node));
  n1->ch = it[0].ch;
  n1->freq = it[0].count;
  n1->left = NULL;
  n1->right = NULL;
  if (it_count > 1)
  {
    for (i = 1; i < it_count; i++)
    {
      n2 = (struct node *)malloc(sizeof(struct node));
      n3 = (struct node *)malloc(sizeof(struct node));
      n2->ch = it[i].ch;
      n2->freq = it[i].count;
      n2->left = NULL;
      n2->right = NULL;
      n3->ch = '^';
      n3->freq = (n1->freq) + (n2->freq);
      if (n1->freq > n2->freq)
      {
        n3->right = n1;
        n3->left = n2;
      }
      else
      {
        n3->left = n1;
        n3->right = n2;
      }
      n1 = n3;
    }
    root = n3;
  }
  else
    root = n1;
  return root;
}
int strtoitem(char str[], struct item it[])
{
  int i = 0, j, c, check = 1, it_count = 0;
  while (str[i] != '\0')
  {
    c = 0;
    j = 0;
    check = 1;
    while (j < it_count)
    {
      // printf("\nexecute : %d",i);
      if (it[j].ch == str[i])
      {
        check = 0;
        break;
      }
      j++;
    }
    if (check)
    {
      j = 0;
      while (str[j] != '\0')
      {

        if (str[j] == str[i])
          c++;
        j++;
      }
      it[it_count].ch = str[i];
      it[it_count].count = c;
      it_count++;
    }
    i++;
  }
  return it_count;
}
void sort_item(struct item it[], int it_count)
{
  int i, j, count, l;
  char ch;
  l = it_count - 1;
  for (i = 0; i < it_count - 1; i++)
  {
    for (j = 0; j < l; j++)
    {
      if (it[j].count > it[j + 1].count)
      {
        ch = it[j].ch;
        count = it[j].count;
        it[j].ch = it[j + 1].ch;
        it[j].count = it[j + 1].count;
        it[j + 1].ch = ch;
        it[j + 1].count = count;
      }
    }
    l--;
  }
}
int main()
{
  char str[50];
  int i, j, it_count;
  struct item it[20];
  struct node *root = NULL;
  struct binary b[20];
//  clrscr();
  printf("\nEnter Message : \n");
  scanf("%s", str);
  it_count = strtoitem(str, it);
  sort_item(it, it_count);
  root = create_tree(root, it, it_count);
  for (i = 0; i < it_count; i++)
    search(root, b, it[i].ch, i);
  printf("\n\nEach Character Binary Value : ");
  for (i = 0; i < it_count; i++)
  {
    printf("\n %c [%d] : ", b[i].ch, it[i].count);
    for (j = 0; j < b[i].last_index; j++)
    {
      printf("%d", b[i].bi[j]);
    }
    if (b[i].last_index == 0)
      printf("%d", b[i].bi[0]);
  }
 // getch();
 return 0;
}