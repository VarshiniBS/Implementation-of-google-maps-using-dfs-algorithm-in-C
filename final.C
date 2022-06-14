#include <stdio.h>
#include <conio.h>
#include <string.h>
# define MAX 30
# define VER 8
int count;
int top;
char *places[8]={"vijaynagar","Marenhalli","Jayanagar","Kormangala","ElectronicCity","JPnagar","Indiranagar","Bellandur"};
void dfs(int a[8][8], int u, int v, int visited[], int stack[], int dist[]);
void push(int s[], int ele);
void pop(int s[]);
int main()
{   char src[30],dest[30];
    int s,d,stack[MAX];
    int i,mx,mn,indexs,indexl;
    int visited[8],dist[MAX];
   
    int edges[VER][VER]={{0,0,1,1,0,0,0,0},
			 {0,0,0,1,0,0,0,0},
			 {1,0,0,1,1,1,0,0},
			 {1,1,1,0,0,0,1,0},
			 {0,0,1,0,0,0,1,1},
			 {0,0,1,0,0,0,1,1},
			 {0,0,0,1,1,1,0,0},
			 {0,0,0,0,1,1,0,0}};

    clrscr();
    top=0;
    count=0;
    dist[MAX]=0;
    for(i=0;i<VER;i++)
    { visited[i]=0; }


    printf("Enter source ");
    scanf("%s",src);
    for(i=0;i<VER;i++)
     if(!strcmpi(src,places[i]))
     {
      s=i;
      break;
     }
    printf("\nEnter destination ");
    scanf("%s",dest);
    for(i=0;i<VER;i++)
    if(!strcmpi(dest,places[i]))
     {
      d=i;
      break;
     }
    dfs(edges,s,d,visited,stack,dist);
    if(dist[1]==0)
     printf("no possible path");
    mx = 0;
    mn = MAX;
    indexs=0;
    indexl=0;
    for(i=1; dist[i]!=0; i++)
    {
	if(dist[i]>mx)
	{
	    mx = dist[i];
	    indexl=i;
	}
    }
    for(i=1;dist[i]!=0; i++)
    {
	if(dist[i]<mn)
	{
	    mn = dist[i];
	    indexs=i;

	}}
	if(mx==mn)
	 printf("all routes have same distance can take any route\n");
    else
    {
      printf("%d is the Longest path: %d\n",indexl, mx-1);
      printf("%d is the Shortest path: %d\n\n",indexs, mn-1);}


    return 0;
}
void dfs(int a[8][8], int u, int v, int visited[], int stack[], int dist[])
{
    int b,i,w;

    if(visited[u]==1)
     return;
    visited[u]=1;
    push(stack,u);
    if(u==v)
     { ++count;
	printf("%d",count);
	for(i=1;i<=top;i++)
	{// **b=*(places[i-1]);
	 b=stack[i];
	 if(i==top)
	  printf("%s",places[b]);
	  else
	   printf("%s--->",places[b]); }
	printf("\n");
	dist[count]=top;

	pop(stack);
	visited[u]=0;
	return;
      }

     for(w=0;w<8;w++)
      if(a[u][w]==1 && visited[w]!=1)
     {
       dfs(a,w,v,visited,stack,dist);}
     pop(stack);
     visited[u]=0;

}


void push( int items[], int e)
{
	items[++top]=e;
}
void pop(int items[])
{        items[top]=0;
	 (top)--;
}