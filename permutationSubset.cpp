#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > res;
vector<int> nums;
int N, K;
vector<bool> vis;

void Permutation(vector<int> &cmb, int cnt, int pre){
    int i;
    int tmp;

    for (i = 0; i < N; i++){
        tmp = cnt;
        if (vis[i] == false && pre <= nums[i]){
            vis[i] = true;
            pre = nums[i];
            if (cnt != K - 1){
                cmb[cnt] = nums[i];
                cnt++;

            }
            else{
                cmb[cnt] = nums[i];
                res.push_back(cmb);
            }

            Permutation(cmb, cnt, pre);

            //cout <<"cnt:" << cnt << " " <<nums[i] << endl;
            vis[i] = false;
            if (tmp == K - 1) break;
            cnt--;
        }

    }

    return;


}

void Permutation2(vector<int> &cmb, int cnt, int pos){
    if(cnt == K){
        res.push_back(cmb);
        return;
    }

    for (int i = pos; i < N; i++){
        cmb.push_back(nums[i]);
        Permutation2(cmb, cnt+1, i+1);
        cmb.pop_back();
    }

    return;



}

void PrintVec(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << '\n';
}

void PrintRes(){
    for(int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << '\n';
    }
}

void initVis(){
    for (int i = 0; i < N; i++) vis.push_back(false);
}

void initCmb(vector<int> &v){
    while(!v.empty()){
        v.pop_back();
    }
}
int main(){
    int n, k;
    cin >> n >> k;
    N = n;
    K = N;
    vector<int> cmb;
    for (int i = 0; i < N; i++) nums.push_back(i+1);



    for (int j = 1; j <= N; j++)
    {

        K = j;
        cout << K << endl;
        initVis();
        initCmb(cmb);
        PrintVec(cmb);
        Permutation2(cmb, 0, 0);
    }
    PrintRes();

    return 0;
}
