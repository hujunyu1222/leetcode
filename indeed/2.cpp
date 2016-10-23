#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;



int main(){
    int N;
    cin >> N;
    vector<int> nums(N);
    vector<int> vis(N,0);

    int cnt = 0;
    int i, j;

    for (i = 0; i < N; i++){
        cin >> nums[i];
    }

    for (i = 0; i < N; i++){
        if (vis[i] == 0){
            vis[i] = 1;
            j = nums[i] - 1;
            while(vis[j] == 0){
                vis[j] = 1;
                j = nums[j] - 1;
            }
            cnt++;
        }
    }

    cout << cnt;

    return 0;

}
