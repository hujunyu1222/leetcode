#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

int backtracking(vector<int> &nums, int s, int e){
    if (s == e){
        return 1;
    }

    int i;
    int res = 0;
    for (i = s; i <= e; i++){
        res += backtracking(nums, i+1, e);
        while(i <= e && nums[i] == nums[i+1]){
            i++;
        }
    }

    return res;
}

int main(){
    vector<int> nums{2,3,4};
    cout << backtracking(nums, 0, 2);

    return 0;
}


/*
int main(){
    int n;
    cin >> n;
    vector<int> nums(n,0);

    int i = 0;
    int cnt, length, res;
    cnt = length = res = 0;

    for (i = 0; i < n; i++){
        cin >> nums[i];
        if (nums[i] == 1) cnt++;
    }

    sort(nums.begin(), nums.end());

    i = cnt;
    ll sum, product;

    sum = cnt;
    product = 1;
    while(i < n){
        product = product * nums[i];
        sum += nums[i];
        if (product >= sum){
            break;
        }
        length++;
        i++;
    }

    //if (i != n && cnt != 0) res++;

    if (cnt != 0){
        res += cnt - 1;
    }
    res += backtracking(nums, cnt, cnt + length - 1);

    cout << res << endl;

    return 0;
}
*/
