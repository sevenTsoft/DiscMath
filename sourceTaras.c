#include "sourceTaras.h"
#include <stdio.h>
#include <stdlib.h>

void computer_group()
{
    int sizeA = 0, i;
    float *setA = NULL;
    float setAl;
    printf("\nInput a group of integers to input set A. Input -1 if you want to stop writing numbers.\n");
    printf("\nInput one integer: ");
    while(scanf("%f", &setAl) == 1 && setAl != -1)
    {
        setA = realloc(setA, (sizeA + 1) * sizeof(float));
        setA[sizeA++] = setAl;
        printf("Input one integer: ");
    }
    printf("\nSet A = {");
    for(i=0; i < sizeA; i++)
    {
        printf("%.0f", setA[i]);
        if (i<sizeA-1)
        {
            printf(", ");
        }
    }
    printf("}\n");
    int sizeU= 0;
    float *setU = NULL;
    float setUl;
    printf("\nWrite a group of real numbers to input Universum. Write -1 if you want to stop writing numbers.\n");
    printf("\nInput one integer: ");
    while(scanf("%f", &setUl) == 1 && setUl != -1)
    {
        setU = realloc(setU, (sizeU+1) * sizeof(float));
        setU[sizeU++] = setUl;
        printf("Input one integer: ");
    }
    printf("\nU = {");
    for(i=0; i<sizeU; i++)
    {
        printf("%.0f", setU[i]);
        if (i<sizeU-1)
        {
            printf(", ");
        }
    }
    printf("}\n");
    int same[sizeU];
    for(i = 0; i < sizeU; i++)
    {
        same[i]=0;
        for (int j = 0; j<sizeA; j++)
        {
            if(setA[j]==setU[i])
            {
                same[i]=1;
                break;
            }
            else
            {
                same[i]=0;
            }
        }
    }
    printf("\nWhile set U is Universum, set A in computer expression is: ");
    for(i = 0; i < sizeU; i++)
    {
        printf("%d", same[i]);
    }
    printf("\n");
}
