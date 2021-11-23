#include "ReadOnlyBlockDevice.h"
#include "mbed_wait_api.h"
#include "uop_msb.h"
using namespace uop_msb;


// You are to use these ojects to read the switch inputs
DigitalIn SW1(USER_BUTTON);
DigitalIn SW2(BTN1_PIN);
DigitalIn SW3(BTN2_PIN);
DigitalInOut SW4(BTN3_PIN,PIN_INPUT,PullDown,0);
DigitalInOut SW5(BTN4_PIN,PIN_INPUT,PullDown,0);


BusIn bus(BTN1_PIN, BTN2_PIN, BTN3_PIN, BTN4_PIN, USER_BUTTON);



// You are to use this object to control the LEDs
BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);

//Use this to sound an error
Buzzer alarm;

int main()
{
    bus[2].mode(PinMode::PullDown);
    bus[3].mode(PinMode::PullDown);
    while (true)
    {
        leds = 0;

        //Beep
        alarm.playTone("A", Buzzer::HIGHER_OCTAVE);
        wait_us(250000);
        alarm.rest();

        leds = 0;
        //Wait for the blue button using a while loop
        while (SW1==0){ };


        
        // For full marks, debounce the switches with suitable delays

        // This is a "combination lock" activity. Write some code to detect the following sequence of press-and-release inputs
        // SW1 and SW2, SW5, SW4, SW2 and SW3
        // If the full sequence is entered, correctly, the green LED should flash 3 times
        // If a sequence of inputs was entered incorrectly, the red LED should light and the buzzer should sound for 5 seconds
        // For full marks, debounce the switches and use flow control structures and arrays to avoid deep nesting of code

        // ***** MODIFY THE CODE BELOW HERE *****
        wait_us(500000);
        if(SW1 == 1){
            wait_us(250000);
            while(SW1==1 | bus==0){ }
            // wait_us(5000000);
            if(SW2==1){
                wait_us(250000);
                while(SW2==1 | bus==0){ }
                // wait_us(5000000);
                if(SW5==1){
                    wait_us(250000);
                    while(SW5==1 | bus==0){ }
                    // wait_us(5000000);
                    if(SW4==1){
                        wait_us(250000);
                        while(SW4==1 | bus==0){ }
                        // wait_us(5000000);
                        if(SW2==1){
                            wait_us(250000);
                            while(SW2==1 | bus==0){ }
                            // wait_us(5000000);
                            if(SW3==1){
                                wait_us(250000);
                                for(int i = 0; i < 3; i++){
                                    led = 4;
                                    wait_us(500000);
                                    led = 0;
                                }
                            }
                            else{
                                leds = 1;
                                alarm.playTone("C");
                                wait_us(5000000);
                                alarm.rest();
                                leds = 0;
                            }
                        }
                        else{
                            leds = 1;
                            alarm.playTone("C");
                            wait_us(5000000);
                            alarm.rest();
                            leds = 0;
                        }
                    }
                    else{
                        leds = 1;
                        alarm.playTone("C");
                        wait_us(5000000);
                        alarm.rest();
                        leds = 0;
                    }
                }
                else{
                    leds = 1;
                    alarm.playTone("C");
                    wait_us(5000000);
                    alarm.rest();
                    leds = 0;
                }
            }
            else{
                leds = 1;
                alarm.playTone("C");
                wait_us(5000000);
                alarm.rest();
                leds = 0;
            }
        }
        else{
            leds = 1;
            alarm.playTone("C");
            wait_us(5000000);
            alarm.rest();
            leds = 0;
        }
        // ***** MODIFY THE CODE ABOVE HERE *****
    }
}


