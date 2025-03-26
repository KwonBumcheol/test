#include<iostream>
#include<unistd.h>
#include<wiringPi.h>
#include<iomanip>
using namespace std;

#define USING_DHT11      true   // The DHT11 uses only 8 bits
#define DHT_GPIO         25      // GPIO 25
#define LH_THRESHOLD     26      // Low=~14, High=~38 - pick avg.

#define LED_R_GPIO   22  // R LED 
#define LED_G_GPIO   27  // G LED

int main(){
    int num = 0;
    int humid = 0, temp = 0;
    cout << "Starting the one-wire sensor program" << endl;
    wiringPiSetupGpio();         // GPIO 번호 체계 사용
    pinMode(LED_R_GPIO, OUTPUT);
    pinMode(LED_G_GPIO, OUTPUT);

    digitalWrite(LED_R_GPIO, LOW);
    digitalWrite(LED_G_GPIO, LOW);
    piHiPri(99);                 // 프로세스 우선순위 높이기 -> 데이터 수신 정확도 향상
TRYAGAIN:                        // If checksum fails (come back here)
    unsigned char data[5] = {0,0,0,0,0};
    pinMode(DHT_GPIO, OUTPUT);                 // gpio starts as output
    digitalWrite(DHT_GPIO, LOW);               // pull the line low
    usleep(18000);                             // wait for 18ms
    digitalWrite(DHT_GPIO, HIGH);              // set the line high
    pinMode(DHT_GPIO, INPUT);                  // now gpio is an input

    // need to ignore the first and second high after going low
    do { delayMicroseconds(1); } while(digitalRead(DHT_GPIO)==HIGH);
    do { delayMicroseconds(1); } while(digitalRead(DHT_GPIO)==LOW);
    do { delayMicroseconds(1); } while(digitalRead(DHT_GPIO)==HIGH);
    // Remember the highs, ignore the lows -- a good philosophy!
    for(int d=0; d<5; d++) {       // for each data byte
        // read 8 bits
        for(int i=0; i<8; i++) {    // for each bit of data
            do { delayMicroseconds(1); } while(digitalRead(DHT_GPIO)==LOW);
            int width = 0;           // measure width of each high
            do {
                width++;
                delayMicroseconds(1);
                if(width>1000) break; // missed a pulse -- data invalid!
            } while(digitalRead(DHT_GPIO)==HIGH);    // time it!
            // shift in the data, msb first if width > the threshold
            data[d] = data[d] | ((width > LH_THRESHOLD) << (7-i));
        }
    }
    if (USING_DHT11){
        // humid = data[0] * 10;            // one byte - no fractional part
        temp = data[2] * 10;             // multiplying to keep code concise
    }
    else {                              // for DHT22 (AM2302/AM2301)
        // humid = (data[0]<<8 | data[1]);  // shift MSBs 8 bits left and OR LSBs
        temp = (data[2]<<8 | data[3]);   // same again for temperature
    }
    
    unsigned char chk = 0;   // the checksum will overflow automatically
    for(int i=0; i<4; i++){ chk+= data[i]; }
    if(chk==data[4]){
        cout << ++num << endl;
        cout << "The checksum is good" << endl;
        cout << "The temperature is " << (float)temp/10 << "°C" << endl;
        // cout << "The humidity is " << (float)humid/10 << "%" << endl;
        cout << endl;

        if(temp / 10 > 30){
            digitalWrite(LED_R_GPIO, HIGH);
            digitalWrite(LED_G_GPIO, LOW);
        }
        else{
            digitalWrite(LED_R_GPIO, LOW);
            digitalWrite(LED_G_GPIO, HIGH);
        }
    }
    usleep(2000000); // 2초
    goto TRYAGAIN;

    return 0;
}
