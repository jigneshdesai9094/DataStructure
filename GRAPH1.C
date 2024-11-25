struct graph
{
 int v;
 int e;
 int *matrix;
};
struct graph createGraph(int v,int e)
{
  struct graph g;
  int *m=(int*)malloc(sizeof(int)*(v*v));
  int v1,v2,i;
  int j;
 for(i=0;i<v;i++)
 {
   for(j=0;j<v;j++)
     *((m+(v*i))+j)=0;
 }
  g.v=v;
  g.e=e;
  for(i=0;i<e;i++)
  {
   printf("\nEnter Vertice1 to connect Vertice2 number");
   scanf("%d%d",&v1,&v2);
   *((m+(v*v1))+v2)=1;
 //  *((m+(v*v2))+v1)=1;
  }
  g.matrix=m;
  return g;
}
int isContain(int *visited,int t,int ele)
{
   int i;
   for(i=0;i<=t;i++)
   {
     if(*(visited+i)==ele)
       break;
   }
   if(i>t)
     return -1;
   else
     return 1;
}
void BFS(struct graph g)
{
  int *visited=(int*)malloc(sizeof(int)*g.v);
  int r=0,f=-1,j,row;
  *visited=*(g.matrix);
  while(f<r)
  {
     ++f;
     for(j=0;j<g.v;j++)
     {
       row=*((g.matrix+(g.v*(*(visited+f))))+j);
       if(row==1)
       {
	 for(row=0;row<=r;row++)
	 {
	    if((*(visited+row))==j)
	       break;
	 }
	 if(row>r)
	   visited[++r]=j;
       }
     }
  }
  printf("\nBFS :\n");
  for(row=0;row<=r;row++)
    printf(" %d ",*(visited+row));
}

void DFS(struct graph g)
{
  int *visited=(int*)malloc(sizeof(int)*g.v);
  int t=0,j,con,i;
  *visited=*(g.matrix);;
  for(j=0;j<g.v;j++)
  {
    con=*((g.matrix+(g.v*(*(visited+t))))+j);
    if(con==1 && isContain()==-1)
    {
      *(visited+t)=j;
    }
  }
}
void display(struct graph g)
{
 int i,j;
 for(i=0;i<g.v;i++)
 {
   for(j=0;j<g.v;j++)
     printf(" %d ",*((g.matrix+(g.v*i))+j));
   printf("\n");
 }
}
void main()
{

  struct graph g;
  int v,e;
  clrscr();
  printf("\nEnter virtices and edges");
  scanf("%d%d",&v,&e);
  g=createGraph(v,e);
  display(g);
  BFS(g);
  getch();
}