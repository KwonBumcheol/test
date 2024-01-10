#include <iostream>
using namespace std;

int main(){
    // int T, H, W, N, z=0; // T=반복수, H=층, W=방, N=손님(번째)
    // cin >> T;
    // int sum[T];
    // for(int i=0;i<T;i++){
    //     cin >> H >> W >> N;
    //     int ACM[H][W];
    //     for(int k=0;k<T;k++){
    //         for(int i=0;i<W;i++){
    //             for(int j=0;j<H;j++){
    //                 ACM[j][i] = 100*(j+1);
    //                 ACM[j][i] += (i+1);
    //                 N--;
    //                 if(N==0){
    //                     sum[k] = ACM[j][i];
    //                     sum[z] = sum[k];
    //                     z++;
    //                 }
    //             }
    //         }   
    //     }
    // }
    // for(z=0;z<T;z++){
    //     cout << sum[z] << endl;
    // }
    // return 0;

    int T; // T=반복수 
	int H, W, N; // H=층, W=방, N=손님(번째)
	int result; // 방번호
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> H >> W >> N; 

		if (N%H == 0) { // 나머지
			result = H * 100 + (N / H); // 나누어떨어지는 경우
		}
		else {
			result = (N%H) * 100 + (N / H) + 1; // 그 외
		}
		cout << result << endl;
	}
}