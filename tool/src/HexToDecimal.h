// h2d(*arr hex)

// this is a function that inputs an array value
// in hexidecimal form and outputs its decimal equivalent

#include <stdio.h>
#include <string.h>

#define LENGTH 10

int h2d(){ //ex. hex: [2,4,E]
    int res = 0;
    char hex[LENGTH];
    
    printf("Enter a hexidecimal number to convert to decimal:");
    scanf("%s", hex);
    // turn hex into an array

    int len = (int) strlen(hex);
    //printf("%d\n", len);
    /*
    for(int i = 0; i < len; i++){
        printf("%d\n", hex[i]);
    }
    */
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
    /*
    for(int i = 0; i < len; i++){
        printf("%d\n", hex[i]);
    }
    */
    //iterate:
    for(int i = 0; i < len; i++){
    // if not last iteration: add carry to hex value and multiply by 16
        if(i != len - 1){
            res = (res + hex[i]) * 16;
        }
        else{ // if last carry: only add carry to hex value
            res = res + hex[i];
        }
    }
    return res;
}