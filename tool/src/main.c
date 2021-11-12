// main file for the translator program

#include <stdio.h>

#include "BinaryToDecimal.h"
//#include "BinaryToHex.h"
#include "DecimalToBinary.h"
//#include "DecimalToHex.h"
#include "HexToBinary.h"
#include "HexToDecimal.h"


int main(){
    int choice = 0, choice2 = 0;
    while(1){
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
                int res = b2d();
			    printf("%d\n", res);
			    printf("\n");
            }
            if (choice2 == 2){ // to hex
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
                unsigned long res = d2b();
                printf("%lu\n", res);
			    printf("\n");  
            }
            if (choice2 == 2){ // to hex
                //int res = d2h();
                //printf("%d\n", res);
			    //printf("\n");
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
                unsigned long res = h2b();
                printf("%lu\n", res);
			    printf("\n");  
            }
            if (choice2 == 2){ // to dec
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
	return 0;
}