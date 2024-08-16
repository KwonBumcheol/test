#include <iostream>
using namespace std;

int gcd(int a, int b){
    int r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    int GCD = gcd(a, b);

    int LCM = a*b/GCD;
    cout << GCD << '\n' << LCM;
    return 0;
}