#include <iostream>
using namespace std;

int main(){
    int N, T, P, T_Min=0, T_Max1=0, T_Max2=0;
    cin >> N;
    int size[6];
    for(int i=0; i<6; i++)
        cin >> size[i];
    cin >> T >> P;
    for(int i=0; i<6; i++){
        T_Min += size[i]/T;
        if(size[i]%T != 0)
            T_Min++;
    }
    T_Max1 = N/P;
    T_Max2 = N%P;
    cout << T_Min << endl;
    cout << T_Max1 << ' ' << T_Max2 << endl;
    return 0;
}