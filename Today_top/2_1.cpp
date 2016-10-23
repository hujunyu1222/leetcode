#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    vector<int> nums;

    freopen("in1.txt", "r", stdin);

    cin >> n;
    int tmp;

    for (int i = 0; i < n; i++){
        cin >> tmp;
        nums.push_back(tmp);

    }

    sort(nums.begin(), nums.end());

    int s = 0, e = 1;
    int cnt = 0;;

    while(e < nums.size() && s < nums.size()){
        if (nums[e] - nums[s] <= 10){
            e++;
        }
        else{
           cnt += (3 - (e - s));
           s = e;
           e++;
        }
        if (e - s == 2){
            if (nums[e] - nums[e - 1] <= 10){
                s = e + 1;
                e = s + 1;
            }
            else{
                cnt += (3 - (e - s));
                s = e;
                e++;
            }
        }

    }

    cout << cnt << endl;

    return 0;

}

