#include <stdio.h>
#define size 16

void add(int *input1,int *input2){
    int tempSum = 0;
    int carry[size+1] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};// array to capture the output
    for (int i = size-1; i>=0; i = i-1){
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

void b2d(int *output){
    int sum = 0;
    for (int i = 0; i < size; i++){
        if(i==size-1){
            sum = output[i]+sum;
        }
        else{
            sum = (output[i]+sum)*2;
        }
    }
    printf("The result is %d\n", sum);
}


int mul(int input1, int input2){
    // set input 1 = multiplicand
    int multiplicand[size] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    // set input 2 = multiplier
    int multiplier[size] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    // set Product = 0
    int product[size] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    printf("Multiplying %d and %d gives you... \n", input1, input2);
    int i = size-1;
    int multiplier_counter = 0;
    int multiplicand_counter = 0;
    // converting integers to binary and storing them in list
    while(input1>0){
        multiplicand[i] = input1 % 2;
        input1 = input1/2;
        i = i-1;
        multiplicand_counter++;
    }
    i = size-1;
    while(input2>0){
        multiplier[i] = input2 % 2;
        input2 = input2/2;
        i = i-1;
        multiplier_counter++;
    }
    // implement the multiplication algorithm

    while(multiplier_counter > 0){ //while loop executes 3 times
        if(multiplier[size-1] == 1){
           add(multiplicand,product);
        }
        //right shift multiplier
        for (int i = size-1; i>=0; i--){
            int temp = 0;
            if(i+1 < size){
                temp = multiplier[i];
                multiplier[i] = 0;
                multiplier[i+1] = temp;
            }
            else if(i+1 >= size){
                multiplier[i] = 0;
            }
        }
        // left shift the multiplicand
        for (int i = 0; i<size; i++){
            if(i-1 >= 0){
                int temp = 0;
                temp = multiplicand[i];
                multiplicand[i] = 0;
                multiplicand[i-1] = temp;
        }
    }
    multiplier_counter = multiplier_counter-1;
    }
    printf("\n");
    b2d(product);
}
    // if the last digit of multiplier is equal to 0, continue
    // if the last digit of multiplier is equal to 1,
    // add the muliplicand to product
    // right shift multiplier
    // left shift multiplicand
    // continue until R is all 0s
