// This will contain the dividing function!
// div(num1, num2)
#include <stdio.h>
#include "InternalAdder.h"
#include "Internalb2d.h"
#include "leftShiftTwoArrays.h"
#define size 16

#include <stdio.h>
#include <stdlib.h>

void twoscomplement(int *input, int *output, int count){
    // compute the twos complement by switching ones and zeros and addin one to it
    for(int i = 0;i<count;i++){
        if(input[i] == 0){
            output[i] = 1;
        }
        else{
            output[i] = 0;
        }
    }
    int *one = (int *) malloc(count*sizeof(int));
    one[count-1] = 1;
    internaladd(one,output,count);

}

void divi(int input1, int input2, int arr[]){
    // make a temp variable of inputs 1 and 2 
    int copy_input1 = input1;
    int copy_input2 = input2;
    int dividend_counter = 0;
    int divisor_counter = 0;
    // calculate the numer of bits required for dividend
    while(copy_input1>0){
        copy_input1 = copy_input1/2;
        dividend_counter++;
    }
    // calculate the numer of bits required for divisor
    while(copy_input2>0){
        copy_input2 = copy_input2/2;
        divisor_counter++;
    }
    // add 1 to divisor
    divisor_counter = divisor_counter + 1;
    int i = dividend_counter-1;
    int *dividend = (int *) malloc(dividend_counter*sizeof(int));
    // translate b2d and put in an array 
    while(input1>0){
        dividend[i] = input1 % 2;
        input1 = input1/2;
        i = i-1;
    }
    i = divisor_counter-1;
    int *divisor = (int *) malloc(divisor_counter*sizeof(int));
    int *quotient = (int *) malloc(divisor_counter*sizeof(int));
    int *neg_divisor = (int *) malloc(divisor_counter*sizeof(int));
    // translate b2d and put in an array
    while(input2>0){
        divisor[i] = input2 % 2;
        input2 = input2/2;
        i = i-1;
    }
    divisor[0] = 0;
    // divident/divisor = quotient 
    // convert decimal to binary list
    // make a copy of divisor count
    int dcount = dividend_counter;
    // find the negative value of the divisor in binary
    twoscomplement(divisor,neg_divisor, divisor_counter);
    // actually compute the multiplication algorithm
    while(dcount>0){
        // left shift quotient and dividend together
        leftShiftTwoArrays(quotient,dividend,dividend_counter,divisor_counter);
        // subtract divisor from quotient 
        internaladd(neg_divisor,quotient,divisor_counter);
        if(quotient[0] == 1){
            // change the last bit in dividend to 0
            dividend[dividend_counter-1] = 0;
            // add divisor to quotient
            internaladd(divisor,quotient,divisor_counter);
        }
        else if(quotient[0] == 0){
            // change the last bit in dividend to 1
            dividend[dividend_counter-1] = 1;
        }
        // decriment the counter
        dcount = dcount-1;
        // if the first bit in quotient is 0: set the last bit in dividend to 1 
    }
    int q = internalb2d(quotient,divisor_counter);
    int d = internalb2d(dividend,dividend_counter);
    arr[0] = d;
    arr[1] = q;
}