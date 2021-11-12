// d2b(int decimal)
// this is a function that inputs an integer value
// in decimal form and outputs its binary equivalent

#include <stdio.h>
#include <math.h>

int d2b(){
    int decimal = 0;
    printf("Enter a decimal number to convert to binary:");
    scanf("%d", &decimal);
    int value = 0, count = 0, res = 0;
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
	if(count != check){ // if the number of values that should be in it is smaller than what is actually in it:
		count = count - check; // get the difference
		res = res * pow(10, count); // multiply: 1 * 1000 = 1000 in binary = 8 in decimal
	}

	return res;
}