#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, num;
    cin >> N;
    vector<int> v(N);

    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> num;
        if(binary_search(v.begin(), v.end(), num)){
            cout << '1' << '\n';
        } else {
            cout << '0' << '\n';
        }
    }
    return 0;
}