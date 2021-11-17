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
    int binary[LENGTH * 4];
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
    // convert from decimal to binary
    for(int i = 0; i < len; i++){
        res = d2b(hex[i]);
        // add values one by one to binary[]
        for(int i = 0; i < 4; i++)
            // if len res is less than 4:
            // loop the difference and add those to binary[]
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
    // print out list one by one on same line
    return 0;
}