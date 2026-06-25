#include<stdio.h>
#define MAX 10


int TOrder[MAX], k=0;


void topologicalSort(int A[][MAX], int inDegree[], int n)
{
    int i,j;
    for(i=0;i<n;++i)
    {
        if(inDegree[i] == 0)
        {
            inDegree[i] = -1;
            TOrder[k++] = i;


            for(j=0;j<n;++j)
                if(A[i][j] == 1 && inDegree[j] != -1)
                    inDegree[j]--;


            i=-1;
        }
    }
}


int main()
{
    int A[MAX][MAX], inDegree[MAX], n,i,j;


    printf("No. of Nodes: ");
    scanf("%d",&n);


    for(i=0;i<n;++i)
        inDegree[i] = 0;


    printf("Enter the Adjacency Matrix:-\n");
    for(i=0;i<n;++i)
        for(j=0;j<n;++j){
            scanf("%d",&A[i][j]);
            if(A[i][j]==1) ++inDegree[j];
        }


    topologicalSort(A,inDegree,n);


    if(k == n)
    {
        printf("\nTopological Ordering is: ");
        for(i=0; i<k; ++i)
            printf("%d ",TOrder[i]);
    }
    else
        printf("\nTopological Ordering Not Possible");


    return 0;
}
