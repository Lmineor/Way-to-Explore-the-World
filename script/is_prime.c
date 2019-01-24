/*判定素数*/

#include <stdio.h>
#define TRUE 1
#define FALSE 0
typedef int Bool;

Bool is_prime(int num){
    int div;
    if(num<1) return FALSE;
    for (div=2; div< num; div++)
        if (num % div == 0) return FALSE;
    return TRUE;
}

Bool main(){
    int n=11;
    // scanf("input a num %d", &n);
    if (is_prime(n))
        printf("is prime");
    else
        printf("is not a prime");
}