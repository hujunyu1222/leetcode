#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reverse(vector<int>& num, int l, int r)
{
    while(l<r)
    {
        swap(num[l++], num[r--]);
    }
}

//非递归（已经去重）
vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int>> ret;
    sort(num.begin(), num.end());
    int i, j, n = num.size();
    ret.push_back(num);
    while(1)
    {
        for(i=n-2; i>=0 && num[i]>=num[i+1]; i--);

        if(i<0) break;

        for(j=n-1; num[j]<=num[i]; j--);

        swap(num[i], num[j]);

        reverse(num, i+1, n-1);
        ret.push_back(num);
    }
    return ret;
}

//递归版本(已去重)

void Permutation(vector<int> &nums, int pos, vector<vector<int> > &res){
    if (pos == nums.size()){
        res.push_back(nums);
        return;
    }

    for (int i = pos; i < nums.size(); i++){
        while (i != pos && nums[i] == nums[pos]){
            i++;
        }
        if (i >= nums.size()) break;
        swap(nums[pos], nums[i]);
        Permutation(nums, pos+1, res);
        swap(nums[pos], nums[i]);
    }

    return;
}

void Print(vector<vector<int> > &res){
    cout << "==================\n";
    for (auto x:res){
        for (auto y:x){
            cout << y << " ";
        }
        cout << "\n";
    }
    cout << "==================\n";

}


int main(){
    int a[] = {1,1,1,2,3};
    vector<int> nums(a, a+5);
    vector<vector<int> > res;

    Permutation(nums, 0, res);

    Print(res);

    res.resize(0);

    res = permute(nums);

    Print(res);

    return 0;
}

