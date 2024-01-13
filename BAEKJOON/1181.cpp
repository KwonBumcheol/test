#include <iostream>
#include <algorithm> // 정렬 함수 : sort
using namespace std;

int cmp(string a, string b){
    if(a.length() == b.length()){ // 1. 길이가 같으면, 사전 순
        return a < b; // 오름차순 < , 내림차순 >
    } else { // 2. 길이가 다르면, 짧은 순
        return a.length() < b.length();
    }
}

int main(){
    int N;
    cin >> N;
    string Alpha[20000];

    for(int i = 0; i < N; i++){
        cin >> Alpha[i];
    }

    sort(Alpha, Alpha + N, cmp); // sort(v.begin(), v.end(), compare); > 사용자 정의 함수 사용

    for(int i = 0; i < N; i++){ // 중복된 경우 한번만 출력
        if(Alpha[i] == Alpha[i - 1]){
            continue; // for문으로 복귀
        }
        cout << Alpha[i] << endl;
    }

    return 0;
}