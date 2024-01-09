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

    int T;
	int H, W, N;
	int result;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> H >> W >> N;

		if (N%H == 0) {
			result = H * 100 + (N / H);
		}
		else {
			result = (N%H) * 100 + (N / H) + 1;
		}
		cout << result << endl;
	}
}