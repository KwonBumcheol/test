#include <iostream>
#include <wiringPi.h>
#include <unistd.h>
using namespace std;

// GPIO 핀 번호 설정
#define LED1_GPIO   17  // 첫 번째 LED 
#define LED2_GPIO   18  // 두 번째 LED 
#define LED3_GPIO   27  // 세 번째 LED

#define BUTTON1_GPIO  13  // 첫 번째 버튼
#define BUTTON2_GPIO  19  // 두 번째 버튼 
#define BUTTON3_GPIO  26  // 세 번째 버튼 
#define DEBOUNCE_TIME 200 // 200ms 디바운싱 시간

// 디바운싱을 위한 마지막 버튼 누름 시간 저장
unsigned int lastISRTime1 = 0;
unsigned int lastISRTime2 = 0;
unsigned int lastISRTime3 = 0;


// LED 상태 변수
bool ledState1 = false;
bool ledState2 = false;
bool ledState3 = false;

// 버튼 1의 인터럽트 서비스 루틴 (ISR)
void lightLED1(void) {
    unsigned int currentISRTime = millis();  // 현재 시간(ms)
    if (currentISRTime - lastISRTime1 > DEBOUNCE_TIME) {
        ledState1 = !ledState1; // LED 상태 토글
        digitalWrite(LED1_GPIO, ledState1 ? HIGH : LOW);
        cout << "버튼 1 눌림! LED 1 " << (ledState1 ? "켜짐" : "꺼짐") << endl;
        lastISRTime1 = currentISRTime;
    }
}

// 버튼 2의 인터럽트 서비스 루틴 (ISR)
void lightLED2(void) {
    unsigned int currentISRTime = millis();
    if (currentISRTime - lastISRTime2 > DEBOUNCE_TIME) {
        ledState2 = !ledState2;
        digitalWrite(LED2_GPIO, ledState2 ? HIGH : LOW);
        cout << "버튼 2 눌림! LED 2 " << (ledState2 ? "켜짐" : "꺼짐") << endl;
        lastISRTime2 = currentISRTime;
    }
}

// 버튼 3의 인터럽트 서비스 루틴 (ISR)
void lightLED3(void) {
    unsigned int currentISRTime = millis();
    if (currentISRTime - lastISRTime3 > DEBOUNCE_TIME) {
        ledState3 = !ledState3;
        digitalWrite(LED3_GPIO, ledState3 ? HIGH : LOW);
        cout << "버튼 3 눌림! LED 3 " << (ledState3 ? "켜짐" : "꺼짐") << endl;
        lastISRTime3 = currentISRTime;
    }
}

int main() {
    wiringPiSetupGpio();  // GPIO 번호 체계 사용

    // LED 핀을 출력으로 설정
    pinMode(LED1_GPIO, OUTPUT);
    pinMode(LED2_GPIO, OUTPUT);
    pinMode(LED3_GPIO, OUTPUT);

    // 버튼 핀을 입력으로 설정
    pinMode(BUTTON1_GPIO, INPUT);
    pinMode(BUTTON2_GPIO, INPUT);
    pinMode(BUTTON3_GPIO, INPUT);

    // 초기 LED 상태를 꺼둠
    digitalWrite(LED1_GPIO, LOW);
    digitalWrite(LED2_GPIO, LOW);
    digitalWrite(LED3_GPIO, LOW);

    cout << "각 버튼을 누르면 해당 LED가 켜졌다 꺼졌다 합니다!" << endl;

    // 인터럽트 설정 (버튼이 눌릴 때 실행될 함수 연결)
    wiringPiISR(BUTTON1_GPIO, INT_EDGE_RISING, &lightLED1);
    wiringPiISR(BUTTON2_GPIO, INT_EDGE_RISING, &lightLED2);
    wiringPiISR(BUTTON3_GPIO, INT_EDGE_RISING, &lightLED3);

    // 무한 루프: 프로그램이 종료되지 않고 계속 실행됨
    while(1) {
        sleep(1); // CPU 점유율을 줄이기 위해 1초 대기
    }

    return 0;
}