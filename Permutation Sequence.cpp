#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void reverseVec(vector<int> &nums, int l, int r){
    while (l < r){
        swap(nums[l++], nums[r--]);
    }
}

void initVec(vector<int> &nums, int n){
    for (int i = 1; i <= n; i++){
        nums[i-1] = i;
    }
}

string vecToString(vector<int> &nums){
    string res = "";
    stringstream ss;
    int tmp = 0;
    for (int i = 0; i < nums.size(); i++){
        tmp = tmp * 10 + nums[i];
    }
    ss << tmp;
    ss >> res;
    return res;
}

void PrintVec(vector<int> &nums){
    for (int i = 0; i < nums.size(); i++){
        cout << nums[i];
    }
    cout << '\n';
}

string getPermutation(int n, int k) {
    vector<int> nums(n);
    string res;

    initVec(nums, n);
    int index = 1;

    int i, j;
    int N = k;
    res = vecToString(nums);

    while(--N){
        for (i = n - 2; i >= 0 && nums[i] > nums[i+1]; i--);

        if (i < 0) res = vecToString(nums);

        for (j = n - 1;j >= 0 && nums[j] < nums[i]; j--);
        swap(nums[i], nums[j]);
        reverseVec(nums, i+1, n - 1);
        res = vecToString(nums);
        //PrintVec(nums);
        //cout << res << endl;
    }

    return res;

}

int stratum(int n){
    int res = 1;
    while(n){
        res *= n--;
    }

    return res;
}

string getPermutation2(int n, int k){
    string res = "";
    vector<bool> vis(n);
    char c = '0';
    int num = 0;
    int i, j;
    int N = n;
    int cnt = 0;

    for (i = 0; i < n; i++) vis[i] = false;

    while(k != 0){
        num = stratum(--N);
        //cout << k << ":" << num << endl;
        cnt = k / num;

        if (k % num != 0) cnt++;

            j = 0;
            while(cnt){

                if (vis[j] == false){
                    cnt--;
                }
                j++;
            }
            vis[j - 1] = true;
            res += c + j;


        k = k % num;
    }
    //cout << res << "tmp:res" << endl;
    for (i = n - 1;i >=0; i--){
        if (vis[i] == false){
           res += c + i + 1;
           vis[i] = true;
        }
    }

    return res;

}

int main(){
    string s;
    s = getPermutation2(5, 80);
    cout << s;

    return 0;
}
