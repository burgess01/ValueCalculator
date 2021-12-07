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
    printf("Enter a hexidecimal number to convert to binary:");
    scanf("%s", hex);
    // split hex into an array
    int len = strlen(hex);
    printf("The length is %d\n",len);
    int decimal[len];
    int binary[len*4];
    // iterate through, turning letter values to numbers
    for(int i = 0; i < len; i++){
        printf("Hex values are %d\n", hex[i]);
    }
    for(int i = 0; i < len; i++){
        if(hex[i] == 'A'){
            decimal[i] = 10;
        }
        else if(hex[i] == 'B'){
            decimal[i] = 11;
        }
        else if(hex[i] == 'C'){
            decimal[i] = 12;
        }
        else if(hex[i] == 'D'){
            decimal[i] = 13;
        }
        else if(hex[i] == 'E'){
            decimal[i] = 14;
        }
        else if(hex[i] == 'F'){
            decimal[i] = 15;
        }
        else{
            decimal[i] = hex[i]-48;
        }
    }

    for(int i = 0; i < len; i++){
        printf("Decimal values are %d\n", decimal[i]);
    }
    // convert from decimal to binary
    for(int i = 0; i < len; i++){
        res = d2b(decimal[i]);
        printf("res is %d\n", res);
        binary[i] = res;
        // add values one by one to binary[]
        /*
        for(int i = 0; i < 4; i++)
            // if len res is less than 4:
            // loop the difference and add those to binary[]
            binary[i] = res;
        */
    }
    
    // return output
    unsigned long result = 0;
    int i = 0;
    while(len>0){
        printf("i is %d\n", i);
        printf("%d\n", binary[i]);
        result = result + (pow(10,((len-1)*4))*binary[i]);
        len = len-1;
        i++;
    }
    
    printf("The result is %lu\n", result);
    // print out list one by one on same line
    return 0;
}