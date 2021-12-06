#pragma once
#include <stdio.h>
#include <stdlib.h>

void internaladd(int *input1,int *input2, int arrsize){
    int tempSum = 0;
    int *carry = (int *) malloc(arrsize+1*sizeof(int));
    for (int i = arrsize-1; i>=0; i = i-1){
        tempSum = carry[i]+input1[i]+input2[i];
        if(tempSum == 0){
            input2[i] = 0;
            carry[i-1] = 0;
        }
        else if(tempSum == 1){
            input2[i] = 1;
           // printf("%d\t%d\n",j, input2[j]);
            carry[i-1] = 0;
        }
        else if(tempSum == 2){
            input2[i] = 0;
            carry[i-1] = 1;
        }
        else{
            input2[i] = 1;
            carry[i-1] = 1;
        }
    }
}