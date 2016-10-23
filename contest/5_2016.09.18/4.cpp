#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool canCross(vector<int>& stones) {
    int dp[500][500] = {{0}};
    dp[0][0] = 1;

    int n = stones.size();
    cout << "0" << endl;
    for (int i = 1; i < n; i++){
        cout << "1" << endl;
        for (int j = 1; j < 500; j++){
            cout << "2" << endl;
            for (int k = 0; k <= i - 1; k++){
                cout << "3" << endl;
                if (dp[k][j - 1] == 1){
                    if (stones[k] + j - 2 == stones[i] ||
                        stones[k] + j - 1 == stones[i] ||
                        stones[k] + j == stones[i]){

                            dp[i][j] = 1;
                            if (i == n - 1) return true;
                            break;
                        }

                }
            }
        }
    }

    return false;

}

int main(){
    vector<int> stones{0,1,3,5,6,8,12,17};

    if (canCross(stones)){
        cout << "True\n";
    }
    else {
        cout << "False\n";
    }




    return 0;
}
