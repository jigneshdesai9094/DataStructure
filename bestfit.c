
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void swapOut(char pname,char s_memory[],int ssize)
{
    int i=0;
    for(i=0;i<=ssize;i++)
    {
        if(s_memory[i]==pname)
           s_memory[i]='\0';
    }
}
void putMemory(char pname,int start,int end,char s_memory[])
{
    int i;
    for(i=start;i<=end;i++)
        s_memory[i]=pname;
}
void printarr(char s_memory[],int size)
{
    int i;
    int x=0;
    for(i=0;i<=size;i++)
    {
        printf(" %c",s_memory[i]);
        if(x==20)
        {
          printf("\n");
          x=0;
        }
        x++;
    }
}
void swapIn(char pname,int size,char s_memory[],int ssize)
{
    int start=-1,end=-1,old_start=-1,old_end=ssize;
    int i=0,x=0,last;
    while(i<=ssize)
    {
        if(x==0 && s_memory[i]=='\0')
        {
            x=1;
            start=i;
        }
        if(x==1 && s_memory[i]!='\0')
        {
            x=0;
            end=i;
        }
        if(start!=-1 && end!=-1)
        {
            if((end-start)>=size && (old_end-old_start)>(end-start))
            {
                old_start=start;
                old_end=end;
            }
        }
        i++;
    }
    if(end==-1 || old_end==end)
        last=ssize;
    else
      last=end;
    if((old_end-old_start)<=(last-start))
        putMemory(pname,old_start,old_start+(size-1),s_memory);
    else
    {
        putMemory(pname,start,start+(size-1),s_memory);
    }
}
int main() {
    char pname,s_memory[500];
    int i=0;
    int size,ssize=499,choice;
    for(i=0;i<500;i++)
    {
        s_memory[i]='\0';
    }
    while(1)
    {
        printf("\n1.swap in");
        printf("\n2.swap out");
        printf("\n3.exit");
        printf("\nenter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:    printf("Enter process name one character: ");
                       scanf(" %c",&pname);
                       printf("\nenter process size  : ");
                       scanf("%d",&size);
                      swapIn(pname,size,s_memory,ssize);
                    
                   printarr(s_memory,ssize);
                   break;
            case 2:printf("Enter process name one character: ");
                    scanf(" %c",&pname);
                   swapOut(pname,s_memory,ssize);
                   printarr(s_memory,ssize);
                   break;
            case 3:exit(0);
            default:printf("\nenter valid choice");
        }
    }
    return 0;
}