#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int Auset, Ausar, Heru;

    while(1){
        cin >> Auset >> Ausar >> Heru;
        if(Auset == 0 && Ausar == 0 && Heru == 0)
            break;
        if((pow(Heru, 2) == pow(Ausar, 2) + pow(Auset, 2)) || (pow(Auset, 2) == pow(Ausar, 2) + pow(Heru, 2)) || (pow(Ausar, 2) == pow(Heru, 2) + pow(Auset, 2)))
            cout << "right" << endl;
        else
            cout << "wrong" << endl;
    }
    return 0;
}