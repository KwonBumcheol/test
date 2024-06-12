#include <iostream>
using namespace std;

int main(){
    int N, num, result = 0, cnt = 0;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> num;
        for(int j = 1; j <= num; j++){
            if(num % j == 0)
                cnt++;
        }
        if(cnt == 2)
            result++;
        cnt = 0;
    }
    cout << result;
    return 0;
}