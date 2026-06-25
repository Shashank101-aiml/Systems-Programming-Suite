#include<stdio.h>
#define max(a,b) ((a<b)?(b):(a))


void dynamicKnapsack(int profit[], int weight[], int N, int M)
{
    int i,w;
    int dp[N+1][M+1];


    //Building DP Table
    for(i=0;i<=N;++i)
        for(w=0;w<=M;++w)
        {
            if(i==0||w==0)
                dp[i][w] = 0;
            else if(w<weight[i-1])
                dp[i][w] = dp[i-1][w];
            else
                dp[i][w] = max(dp[i-1][w], profit[i-1]+dp[i-1][w-weight[i-1]]);
        }

 
    int result = dp[N][M];
    printf("\nMaximum Profit: %d",result);
    printf("\nSolution Vector X[]: ");


    short X[N];
    for(int i=0;i<N;++i)
        X[i] = 0;


    //Trace Back the Table
    for(int i=N;(result>0 && i>0); i--)
    {
        if(result == dp[i-1][w-1])
            continue;


        X[i-1] = 1;
        result -= profit[i-1];
        w -= weight[i-1];
    }


    for(int i=0;i<N;++i)
        printf("%hd ",X[i]);
}


int main()
{
    int N;
    printf("Enter No. of Objects: ");
    scanf("%d",&N);


    int profit[N];
    printf("Enter Profits: ");
    for(int i=0;i<N;++i) scanf("%d",&profit[i]);


    int weight[N];
    printf("Enter Weights: ");
    for(int i=0;i<N;++i) scanf("%d",&weight[i]);


    int M;
    printf("Enter Knapsack Capacity: ");
    scanf("%d",&M);


    dynamicKnapsack(profit,weight,N,M);


    return 0;
}
