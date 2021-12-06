// driver file that creates an input.txt file and an output.txt file
// the input file has random inputs for each function created to test it
// the results from these functions are stored in the output file for the
// programmer to access and check for correctness.
#include "DecimalToBinary.h"
#include "DecimalToHex.h"

#include <stdio.h>
#include <stdlib.h>

// function for generating random binary
//def randBin(int dec):
//    int binary = d2b(dec)

// function for generating random hexadecimal
//def randHex():
//    dec = rand() % 100)

int main(){
    time_t t;
    srant((unsigned) time(&t));

    //randomly generate input.txt
    FILE * fp;

    fp = fopen("input.txt", "w+");
    // b2d
    fprintf(fp, "\n");
    // conversion functions:
    // b2d
    fprintf(fp, "%d\n", randBin(rand() % 100));
    // b2h
    fprintf(fp, "%d\n", randBin(rand() % 100));
    // d2b
    fprintf(fp, "%d\n", rand() % 100);
    // d2h
    fprintf(fp, "%d\n", rand() % 100);
    // h2b
    fprintf(fp, "%d\n", randHex(rand() % 100));
    // h2d
    fprintf(fp, "%d\n", randHex(rand() % 100));
        
    // calculator functions:
    // add
    fprintf(fp, "%d,%d\n", rand() % 100, rand() % 100);
    // subtract
    fprintf(fp, "%d,%d\n", rand() % 100, rand() % 100);
    // multiply
    fprintf(fp, "%d,%d\n", rand() % 100, rand() % 100);
    // divide
    fprintf(fp, "%d,%d\n", rand() % 100, rand() % 100);

    // input numbers from input.txt into functions &
    // put outputs into output.txt
    FILE * fr;
    char buff[255];
    fr = fopen("input.txt", "r");

    FILE * fx;
    fx = fopen("output.txt", "w+");
    // conversion functions:
    // b2d
    fscanf(fr, "%s", buff);

    // b2h
    fgets(buff, 255, (FILE*)fr);

    // d2b
    fgets(buff, 255, (FILE*)fr);

    // d2h
    fgets(buff, 255, (FILE*)fr);
    
    // h2b
    fgets(buff, 255, (FILE*)fr);

    // h2d
    fgets(buff, 255, (FILE*)fr);

    
    // calculator functions:
    // add
    // subtract
    // multiply
    // divide



    fclose(fp);

}

/*
translate:


    # b2d
    # b2h
    # d2b
    # d2h
    # h2b
    # h2d
    
    # calculator functions:
    # add
    # subtract
    # multiply
    # divide

# put outputs into output.txt

*/