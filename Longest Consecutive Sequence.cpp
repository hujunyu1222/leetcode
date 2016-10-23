#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // using map
    /*
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int>m;
        int ans = -1;
        for(int i : nums){
            if(m.find(i) == m.end()){
                int leftnum = (m.find(i - 1) != m.end() ? m[i - 1] : 0);
                int rightnum = (m.find(i + 1) != m.end() ? m[i + 1] : 0);
                m[i] = leftnum + rightnum + 1;
                m[i - leftnum] = m[i];
                m[i + rightnum] = m[i];
                ans = max(ans, m[i]);
            }
        }
        return ans;
    }
    */
    //using union find
    vector<int> size;
    vector<int> p;
    int ans;
    int find(int x){
        return x == p[x] ? x : p[x] = find(p[x]);
    }
    void unionFind(int a, int b){
        int pa = find(a);
        int pb = find(b);
        if(pa == pb){
            return;
        }
        p[pa] = pb;
        size[pb] += size[pa];
        ans = max(ans, size[pb]);
    }
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        ans = 1;
        p = vector<int>(nums.size());
        size = vector<int>(nums.size(), 1);
        iota(p.begin(), p.end(), 0);//生成从0开始的有序序列
        unordered_map<int, int>m;
        int idx = -1;
        for(int i : nums){
            ++idx;
            if(m.find(i) == m.end()){
                m[i] = idx;
                if(m.find(i - 1) != m.end()){
                    unionFind(idx, m[i - 1]);
                }
                if(m.find(i + 1) != m.end()){
                    unionFind(idx, m[i + 1]);
                }
            }
        }
        return ans;
    }
};
