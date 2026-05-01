#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int *first;
    int *second;
} SplitP;

void sort(int *arr, int ln);
SplitP sort_desassemble(int *arr, int len);
int *sort_reassemble(int *right, int *left, int lenright, int lenleft);

int main(void)
{
    printf("length of the random array? ");
    const int LEN ;
    do 
    {
        scanf("%i", &LEN);
    }
    while (LEN < 1);
    
    int *arr = (int*)malloc(sizeof(int) * LEN);

    // Randomly generate the array
    srand(time(NULL)); // Seed ONCE before the loop

    for (int i = 0; i < LEN; i++)
    {
        int n = rand() % 11;  // Generates 0 to 10
        *(arr + i) = n;
    }

    // Print the unsorted
    printf("unsorted: ");
    // Print the sorted list
    for (int i = 0; i < LEN; i++)
    {
        printf("%i,", *(arr + i));
    }
    printf("\n");

    // Sort it
    sort(arr, LEN);
    
    printf("sorted: ");
    // Print the sorted list
    for (int i = 0; i < LEN; i++)
    {
        printf("%i,", *(arr + i));
    }
    printf("\n");
}

void sort(int *arr, int ln)
{
    // Base
    if (ln <= 1)
    {
        return;
    }
    
    // get the two parts
    SplitP val = sort_desassemble(arr, ln);
    int firstln = 0, secondln = 0;

    // First will always be the same
    firstln = ln / 2;

    if (ln % 2 == 0)
    {
       secondln = ln / 2;
    }
    else // ln is odd 
    {
        secondln = ln % 2 + firstln;
    }

    sort(val.first, firstln);
    sort(val.second, secondln);

    // Merge
    int *merge = sort_reassemble(val.second, val.first, firstln, secondln);

    // Copy it to the real thing (someone on Overflow said this is better than a loop)
    memcpy(arr, merge, sizeof arr[0] * ln);

    // Free the values
    free(val.first);
    free(val.second);
    free(merge);
}

// This function will return an array of pointers that point to the desassembled arrays
SplitP sort_desassemble(int *arr, int len)
{
    const int HALF = len / 2;
    int* newarr = malloc(sizeof newarr[0] *  HALF);
    SplitP value;

    // First part
    for (int i = 0; i < HALF; i++)
    {
        *(newarr + i) = arr[i];
    }

    int *newarr2 = malloc((len - HALF) * sizeof(int)); 
    // Second part
    for (int i = HALF; i < len; i++)
    {
        *(newarr2 + (i - HALF)) = arr[i];
    }

    value.first = newarr;
    value.second = newarr2;

    return value;
}

// right and left should point to the start of two arrays
int *sort_reassemble(int *right, int *left, int lenright, int lenleft)
{
    // I can use arrays but i want practice on malloc
    int *arr = malloc((lenright + lenleft) * sizeof(int));
    int leftindex = 0, rightindex = 0;
    int k = 0;

    // I was confusion i and j so i gave them appropriate names.
    while ((leftindex < lenleft) && (rightindex < lenright))
    {
        if (*(left + leftindex) <= *(right + rightindex))
        {
            *(arr + k) = *(left + leftindex);
            leftindex++;
        }
        else 
        {
            *(arr + k) = *(right + rightindex);
            rightindex++;
        }
        k++;
    }

    // I love stack overflow
    // Append remaining elements from left array if any
    while (leftindex < lenleft) {
        *(arr + k) = *(left + leftindex);
        leftindex++;
        k++;
    }

    // Append remaining elements from right array if any
    while (rightindex < lenright) {
        *(arr + k) = *(right + rightindex);
        rightindex++;
        k++;
    }

    return arr;
}