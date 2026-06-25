#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void selection_sort(int a[], int n){
    for(int i = 0;i<n-1;i++)
    {
        int min_idx=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[min_idx]>a[j])
            {
                min_idx=j;
            }

        }
        int temp = a[min_idx];
        a[min_idx] = a[i];
        a[i] = temp;
    }
}
int main(){
    int n_value[]={5000,6000,10000,20000,50000};
    int num_test = sizeof(n_value) / sizeof(n_value[0]);
    printf('\n Time taken for selection sort: \n');
    for(int t = 0;t < num_test;t++)
    {
        int n = n_value[t];
        int *a = (int*)malloc(n*sizeof(int));

        srand(time(0));
        for(int i = 0;i<n;i++)
        {
            a[i] = rand() % 1000;
        }
        clock_t start_time = clock();
        selection_sort(a,n);
        clock_t end_time = clock();
        double time_taken = ((double)(end_time - start_time))/CLOCKS_PER_SEC;
        printf("Sorted %d elements in %.6f seconds. \n",n, time_taken);
        free(a);
    }
    return 0;
}
