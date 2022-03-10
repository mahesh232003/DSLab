#include <stdio.h>
#include <stdlib.h>
#define max 20
int visited[max],q[max],f=-1,r=-1,a[10][10];
void enque(int x)
{
    if (f==-1)
    {
        f=r=0;
    }
    else
    {
        ++r;
    }
    q[r]=x;
}
int dequeue()
{
    int x;
    if(f==-1)
    {
        return -1;
    }
    else
    {
        x=q[f];
        if (f==r)
        {
            f=r=-1;
        }
        else
        {
            ++f;
        }
        return x;
    }
}
void bfs(int v,int n)
{
    int u=v;
    visited[u]=1;
    printf("%d\t",v);
    while(1)
    {
        for (int i=1;i<=n;i++)
        {
            if(a[u][i]==1 && visited[i]==0)
            {
                visited[i]=1;
                enque(i);
                printf("%d\t",i);
            }
        }
        if (f==-1)
        {
            return;
        }
        else
        {
            u=dequeue();
        }
    }
}
void dfs(int v,int n)
{
    printf("%d\t",v);
    visited[v]=1;
    for(int i=0;i<=n;i++)
    {
        if (visited[i]==0 && a[v][i]==1)
        {
            dfs(i,n);
        }
    }
}

int main()
{
    int n,ch,v;
    printf("Enter number of elements in graph\n");
    scanf("%d",&n);
    printf("Enter elements in matrix\n");
    for(int i=1;i<=n;i++)
    {
        printf("Enter %d row elements\n",i);
        for (int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
        visited[i]=0;
    }
    printf("Enter your choice\n");
    printf("1:BFS\n2:DFS\n3:Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("Enter vertex\n");
                scanf("%d",&v);
                bfs(v,n);
                break;
        case 2: printf("Enter vertex\n");
                scanf("%d",&v);
                dfs(v,n);
                break;
        case 3:exit(0);
        default:printf("Enter a valid choice\n");
                break;
    }
    return 0;
}



