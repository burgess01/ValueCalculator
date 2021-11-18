// This will contain the adding function!
// add(num1, num2)
// Assuming that the bits is 16 or less
#define bits 16
unsigned long add(unsigned long num1, unsigned long num2){
    printf("num1 is: %lu \n", num1);
    printf("num2 is: %lu \n", num2); 
    unsigned long res = 0;
	int decimal1[bits] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
	int decimal2[bits] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
	int output[bits] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
	unsigned long temp = num1;
	int index = bits-1;
	while(temp > 0){
		decimal1[index] = temp % 2;
		temp /= 10;
		index--;
	}
	for (int i = 0; i < bits; i++){
		printf("%d ", decimal1[i]);
	}
	printf("\n");
	temp = num2;
	index = bits-1;
	while(temp > 0){
		decimal2[index] = temp % 2;
		temp /= 10;
		index--;
	}
	for (int i = 0; i < bits; i++){
		printf("%d ", decimal2[i]);
	}
	printf("\n");
	// add logic for adding the two inputs and bind the output to the output array.
	int carry_in = 0;
	int carry_out = 0;
	for(int i = bits-1; i > 0; i--){
		if (carry_out == 1){
			carry_in = 1;
			carry_out = 0;
		}
		if(decimal1[i] == 0 && decimal2[i] == 0){
			output[i] = 0;
		}
		else if(decimal1[i] == 1 && decimal2[i] == 1){
			output[i] = 0;
			carry_out = 1;
		}
		else {
			output[i] = 1;
		}
		// Write case to add 1 if carry is true
		if(carry_in == 1){
			if(output[i] == 1){
				output[i] = 0;
				carry_out = 1;
			}
			else
				output[i] = 1;
		}
		carry_in = 0;
	}
	// convert the output array to the decimal representation and store the result in res.
	unsigned long binary_sum = 0;
	for(int i = 0; i < bits; i++){
		binary_sum = binary_sum * 10 + output[i];
	}
    res = binary_sum;
    return res;
}