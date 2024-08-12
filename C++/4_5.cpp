#include <iostream>
using namespace std;

int main(){
    int *p = new int; // int *p; p = new int;

    if(!p){ // p = NULL
        cout << "메모리에 할당할 수 없습니다.";
        return 0;
    }

    *p = 5;
    int n = *p;
    cout << "*p = " << *p << '\n';
    cout << "n = " << n << '\n';

    delete p; // 할당 받은 메모리 반환
}