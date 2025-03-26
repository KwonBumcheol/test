#include <iostream>
#include <wiringPi.h>

using namespace std;

#define LED_R_GPIO   22  // R LED 
#define LED_G_GPIO   27  // G LED 
#define LED_B_GPIO   17  // B LED

#define PIN_TRIG 23      // GPIO 23
#define PIN_ECHO 24      // GPIO 24
#define RANGE_R 10       // 10cm 
#define RANGE_G 15       // 15cm
#define RANGE_B 30       // 30cm

int main(int argc, char* argv[]){
    wiringPiSetupGpio(); // GPIO 번호 체계 사용

    unsigned int T, L;   // 측정 거리 L, T

    pinMode(PIN_TRIG, OUTPUT);
    pinMode(PIN_ECHO, INPUT);

    pinMode(LED_R_GPIO, OUTPUT);
    pinMode(LED_G_GPIO, OUTPUT);
    pinMode(LED_B_GPIO, OUTPUT);

    digitalWrite(LED_R_GPIO, LOW);
    digitalWrite(LED_G_GPIO, LOW);
    digitalWrite(LED_B_GPIO, LOW);

    while (1) {
        digitalWrite(PIN_TRIG, LOW); 
        delayMicroseconds(2);
        digitalWrite(PIN_TRIG, HIGH); 
        delayMicroseconds(20);
        digitalWrite(PIN_TRIG, LOW);

        while (digitalRead(PIN_ECHO) == LOW);

        unsigned int startTime = micros();
        while (digitalRead(PIN_ECHO) == HIGH);

        T = micros() - startTime;
        L = T / 58.2;

        if (L > 0 && L < RANGE_R){
            cout << "Red" << endl;
            digitalWrite(LED_R_GPIO, HIGH);
            digitalWrite(LED_G_GPIO, LOW);
            digitalWrite(LED_B_GPIO, LOW);
        }
        else if(L >= RANGE_R && L < RANGE_G){
            cout << "Green" << endl;
            digitalWrite(LED_R_GPIO, LOW);
            digitalWrite(LED_G_GPIO, HIGH);
            digitalWrite(LED_B_GPIO, LOW);     
        }
        else if(L >= RANGE_G && L < RANGE_B){
            cout << "Blue" << endl;
            digitalWrite(LED_R_GPIO, LOW);
            digitalWrite(LED_G_GPIO, LOW);
            digitalWrite(LED_B_GPIO, HIGH);
        }
        else{
            cout << "OFF" << endl;
            digitalWrite(LED_R_GPIO, LOW);
            digitalWrite(LED_G_GPIO, LOW);
            digitalWrite(LED_B_GPIO, LOW);
        }
        delay(100);
    }
}