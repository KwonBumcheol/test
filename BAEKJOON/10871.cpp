#include <iostream>
using namespace std;

int main(){
    int N, X, seq_A[10000];
    cin >> N >> X;
    
    for(int i = 0; i < N; i++){
        cin >> seq_A[i]; // 수열A > 정수N개 입력
    }

    for(int i = 0; i < N; i++){
            if(seq_A[i] < X){
                cout << seq_A[i] << ' ';
            }
        }
    return 0;
}