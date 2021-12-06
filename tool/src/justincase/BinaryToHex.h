// b2h()

// this is a function that inputs an integer value
// in binary form and outputs its hexidecimal equivalent

#include <stdio.h>

#define bits 16

void b2h(){
    // input binary
    unsigned long binary;
    printf("Enter a binary number to convert to hexidecimal:");
    scanf("%lu", &binary);
    // loop backwards
    // store bits into an array
    int binary_array[bits] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    unsigned long temp = binary;
	int index = bits-1;
	while(temp > 0){
		binary_array[index] = temp % 2;
		temp /= 10;
		index--;
	}
    // grab groups of 4 values and store together
    int group[4] = {0,0,0,0};
    int dec_array[4]; // array that will store the decimal values of binary groups
    int count = 3;
	for (int i = bits-1; i >= 0; i -= 4){ // index 12-15, 8-11, 4-7, 0-3 
        group[3] = binary_array[i];
        group[2] = binary_array[i-1];
        group[1] = binary_array[i-2];
        group[0] = binary_array[i-3];
        // remove the binary group from the list
        unsigned long group_binary = 0;
        for(int i = 0; i < 4; i++){
            group_binary = group_binary * 10 + group[i];
        }
        // compute the values of the binary groups
        int group_val = b2d(group_binary);
        // store decimal equivalent
        dec_array[count] = group_val;
        count--;
	}
    int hasValue = 0; // pseudo-boolean variable to avoid printing leading 0's
    for(int i = 0; i < 4; i++){ // print out the values in a single line
        // convert to corresponding letter where appropriate
        if(dec_array[i] == 10){
            printf("A");
            hasValue = 1;
        }
        else if(dec_array[i] == 11){
            printf("B");
            hasValue = 1;
        }
        else if(dec_array[i] == 12){
            printf("C");
            hasValue = 1;
        }
        else if(dec_array[i] == 13){
            printf("D");
            hasValue = 1;
        }
        else if(dec_array[i] == 14){
            printf("E");
            hasValue = 1;
        }
        else if(dec_array[i] == 15){
            printf("F");
            hasValue = 1;
        }
        else if(dec_array[i] != 0){
            printf("%d", dec_array[i]);
            hasValue = 1;
        }
        else if(hasValue != 0) // case in which is 0 but not leading
            printf("%d", dec_array[i]);
    }
}