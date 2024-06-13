#include <iostream>
#include <algorithm>

using namespace std;

unsigned int K, N; // 오영식 가지고 있는 랜선의 개수 K, 필요한 랜선의 수 N
unsigned int list[10000];
unsigned int ans;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    cin >> K >> N;

    unsigned int maxi = 0;

    for(int i = 0; i < K; i++){
        cin >> list[i];
        maxi = max(maxi, list[i]);
    }

    unsigned int left = 1, right = maxi, mid;
    
    while(left <= right){
        mid = (left + right) / 2;
        unsigned int now = 0;

        for(int i = 0; i < K; i++){
            now += list[i] / mid;
        }

        if(now >= N){
            left = mid + 1;
            ans = max(ans, mid);
        } else {
            right = mid - 1;
        }
    }
    cout << ans << '\n';
}