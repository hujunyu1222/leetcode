#include <iostream>
#include <vector>

using namespace std;

const int maxNum = 0x7FFFFFFF;

void Print(vector<vector<int> > &dp){
    for (auto x : dp){
        for (auto y : x){
            cout << y << " ";
        }
        cout << endl;
    }
}


int main(){
    int arr[4] = {2,5,3,4};

    int M = 14;
    vector<vector<int> > dp(3, vector<int>(M+1, 0));

    //ø’º‰—πÀı
    vector<int> dp2(M+1, maxNum);



    int i, j;
    dp2[0] = 0;
    if (arr[0] <= M)
    dp2[arr[0]] = 1;


    int left = 0;

    for (i = 1; i < 4; i++){
        for (j = M; j >= 1; j--){
            left = maxNum;
            if (j - arr[i] >= 0 && dp2[j - arr[i]] != maxNum){
                left = dp2[j - arr[i]] + 1;
            }
            dp2[j] = min(left, dp2[j]);
        }
    }

    for (auto x: dp2){
        cout << x << " ";
    }
    cout << '\n';







    //Print(dp);

    dp2[M] != maxNum ? cout << dp2[M] : cout << "-1";
    cout << "\n";


    return 0;
}
