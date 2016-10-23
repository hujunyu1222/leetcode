#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class LRUCache{

private:
    unordered_map<int, int> m;
    unordered_map<int, long> timeTable;
    priority_queue <pair<long, int>> lru;

    int nowSize;
    int maxSize;
    long time;

public:
    LRUCache(int capacity) {
        nowSize = 0;
        maxSize = capacity;
        time = 0;
    }

    int get(int key) {
        if (m.find(key) != m.end()){
            timeTable[key] = -time;
            lru.emplace(-time, key);
            time++;
            return m[key];

        }
        else{
            return -1;
        }

    }

    void set(int key, int value) {
        if (m.find(key) != m.end()){
            m[key] = value;
            timeTable[key] = -time;
            lru.emplace(-time, key);
        }
        else{
            if (nowSize < maxSize){
                m[key] = value;
                timeTable[key] = -time;
                nowSize++;
            }
            else{
                while(1){
                    pair<long, int> htop = lru.top();
                    lru.pop();
                    if (timeTable[htop.second] == htop.first){
                        m.erase(htop.second);
                        timeTable.erase(htop.second);
                        break;
                    }
                }

                m[key] = value;
                timeTable[key] = -time;
                lru.emplace(-time, key);
            }
            time++;
        }

    }

    void printCache(){
        for (auto x:m){
            cout << "<" <<x.first << "," << x.second << "> " ;
        }
        cout << endl;
    }
};


int main(){
    LRUCache cache(3);
    cout<<cache.get(2)<<endl;
    cache.set(2,2);
    cache.set(1,1);
    cache.printCache();
    cout<<cache.get(2)<<endl;
    cout<<cache.get(1)<<endl;
    cout<<cache.get(2)<<endl;
    cache.set(3,3);
    cache.set(4,4);
    cache.printCache();




    return 0;
}
