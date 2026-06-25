#include<stdio.h>
#define I 999
int A[15][15], source, n;
void prims(){
    int table[n][2], parent[n], dist[n], visited[n];
    int min = I;
    //Choosing source based on minimum edge
    for(int i = 1; i<n;i++){
        for(int j = 0;j<n;j++){
            if(A[i][j]!=0 &A[i][j]<min){
                min = A[i][j];
                source = i;
            }
        }
    }
    for(int i = 0;i<n;i++){
        dist[i] = A[source][i];
        visited[i] = 0;
        parent[i] = source;
    }
    visited[source] = 1;
    int sum = 0;
    int k = 0;
    for(int i=1;i<n;i++){
        min = I;
        int u = -1;
        //selecting 'u' based on minimum edge
        for(int j=0;j<n;j++){
            if(visited[j] == 0){
                if(dist[j] < min){
                    min = dist[j];
                    u = j;
                }
            }
        }
        table[k][0] = u;
        table[k][1] = parent[u];
        k++;
        sum += A[u][parent[u]];
        visited[u] = 1;
        //selecting next vertex
        for(int v = 0;v<n;v++){
            if(visited[v] == 0 && A[u][v] < dist[v]){
                dist[v] = A[u][v];
                parent[v] = u;
            }
        }
    }
    if(sum>I)
        printf("Spanning Tree does not exist!");
    else{
        printf("The Minimum Spanning Tree is:\n");
        for(int i=0;i<n-1;i++)
            printf("%d -> %d\n", table[i][0], table[i][1]);
        printf("The total cost of the MST  = %d", sum);
    }
}
void main(){
    printf("Enter the no. of vertices: ");
    scanf("%d", &n);
    printf("Enter the details of the Graph:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&A[i][j]);
        }
    }
    prims();
}
