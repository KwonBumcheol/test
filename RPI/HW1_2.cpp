#include <iostream>
#include <wiringPi.h>
#include <unistd.h>
using namespace std;

#define PWM_LED1       18      
#define PWM_LED2       13 

int main() {                             // must be run as root
   wiringPiSetupGpio();                  // use the GPIO numbering
   pinMode(PWM_LED1, PWM_OUTPUT);         
   pinMode(PWM_LED2, PWM_OUTPUT); 
   pwmSetRange(2047);
   // pwmSetClock(); // 기본값 = 32 경우 삽입x

    while (1) {
        for (int i = 0; i < 2047; i++) {
            pwmWrite(PWM_LED1, i);
            usleep(2000000 / 2047);
        }
        for (int i = 2046; i >= 0; i--) {
            pwmWrite(PWM_LED1, i);
            usleep(2000000 / 2047);
        }
        for (int i = 0; i < 2047; i++) {
            pwmWrite(PWM_LED2, i);
            usleep(2000000 / 2047);
        }
        for (int i = 2046; i >= 0; i--) {
            pwmWrite(PWM_LED2, i);
            usleep(2000000 / 2047);
        }
    }

   return 0;
}
