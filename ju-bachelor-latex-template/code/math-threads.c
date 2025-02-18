#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define ITERATIONS 1000000000

// shared variables between the threads!!!
double sumEven = 0.0;
double sumOdd = 0.0;

// function to compute the Even sum
void *computeSumEven(void *param) {
    double localSum = 0.0;
    for (int i = 1; i < ITERATIONS; i += 2) {
        localSum += 1.0 / (pow((double)i,2));
    }
    sumEven = localSum;
    printf("THREAD EVEN finished\n");
    return NULL;
}

// function to compute the Odd sum
void *computeSumOdd(void *param) {
    double localSum = 0.0;
    for (int i = 2; i < ITERATIONS; i += 2) {
        localSum += 1.0 / (pow((double)i,2));
    }
    sumOdd = localSum;
    printf("THREAD ODD finished\n");
    return NULL;
}

int main() {
    pthread_t tEven, tOdd; // we need two threads
    printf("It works!\n");
    double approxPI = 3.141592653589793238462643383279;
    double myPI = 0.0;

    pthread_create(&tEven, NULL, computeSumEven, NULL); // thread Even
    pthread_create(&tOdd, NULL, computeSumOdd, NULL); // thread Odd

    printf("Computing in progress...\n");

    pthread_join(tEven, NULL); // thread Even is finished
    pthread_join(tOdd, NULL); // thread Odd is finished

    double sum = sumEven + sumOdd;
    printf("SUM is: %.30lf\n", sum);
    myPI = sqrt(sum * 6);
    printf("My value for PI is: %.30lf\n", myPI);
    printf("True approx for PI: %.30lf\n", approxPI);
    return 0;
}

