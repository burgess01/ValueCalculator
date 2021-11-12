// h2b()

// this is a function that inputs an array value
// in hexidecimal form and outputs its binary equivalent

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define LENGTH 10

int h2b(){
    int res = 0;
    char hex[LENGTH];
    int binary[LENGTH];
    printf("Enter a hexidecimal number to convert to binary:");
    scanf("%s", hex);
    // split hex into an array
    int len = (int) strlen(hex);
    // iterate through, turning letter values to numbers
    for(int i = 0; i < len; i++){
        if(hex[i] == 'A'){
            hex[i] = 10;
        }
        else if(hex[i] == 'B'){
            hex[i] = 11;
        }
        else if(hex[i] == 'C'){
            hex[i] = 12;
        }
        else if(hex[i] == 'D'){
            hex[i] = 13;
        }
        else if(hex[i] == 'E'){
            hex[i] = 14;
        }
        else if(hex[i] == 'F'){
            hex[i] = 15;
        }
        else{
            hex[i] = hex[i] - 48;
        }
    }
    for(int i = 0; i < len; i++){
        printf("%d\n", hex[i]);
    }
    // find binary equivalent for each option
    for(int i = 0; i < len; i++){
        int value = 0, count = 0, res = 0;
        int decimal = hex[i];
	    unsigned long num = 0;
        while(decimal > 0){
            num = num * 10 + (decimal % 2);
            decimal = decimal / 2;
            //printf("%lu\t%d\n", num, decimal);
            count++;
        }
        unsigned long temp = 0;
        while(num != 0){ // code for reversing int
            temp = num % 10;
            res = res * 10 + temp;
            num = num / 10;
            //printf("%lu\t%lu\t%lu\n", temp, res, num);
        }
        // if the lenth of binary isn't long enough, add zeroes to correct for zero dropping
        int check = 0;
        unsigned long resCheck = res;
        while(resCheck > 0){ //get the number of values
            resCheck = resCheck / 10;
            check++;
        }
        //printf("%d\t%d\n", count, check);
        if(check != 4){ // if the number of values that should be in it is smaller than what is actually in it:
            count =  4 - check; // get the difference
            res = res * pow(10, count); // multiply: 1 * 1000 = 1000 in binary = 8 in decimal
        }
        printf("%d\n", res);
        binary[i] = res;
    }
    // return output
    for(int i = 0; i < len; i++){
        printf("%d\n", binary[i]);
    }
    unsigned long result;
    if(len == 1){
        // combine into one variable
        for(int i = 0; i < len; i++){
            result = (result * 10) + binary[i];
        }
    }
    else{
        result = binary[0];
    }
    return result;
}