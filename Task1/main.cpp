#include "uop_msb.h"
using namespace uop_msb;

BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);

int main()
{
    leds = 0;
    // ***** MODIFY THE CODE BELOW HERE *****

    // 1. Write a for-loop to count from 0 to 100 in steps of 10 - print the results to the serial terminal
    printf("\n\n");
    for(int i=0; i<=100; i+=10){
        printf("i = %d  ", i);
    }

    // 2. Write a for-loop to count from 100 down to 10 in steps of 5 - print the results to the serial terminal

    printf("\n\n");
    for(int i=100; i>0; i-=10){
        printf("i = %d  ", i);
    }
    // 3. Write some code to demonstrate nested for-loops (one loop within another)

    printf("\n\n");
    for(int i = 2; i < 100; i++){
        for(int j = 2; j <= (i/j); j++){
            if(!(i%j)) break;
            if(j > (i/j)){
                printf("%d is a prime number\n", i);
            }

        }
        return 0;
    }
    // ***** MODIFY THE CODE ABOVE HERE *****
    leds = 7;

    while (true) {

    }
}

