#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    int sum;
    int MAX = 0;
    for(int i = 0; i < N - 2; i++){
        for(int j = i + 1; j < N - 1; j++){
            for(int k = j + 1; k < N; k++){
                sum = v[i] + v[j] + v[k];
                if(sum <= M && MAX < sum)
                    MAX = sum;
            }
        }
    }
    cout << MAX;
    return 0;
}