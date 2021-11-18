// main file for the translator program

#include <stdio.h>

#include "BinaryToDecimal.h"
//#include "BinaryToHex.h"
#include "DecimalToBinary.h"
#include "DecimalToHex.h"
#include "HexToBinary.h"
#include "HexToDecimal.h"

#include "Add.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"

int main(){
    int choice = 0, choice2 = 0, choice3 = 0;
    while(1){
        printf("---------------------------------\n");
        printf("Enter:\n(1) to use the value converter\n(2) to use the calculator\n(3) to exit:");
		scanf("%d", &choice3);
        if (choice3 == 1){
            printf("---------------------------------\n");
            printf("Enter:\n(1) to convert from binary\n(2) to convert from decimal\n(3) to convert from hexadecimal\n(4) to exit:");
            scanf("%d", &choice);
            getchar();
            if (choice == 1){ // from bin
                // ask if to dec or hex
                printf("---------------------------------\n");
                printf("Enter (1) to convert to decimal or (2) to convert to hexadecimal:");
                scanf("%d", &choice2);
                if (choice2 == 1){ // to dec
                    printf("Enter a binary number to convert to decimal:");
                    unsigned long binary = 0;
                    scanf("%lu", &binary);
                    int res = b2d(binary);
                    printf("%d\n", res);
                    printf("\n");
                }
                else if(choice2 == 2){ // to hex
                    //int res = b2h();
                    //printf("%d\n", res);
                    //printf("\n");
                }
                else{
                    break;
                }			
            }
            else if (choice == 2){ // from dec
                // ask if to bin or hex
                printf("---------------------------------\n");
                printf("Enter (1) to convert to binary\n\tor (2) to convert to hexadecimal:");
                scanf("%d", &choice2);
                if (choice2 == 1){ // to bin
                    int decimal = 0;
                    printf("Enter a decimal number to convert to binary:");
                    scanf("%d", &decimal);
                    unsigned long res = d2b(decimal);
                    printf("%lu\n", res);
                    printf("\n");  
                }
                else if (choice2 == 2){ // to hex
                    d2h();
                }
                else{
                    break;
                }
                            
            }
            else if (choice == 3){ // from hex
                // ask if to bin or dec
                printf("---------------------------------\n");
                printf("Enter (1) to convert to binary\nor (2) to convert to decimal:");
                scanf("%d", &choice2);
                if (choice2 == 1){ // to bin
                    h2b();
                }
                else if(choice2 == 2){ // to dec
                    int res = h2d();
                    printf("%d\n", res);
                    printf("\n");
                }
                else{
                    break;
                }
            }
            else
                break;
            
        }
        else if (choice3 == 2){
            //implement calculator
            printf("---------------------------------\n");
            printf("Enter:\n(1) to add\n(2) to subtract\n(3) to multiply\n(4) to divide\nor (5) to exit.");
            scanf("%d", &choice2);
            if (choice2 == 1){ //add
                unsigned long num1;
                unsigned long num2;
                int res;
                printf("---------------------------------\n");
                printf("Enter the first number you want to add: ");
                scanf("%lu", &num1);
                printf("Enter the second number you want to add: ");
                scanf("%lu", &num2);

                //change into binary
                num1 = d2b(num1);
                num2 = d2b(num2);

                res = add(num1, num2);

                //change from binary
                res = b2d(res);
                printf("The sum is: %d \n", res);

            }
            else if(choice2 == 2){ // sub
                unsigned long num1;
                unsigned long num2;
                int res;
                printf("---------------------------------\n");
                printf("Enter the first number you want to subtract: ");
                scanf("%lu", &num1);
                printf("Enter the second number you want to subtract: ");
                scanf("%lu", &num2);

                //change into binary
                num1 = d2b(num1);
                num2 = d2b(num2);

                res = sub(num1, num2);

                //change into binary
                res = b2d(res);
                printf("The answer is: %d \n", res);

            }
            else if(choice2 == 3){ // mul
                unsigned long num1;
                unsigned long num2;
                int res;
                printf("---------------------------------\n");
                printf("Enter the first number you want to multiply: (max of 16 bits)");
                scanf("%lu", &num1);
                printf("Enter the second number you want to multiply: (max of 16 bits)");
                scanf("%lu", &num2);

                //change into binary
                num1 = d2b(num1);
                num2 = d2b(num2);

                res = mul(num1, num2);

                printf("The product is: %d", res);

            }
            else if(choice2 == 4){ // div
                unsigned long num1;
                unsigned long num2;
                int res;
                printf("---------------------------------\n");
                printf("Enter the first number you want to divide: (max of 16 bits)");
                scanf("%lu", &num1);
                printf("Enter the second number you want to divide: (max of 16 bits)");
                scanf("%lu", &num2);

                //change into binary
                num1 = d2b(num1);
                num2 = d2b(num2);

                res = divi(num1, num2);

                printf("The answer is: %d", res);

            }
            else{
                break;
            }
        }
        else{
            break;
        }
	return 0;
}
}