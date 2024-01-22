#include <iostream>
#include <string>
#include <algorithm> // reverse() 함수
using namespace std;

int main(){
    string N;

    while(N != "0"){ // 0이 아니면 무한 반복
        cin >> N;
        string buf = N; // 원래 값을 buf에 저장
        reverse(N.begin(), N.end()); // 앞 뒤 바꿈
        if(N == "0"){ // 즉시 탈출( why? 0도 reverse하면 0으로 같다)
            break;
        }
        else if(N == buf){ // 두 수가 동일하면 yes
            cout << "yes" << endl;
        }
        else{ // 다르면 no
            cout << "no" << endl;
        }
    }
    return 0;
}