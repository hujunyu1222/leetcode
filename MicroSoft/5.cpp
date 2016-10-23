#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

#define mx 1000000


struct timeCount{
    double time;
    int num;
    int lastId;
};

unordered_map<string, timeCount> m;

void buildMap(string s){



}

vector<double> BatchQueryExecutionTime(const vector<string>&sqls, const vector<double>&times, const vector<string>&keywords) {
    int index = 0;

    int cnt[mx];
    bool vis[mx];
    double sumTime[mx];
    int i = 0;

    memset(cnt, 0, sizeof(cnt));
    memset(sumTime, 0, sizeof(sumTime));

    unordered_map<string, int> mp;



    for(i = 0; i < sqls.size(); i++) {
        stringstream sql(sqls[i]);
        string word;
        memset(vis, 0, sizeof(vis));
        while(sql >> word) {
            if(mp.find(word) == mp.end())
                mp[word] = index ++;
            int idx = mp[word];
            if(!vis[idx]) {
                cnt[idx] ++;
                sumTime[idx] += times[i];
                vis[idx] = 1;
            }
        }
    }
    vector<double> res;
    for (i = 0; i < keywords.size(); i++){
        string query = keywords[i];
        if (mp.find(query) != mp.end()){
            res.push_back(sumTime[mp[query]] / cnt[mp[query]]);
        }
    }

    return res;




}


int main(){
    int i, j, k;
    int count = 0;


    return 0;
}
