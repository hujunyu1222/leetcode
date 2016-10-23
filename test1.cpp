//#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int minPatches(vector<int> &nums, int n) {
    vector<bool> vis(n+1, false);
    vector<int> arr;

    int res = 0;

    int nSize = nums.size();
    int index = 1;
    int i, j;

    i = 0;

    while(index <= n){
        if (i < nSize && nums[i] <= index ){
            if (arr.size() == 0 || vis[nums[i]] == false){
                vis[nums[i++]] = true;
                arr.push_back(index++);
            }
            else{
                arr.push_back(nums[i++]);
            }
        }
        else{
            res++;
            arr.push_back(index++);
        }

        int tmpSize = arr.size();
        for (j = 0; j < tmpSize - 1; j++){
            int tmp = arr[j] + arr[tmpSize - 1];
            if (tmp == index){
                index++;
            }
            if (vis[tmp] == false){
                vis[tmp] = true;
                arr.push_back(tmp);
            }
        }

        while(vis[index] == true)index++;
    }
    cout << res << endl;
    return res;

}


int main(){
    vector<int> nums{1,5,10};

    cout << "Begin:\n" << endl;
    cout << minPatches(nums, 5);

    return 0;
}

