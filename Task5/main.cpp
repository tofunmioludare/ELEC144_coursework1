#include "uop_msb.h"
using namespace uop_msb;

// You are to ONLY use this object to control the LEDs
PortOut traffic(PortC, 0b0000000001001100);

//The default flash rate is once per second for all tasks

int main()
{

    // //1. Flash the red led 3 times

    // for(int i=0; i<3; i++){
    //     traffic = 0b0000000001001100 & 0b0000000000000100;
    //     wait_us(1000000);
    //     traffic = traffic & 0;
    //     wait_us(1000000);
    // }


    // //2. Using the bitwise OR and AND operators (|,&), flash the green LED on and off 3 times
    // for(int i=0; i<3; i++){
    //     traffic = traffic | 0b0000000001000000;
    //     wait_us(1000000);
    //     traffic = traffic & 0;
    //     wait_us(1000000);
    // }


    // //3. Using the bitwise XOR operator (^), flash the yellow LED on and off 3 times
    // for(int i=0; i<3; i++){
    //         traffic = traffic ^ 0b0000000000001000;
    //         wait_us(1000000);
    //         traffic = traffic & 0;
    //         wait_us(1000000);
    //     }

    //4. Using only bitwise operators, display the traffic light sequence red, red+yellow, green, yellow. Leave a 1s gap between each
    traffic = traffic ^ 0b0000000000000100;
    wait_us(1000000);
    traffic = traffic | 0b0000000000001000;
    wait_us(1000000);
    traffic = traffic ^ 0b0000000001001100;
    wait_us(1000000);
    traffic = traffic ^ 0b0000000001001000;
    wait_us(1000000);
    while (true);
}


