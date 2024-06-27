#include <iostream>
using namespace std;
class Adder{
    int op1, op2;
public:
    Adder(int a, int b);
    int process();
};

Adder::Adder(int a, int b){
    op1 = a; op2 = b;
}

int Adder::process(){
    return op1 + op2;
}
class Calculator{
public:
    void run();
};

void Calculator::run(){
    cout << "두 개의 수를 입력하세요>>";
    int a, b;
    cin >> a >> b;
    Adder adder(a, b);
    cout << adder.process();
}

int main(){
    // cout << "Hello, World!\n";
    // cout << sizeof(long double); // 16byte??? 왜 8byte 아님??
    // return 0;
    Calculator calc;
    calc.run();
}