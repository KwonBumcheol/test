#include <iostream>
using namespace std;

int main(){
    int K, N, sum = 0; // 오영식 가지고 있는 랜선의 개수 K, 필요한 랜선의 수 N
    cin >> K >> N;

    int num[1000000];

    for(int i = 0; i < K; i++){
        cin >> num[i];
        sum += num[i];
    }
    sum = sum / N;

    cout << sum;

    return 0;
}