#include <iostream>
#include <cmath>
using namespace std;

int arr[1000001];
int main(){
    int M, N;
    cin >> M >> N;
    for(int i = 2; i <= N; i++)
        arr[i] = i;
    
    for(int i = 2; i <= sqrt(N); i++){
        if(arr[i] == 0)
            continue;
        for(int j = i * i; j <= N; j += i)
            arr[j] = 0;
    }

    for(int i = M; i <= N; i++){
        if(arr[i] == 0)
            continue;
        else
            cout << arr[i] << '\n';
    }
    return 0;
}