#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <time.h>
#include <cstring>
#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

template<class K, class V>
class MapWithExpiringEntry{

private:
    unordered_map<K, pair<V, long> > hash_map;
    map<long, unordered_set<K> > tree_map;

public:
    long now(){
        //返回毫秒级的系统时间
        return (long)time(NULL) * 1000;
    }


    void put(K key, V value, long durationMs){
        if (hash_map.count(key)){
            tree_map[hash_map[key].second].erase(key);
        }
        long delTime = now() + durationMs;
        hash_map[key] = make_pair(value, delTime);
        tree_map[delTime].insert(key);
    }

    V* get(K key){
        if (hash_map.count(key) == 0){
            return NULL;
        }
        long nowTime = now();
        pair<V,long> tmp = hash_map[key];

        if (nowTime <= tmp.second){
            return &tmp.first;
        }
        else{
            //是否需要写个while?
            tree_map[tmp.second].erase(key);
            hash_map.erase(key);
            return NULL;
        }
    }

    void clear(){
        long nowTime = now();
        auto it = tree_map.begin();
        while(it != tree_map.end()){
            if (it->first < nowTime){
                for (auto jt : it->second){
                    hash_map.erase(jt);
                }
            }
            it++;
        }


    }



};

int main(){
    MapWithExpiringEntry<int, int> M;
    M.put(10,25,5000);

    cout << *(M.get(10)) << endl;

    cout << (long)time(NULL) << endl;

    Sleep(3000);

    cout << (long)time(NULL) << endl;

    if (M.get(10))
        cout << *(M.get(10)) << endl;
    else{
        cout << "NULL" << endl;
    }
    return 0;
}


