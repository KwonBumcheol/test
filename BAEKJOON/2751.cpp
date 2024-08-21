#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int sum[N];
    for(int i=0; i<N; i++){
        cin >> sum[i];
    }
    sort(sum, sum+N);

    for(int i=0; i<N; i++){
        cout << sum[i] << '\n';
    }
    return 0;
}