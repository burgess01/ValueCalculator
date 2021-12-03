#include <stdio.h>
#include <stdlib.h>

void display(int *input, int length){
    for(int i = 0; i<length;i++){
        printf("%d", input[i]);
    }
    printf("\n");
}

void add(int *input1,int *input2, int size){
    int tempSum = 0;
    int *carry = (int *) malloc(size+1*sizeof(int));
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

void b2d(int *output, int size){
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

void leftShiftTwoArrays(int *a,int *q, int qcount, int acount){
    // first input will be a and the second is q
    int size = qcount+acount;
    int j = 1;
    int k = 0;
    for (int i = 1; i < size; i++){
        if(i<acount){
            int temp = 0;
            temp = a[j];
            a[j] = a[j-1];
            a[j-1] = temp;
            j++;
        }
        if(i==acount){
            int temp = 0;
            temp = a[j-1];
            a[j-1] = q[k];
            q[k] = temp;
            k++;
        }
        if(i>acount && i < (size)-1){
            int temp = 0;
            temp = q[k];
            q[k] = q[k-1];
            q[k-1] = temp;
            k++;
        }
        if(i == (size)-1){
            int temp = 0;
            temp = q[k-1];
            q[k-1] = q[k];
            q[k] = 0;
            k++;
        }
    }
}

void twoscomplement(int *input, int *output, int count){
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
    display(one,count);
    add(one,output,count);

}

int main(){
    int input1 = 5;
    int input2 = 2;
    int copy_input1 = input1;
    int copy_input2 = input2;
    int dividend_counter = 0;
    while(copy_input1>0){
        copy_input1 = copy_input1/2;
        dividend_counter++;
    }
    int i = dividend_counter-1;
    int *dividend = (int *) malloc(dividend_counter*sizeof(int));
    while(input1>0){
        dividend[i] = input1 % 2;
        input1 = input1/2;
        i = i-1;
    }
    int divisor_counter = dividend_counter + 1; //create an extra space in the array
    i = divisor_counter-1;
    int *divisor = (int *) malloc(divisor_counter*sizeof(int));
    int *quotient = (int *) malloc(divisor_counter*sizeof(int));
    int *neg_divisor = (int *) malloc(divisor_counter*sizeof(int));
    while(input2>0){
        divisor[i] = input2 % 2;
        input2 = input2/2;
        i = i-1;
    }
    divisor[0] = 0;
    // divident/divisor = quotient 
    // convert decimal to binary list

    printf("The dividend counter is %d\n", dividend_counter);
    printf("The divisor counter is %d\n", divisor_counter);
    printf("\n");
    printf("Original Dividend \n");
    display(dividend, dividend_counter);
    printf("Original Divisor \n");
    display(divisor, divisor_counter);
    printf("\n");
    //make a copy of divisor count
    int dcount = dividend_counter;
    // find the negative value of the divisor in binary
    twoscomplement(divisor,neg_divisor, divisor_counter);
    // print the negative divisor
    printf("Negative Divisor \n");
    display(neg_divisor, divisor_counter);
    // actually compute the multiplication algorithm
    while(dcount>0){
        // left shift quotient and dividend together
        printf("The counter is  %d\n", dcount);
        printf("\n");
        leftShiftTwoArrays(quotient,dividend,dividend_counter,divisor_counter);
        add(neg_divisor,quotient,divisor_counter);
        printf("Quotient before the ifs is : \n");
        display(quotient,divisor_counter);
        if(quotient[0] == 1){
            printf("the first digit of quotient is 1\n");
            dividend[dividend_counter-1] = 0;
            printf("dividend is: \n");
            display(dividend,dividend_counter);
            printf("quotient is: \n");
            display(quotient,divisor_counter);
            add(divisor,quotient,divisor_counter);
            printf("adding quotient and divisor gets you: \n");
            display(quotient,divisor_counter);
        }
        else if(quotient[0] == 0){
            printf("the first digit of quotient is 0\n");
            dividend[dividend_counter-1] = 1;
            printf("dividend is: \n");
            display(dividend,dividend_counter);
            printf("quotient is: \n");
            display(quotient,divisor_counter);
        }
        // decriment the counter
        dcount = dcount-1;
        // subtract divisor from quotient 
        // if the first bit in quotient is 0: set the last bit in dividend to 1 
    }
    printf("Final dividend is: \n");
    display(dividend,dividend_counter);
    b2d(dividend,dividend_counter);
    printf("Final Quotient is: \n");
    display(quotient,divisor_counter);
    b2d(quotient,divisor_counter);
}

