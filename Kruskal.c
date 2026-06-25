#include<stdio.h>
#include<stdlib.h>
int find(int v, int parent[]){
    while(parent[v]!=v)
        v = parent[v];
    return v;
}
void kruskals(int n, int cost[n][n], int parent[]){
    int count, sum, min, u, v, v1, v2, k, source;
    k = 0;
    count = 0;
    sum = 0;
    int table[n][2];
    min = 999;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cost[i][j]!=0 && cost[i][j]<min){
                source = i;
                min = cost[i][j];
            }
        }
    }
    printf("Source = %d", source);
    while(count<(n-1)){
        min = 999;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(cost[i][j]!=0 && cost[i][j]<min){
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        v1 = find(u, parent);
        v2 = find(v, parent);
        if(v1!=v2 && (v!=source)){
            table[k][0] = u;
            table[k][1] = v;
            k++;
            sum = sum+cost[u][v];
            count++;
            parent[v] = u;
        }
        cost[u][v] = cost[u][v] = 999;

    }
    printf("The cost of the spanning tree = %d\n", sum);
    printf("\n The spanning tree:\n");
    for(int i=0;i<(n-1);i++){
        printf("\n%d -> %d", table[i][0], table[i][1]);
    }
}
void main(){
    int n;
    printf("Enter the no. of nodes:");
    scanf("%d", &n);
    int cost[n][n], parent[n];
    printf("\n Enter the adjacency matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &cost[i][j]);
        }
        parent[i] = i;
    }
    kruskals(n, cost, parent);
}
