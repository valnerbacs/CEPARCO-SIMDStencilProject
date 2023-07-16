//Bacayan, Vincent Alner J. S11
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


void calculateY(int ARRAY_SIZE, long long int* X, long long int* Y) {
    int i;
    for (i = 0; i < ARRAY_SIZE - 6; i ++) {
        Y[i] = X[i] + X[i + 1] + X[i + 2] + X[i + 3] + X[i + 4] + X[i + 5] + X[i + 6];
    }
} 


extern void calculateYx86(int ARRAY_SIZE, long long int* X, long long int* Y);
extern void calculateYSIMD(int ARRAY_SIZE, long long int* X, long long int* Y);

int main() {
    int ARRAY_SIZE = pow(2, 20);
    int ARRAY_BYTES = ARRAY_SIZE * sizeof(long long int);
    long long int* X = (long long int*)malloc(ARRAY_BYTES);
    long long int* Y = (long long int*)malloc(ARRAY_BYTES);
    long long int* Yx86 = (long long int*)malloc(ARRAY_BYTES);
    long long int* YSIMD = (long long int*)malloc(ARRAY_BYTES);

    for (int i = 0; i < ARRAY_SIZE; i++) {                  //initialize X values
        X[i] = i + 1;
    }
    
    //Clock Variables
    clock_t start, end;
    double time_taken;
    double timesum = 0;

    //C Implementation call
    printf("------------------------ C PROGRAM ------------------------");
    for (int i = 0; i < 30; i++)
    {
        start = clock();

        calculateY(ARRAY_SIZE, X, Y);

        end = clock();
        time_taken = ((double)(end - start)) * 1e3 / CLOCKS_PER_SEC;
        printf("Run %d : %fms \t", i, time_taken);
        timesum = timesum + time_taken;
    }

    printf("\n\nC function took %fms for array size %d\n\n", timesum / 30, ARRAY_SIZE);
    timesum = 0;    

    printf("Y: ");
    for (int i = 0; i < 5; i++) {
        printf("%lld ", Y[i]);
    }
    printf("\n");

    //x86-64 Implementation Call
    printf("--------------------- X86-64 PROGRAM ----------------------");
    for (int i = 0; i < 30; i++)
    {
        start = clock();

        calculateYx86(ARRAY_SIZE, X, Y);

        end = clock();
        time_taken = ((double)(end - start)) * 1e3 / CLOCKS_PER_SEC;
        printf("Run %d : %fms \t", i, time_taken);
        timesum = timesum + time_taken;
    }

    printf("\n\nx86-64 function took %fms for array size %d\n\n", timesum / 30, ARRAY_SIZE);
    timesum = 0;

    printf("Y: ");
    for (int i = 0; i < 5; i++) {
        printf("%lld ", Y[i]);
    }
    printf("\n");

    //SIMD implementation call
    printf("---------------------- SIMD PROGRAM ----------------------");
    for (int i = 0; i < 30; i++)
    {
        start = clock();

        calculateYSIMD(ARRAY_SIZE, X, Y);

        end = clock();
        time_taken = ((double)(end - start)) * 1e3 / CLOCKS_PER_SEC;
        printf("Run %d : %fms \t", i, time_taken);
        timesum = timesum + time_taken;
    }

    printf("\n\nx86-64 function took %fms for array size %d\n\n", timesum / 30, ARRAY_SIZE);
    timesum = 0;

    printf("Y: ");
    for (int i = 0; i < 5; i++) {
        printf("%lld ", Y[i]);
    }
    printf("\n");
    free(X);
    free(Y);
    return 0;
    }
