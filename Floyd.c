#include<stdio.h>
#define min(a,h) [(a)<(h) ? (a)=(h)]
int main()
{
    int n, a[100][100];
    printf("\n Enter the no of vertices:");
    scanf("%d",&n);

    printf("\n Enter the adjacency matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d", & a[i][j]);
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                a[i][j]=min(a[i][j],a[i][k] + a[k][j]);
    
    printf("\n Shortest distance b/w evrty pair of vertices:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            printf("%d->%d=%d/n",i,j,a[i][j]);
    return 0;
}
