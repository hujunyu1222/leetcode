#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if (a.first == b.first){
        if (a.second == b.second){
            return false;
        }
        else if (a.second > b.second){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        if (a.first > b.first) return false;
        else return true;
    }

}

int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.size() == 0) return 0;

        sort(envelopes.begin(), envelopes.end(), compare);
        vector<int> ends(envelopes.size());
        ends[0] = envelopes[0].second;

        int l, r, m;
        int i;
        int right = 0;
        for (i = 1; i < envelopes.size(); i++){
            l = 0;
            r = right;
            while(l <= r){
                m = (l + r) / 2;
                if (envelopes[i].second > ends[m]){
                    l = m + 1;
                }
                else{
                    r = m - 1;
                }
            }
            ends[l] = envelopes[i].second;
            right = max(right, l);
        }

        return right + 1;
}


int main(){
    vector<pair<int, int> > v = {{6,4},{6,7},{5,4},{2,3}};

    sort(v.begin(), v.end(), compare);

    pair<int, int> a = {6, 7};
    pair<int, int> b = {5, 4};
    cout << compare(a, b) << endl;

    for (auto x : v){
        cout << x.first << " " << x.second << endl;
    }


    return 0;
}
