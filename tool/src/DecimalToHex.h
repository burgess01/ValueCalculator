// d2h()

// this is a function that inputs an integer value
// in decimal form and outputs its hexidecimal equivalent

#include <stdio.h>

#define LENGTH 10

int d2h(){
    // input decimal value
    int decimal;
    char hex[LENGTH];
    printf("Enter a decimal number to convert to hexidecimal:");
    scanf("%d", &decimal);
    // loop, dividing by 16 each time
    int rem = 0, i = 0;
    while(decimal > 0){
        // store remainder of division
        rem = decimal % 16;
        //printf("%d\n", rem);
        decimal = decimal / 16;
        //printf("%d\n", decimal);
        // turn values bigger than 10 into letter eq.
        if(rem > 9){
            if(rem == 10){
                hex[i] = 'A';
            }
            else if(rem == 11){
                hex[i] = 'B';
            }
            else if(rem == 12){
                hex[i] = 'C';
            }
            else if(rem == 13){
                hex[i] = 'D';
            }
            else if(rem == 14){
                hex[i] = 'E';
            }
            else if(rem == 15){
                hex[i] = 'F';
            }
        }
        else{
            hex[i] = rem;
        }
        //printf("%c",hex[i]);
        i++;
    }
    // reverse values and store in combined return var
    for(int j = i; j >= 0; j--){
        //printf("%c\n", hex[j]);
        if (hex[j] > 0 && hex[j] < 10){
            printf("%d", hex[j]);
            //printf("Working");
        }
        else{
            printf("%c", hex[j]);
        }
    }
    printf("\n");
    // return output
    return 0;
}