#include <iostream>
using namespace std;

int fibonacci(int n){
    if(n < 2) return n;
    else return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    int i;
    cin >> i;
    cout << fibonacci(i);
    return 0;
}