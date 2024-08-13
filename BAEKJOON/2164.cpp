#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cout << N;

    vector<int> v;
    for(int i = 0; i < N; i++)
        v.push_back(i); // v[i] = i;
    int i = 0;
    while(v.size() == 1){
        v.erase(v.begin());
        v[N+1] = v[i];
    }
    cout << v[i];
    return 0;
}