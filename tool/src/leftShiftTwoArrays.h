#include <stdio.h>

void leftShiftTwoArrays(int *a,int *q, int qcount, int acount){
    // first input will be a and the second is q
    int internalsize = qcount+acount;
    int j = 1;
    int k = 0;
    for (int i = 1; i < internalsize; i++){
        if(i<acount){
            int temp = 0;
            temp = a[j];
            a[j] = a[j-1];
            a[j-1] = temp;
            j++;
        }
        if(i==acount){
            int temp = 0;
            temp = a[j-1];
            a[j-1] = q[k];
            q[k] = temp;
            k++;
        }
        if(i>acount && i < (internalsize)-1){
            int temp = 0;
            temp = q[k];
            q[k] = q[k-1];
            q[k-1] = temp;
            k++;
        }
        if(i == (internalsize)-1){
            int temp = 0;
            temp = q[k-1];
            q[k-1] = q[k];
            q[k] = 0;
            k++;
        }
    }
}