#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    vector<char> v;
    stack<int> s;
    int n, cnt = 1;
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        while(cnt <= num){
            s.push(cnt);
            cnt++;
            v.push_back('+');
        }
        if(s.top() == num){
            s.pop();
            v.push_back('-');
        } else {
            cout << "NO";
            return 0;
        }
    }
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << '\n';
}