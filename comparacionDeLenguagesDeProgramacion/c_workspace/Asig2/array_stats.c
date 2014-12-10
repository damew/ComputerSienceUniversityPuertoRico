/*
 * Ricardo J Mojica Rivera
 * 841-07-5094
 * September 24, 2014
 * array_stats.c
 * The program ask for ten integer value.  Them get minimum,
 * avarage with 1 decimal, and count odd number.
 */

#include <stdio.h>
#include <stdlib.h>

#define LENTG 10

void fillArray(int *arr);
int minimum(int arr[]);
float avarage(int arr[]);
int sumOdd(int *arr);

int main(void){
    int iarr[LENTG];

    printf("Enter the 10 elements: ");
    fillArray(iarr);

    printf("\nThe minimum element is %d.\n", minimum(iarr));
    printf("The average of the elements is %.1f.\n", avarage(iarr));
    printf("There are %d odd elements.\n", sumOdd(iarr));

    printf("\nThanks for using this program.\n");
}

// Use pointer to fill an array
void fillArray(int *arr){
    for(int i = 0 ; i < LENTG ; i++)
        scanf("%d", (arr+i));
}

// Get the minimum of the array
// and return the integer value
int minimum(int arr[]){
    int amin = arr[0];
    for(int i = 1 ; i < LENTG ; i++){
        if (amin > arr[i])
            amin = arr[i];
    }
    return amin;
}

// Get the average of the array
// and return the float value
float avarage(int arr[]){
    int asum = 0;
    for(int i = 0 ; i < LENTG ; i++)
        asum += arr[i];
    return (float)asum/LENTG;
}

// Calculate all the odds number
int sumOdd(int *arr){
    int aosum = 0;
    for(int i = 0 ; i < LENTG ; i++){
        if (abs(*(arr+i))%2 == 1)
            aosum++;
    }
    return aosum;
}

