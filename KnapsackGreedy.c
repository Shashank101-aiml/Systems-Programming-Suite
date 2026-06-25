#include<stdio.h>
void swap(float*a, float*b){
    float temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int n;
    float capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);

    float weight[n], profit[n], ratio[n], fraction[n];
    printf("Enter weights: \n");
    for(int i = 0; i < n; i++){
        scanf("%f", &weight[i]);
    }
    printf("Enter profits:\n");
    for(int i = 0; i < n;i++){
        scanf("%f", &profit[i]);
        ratio[i] = profit[i] / weight[i];
        fraction[i] = 0;
    }
    printf("Enter knapasack capacity: ");
    scanf("%f", &capacity);

    for(int i = 0; i < n - 1; i++){
     for(int j = 0; j < n - 1; j++){
        if(ratio[j] < ratio[j + 1]){
            swap(&ratio[j], &ratio[j +1]);
            swap(&profit[j], &profit[j + 1]);
            swap(&weight[j], &weight[j +1]);
        }
     }   
    }
    float totalProfit  = 0;
    for(int i = 0; i < n && capacity > 0;i++){
        if(weight[i] <= capacity){
            fraction[i] = 1;
            totalProfit += profit[i];
            capacity -= weight[i];
        } else {
            fraction[i] = capacity / weight[i];
            totalProfit += profit[i]*fraction[i];
            capacity = 0;
        }
    }
    printf("\n Fraction of items taken : \n");
    for(int i = 0; i < n; i++){
        printf("Item %d: %.2f\n",i + 1, fraction[i] );
    }
    printf("Total Profit: %.2f\n", totalProfit);
    return 0;
}
