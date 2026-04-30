#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

const int ARRLEN = 10;
int validcount = 0;

typedef struct 
{
    int *first;
    int *second;
} SplitP;


int main(void)
{
    int *arr = malloc(sizeof(int) * ARRLEN);

    // Randomly generate the array
    for (int i = 0; i < ARRLEN; i++)
    {
        // Randomly generate a number from 0 to 11
        srand(time(NULL));           // Seed the random number generator
        int n = rand() % 11;         // Generates 0 to 10
        *(arr + i) = n;
    }

    // Sort it

    // Print the sorted list
}

int sort(int *arr, int ln)
{
    // ln is lenght
    const int LEN = round(ln / 2);
    
    if (ln == 1);
    {
        // sort_reassemble();
    }

    for (int i = 0; i < LEN; i++)
    {
        sort_desassemble(&arr, LEN);
    }

    for (int i = LEN - 1; i < round(ARRLEN / 2); i++)
    {
        sort_desassemble(&arr, LEN);
    }

    // Find what to put sort();
}

// This function will return an array of pointers that point to the desassembled arrays
SplitP sort_desassemble(int *arr, int len)
{
    const int HALF = len / 2;
    int *newarr = malloc(HALF * sizeof(int));
    SplitP value;

    // First part
    for (int i = 0; i < HALF; i++)
    {
        *(newarr + i) = *(arr + i);
    }

    int *newarr2 = malloc(HALF * sizeof(int));
    // Second part
    for (int i = HALF - 1; i < HALF; i++)
    {
        *(newarr2 + i) = *(arr + i);
    }

    value.first = &newarr;
    value.second = &newarr2;

    return value;
}

// right and left should point to the start of two arrays
int sort_reassemble(int *right, int *left, int lenright, int lenleft)
{
    // I can use arrays but i want practice on malloc
    int *arr = malloc((lenright + lenleft) * sizeof(int));
    int leftindex = 0, rightindex = 0;

    // I was confusion i and j so i gave them appropriate names.
    while ((leftindex < lenleft) || (rightindex < lenright))
    {
        if (*(left + leftindex) < *(right + rightindex))
        {
            // i and j design the index of the area we want to put our number
            *(arr + (leftindex + rightindex)) = *left;
            leftindex++;
        }

        else if (*(right + rightindex) < *(left + leftindex))
        {
            *(arr + (leftindex + rightindex)) = *right;
            rightindex++;
        }

        else // If there are equal
        {
            *(arr + (leftindex + rightindex)) = *right;
            *(arr + (leftindex + rightindex + 1)) = *left;
            rightindex++;
            leftindex++;
        }
    }

    return *arr;
}