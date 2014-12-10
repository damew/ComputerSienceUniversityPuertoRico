/*
 * Ricardo J Mojica Rivera
 * 841-07-5094
 * September 24, 2014
 * fibonacci_calc.c
 * This program calculate the n number of fibonacci
 * sequence using iterative and recursion.
 */

#include <stdio.h>
#define LENGT 5

int uIterative(const int term,int *fibo);
int uRecursive(const int term, int *tempc,int *fibo);

int main(void){
    int fibo[LENGT] = {0,1}, fterm, counter = 2;

    printf("Enter a non-negative integer: ");
    scanf("%d", &fterm);

    if (fterm == 0 || fterm == 1){
        printf("The %d-th number in the Fibonacci sequence is %d.\n", fterm, fibo[fterm]);
    }else{
        printf("Using iteration, the %d-th number in the Fibonacci sequence is %d.\n", fterm, uIterative(fterm, fibo));

        // initialize before the recursive function
        fibo[2]=fibo[0];
        fibo[3]=fibo[1];

        printf("Using recursion, the %d-th number in the Fibonacci sequence is %d.\n", fterm, uRecursive(fterm, &counter, fibo));
    }
    printf("\nThanks for using this program.\n");
}

// Iterative function to get the term
int uIterative(int term,int *fibo){
    fibo[2]=fibo[0];
    fibo[3]=fibo[1];
    for(int i = 3 ; i <= term ; i++){
        fibo[4] = fibo[2] + fibo[3];
        fibo[2] = fibo[3];
        fibo[3] = fibo[4];
    }
    return fibo[4];
}

// Recursive function to get the term
int uRecursive(int term, int *tempc, int *fibo){
    *tempc += 1;
    fibo[4] = fibo[2] + fibo[3];
    fibo[2] = fibo[3];
    fibo[3] = fibo[4];
    if(*tempc != term)
        uRecursive(term, tempc, fibo);
    else
        return fibo[4];
}
