#pragma once
#include <stdio.h>

int internalb2d(int *output, int count){
    int sum = 0;
    for (int i = 0; i < count; i++){
        if(i==count-1){
            sum = output[i]+sum;
        }
        else{
            sum = (output[i]+sum)*2;
        }
    }
    return sum;
}