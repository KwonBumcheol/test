#include <iostream>
#include <wiringPi.h>
#include <mcp3004.h>

#define BASE 200
#define SPI_CHAN 0

#define LEDB_WiringPi 7  // GPIO 4   
#define LEDG_WiringPi 0  // GPIO 17   
#define LEDR_WiringPi 2  // GPIO 27 

#define Bright_B 500
#define Bright_G 300
#define Bright_R 100

int main(void){
    wiringPiSetup(); // wPi 번호 체계 사용

    pinMode(LEDR_WiringPi, OUTPUT);
    pinMode(LEDG_WiringPi, OUTPUT);
    pinMode(LEDB_WiringPi, OUTPUT);

    mcp3004Setup(BASE, SPI_CHAN); // 초기화

    int x;

    while(1){
        x = analogRead(BASE);

        printf("%d\n", x);

        if(x > Bright_B){
            digitalWrite(LEDR_WiringPi, LOW);
            digitalWrite(LEDG_WiringPi, LOW);
            digitalWrite(LEDB_WiringPi, HIGH);
        }
        else if(x > Bright_G && x < Bright_B){
            digitalWrite(LEDR_WiringPi, LOW);
            digitalWrite(LEDG_WiringPi, HIGH);
            digitalWrite(LEDB_WiringPi, LOW);
        }
        else if(x > Bright_R && x < Bright_G){
            digitalWrite(LEDR_WiringPi, HIGH);
            digitalWrite(LEDG_WiringPi, LOW);
            digitalWrite(LEDB_WiringPi, LOW);
        }
        else {
            digitalWrite(LEDR_WiringPi, LOW);
            digitalWrite(LEDG_WiringPi, LOW);
            digitalWrite(LEDB_WiringPi, LOW);
        }

        delay(100);
    }

    return 0;
}