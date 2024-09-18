#include <iostream>
// #include <string>
// using namespace std;

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int T;
//     cin >> T;
//     int L = 0, R = 0;

//     for(int i = 0; i < T; i++){
//         string x;
//         cin >> x;
//         for(int j = 0; j <= x.length(); j++){
//             if(x[j] == '('){
//                 L++;
//             }
//             else if(x[j] == ')'){
//                 R++;
//             }
//         }
        
//         if(L == R)
//             cout << "YES" << '\n';
//         else
//             cout << "NO" << '\n';
//         L = 0; R = 0;
//     }
//     return 0;
// }
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int iSize = 0;

	cin >> iSize;

	for (int i = 0; i < iSize; ++i)
	{
		stack<char> st;
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); ++j)
		{
			if (st.empty() || s[j] == '(') st.push(s[j]);
			else if (st.top() == '(') st.pop();
		}

		if (st.empty()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
    
	return 0;
}