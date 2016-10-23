#include <iostream>
#include <vector>

using namespace std;

vector<int> getMaxWindow(vector<int> &nums, int wSize){
    vector<int> idxV;
    vector<int> res;
    int i = 0;
    while(i < nums.size()){

        if (idxV.size() == 0){
            idxV.push_back(i++);
        }
        else if ( nums[idxV[idxV.size()-1]] > nums[i]){
            idxV.push_back(i++);
        }
        else{
            idxV.pop_back();
            continue;
        }
        if (i >= wSize && idxV.size()!=0) {
            cout << i << ": "<<idxV[0] << endl;
            res.push_back(nums[idxV[0]]);
        }

        if (idxV[0] == i - wSize){
            idxV.erase(idxV.begin());
        }
    }

    return res;

}

int main(){
    int a[] = {4,3,5,4,3,3,6,7};
    vector<int> nums(a, a+8);
    vector<int> res = getMaxWindow(nums, 4);
    for (auto x: res){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
