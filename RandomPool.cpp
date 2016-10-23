#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class RandomPool{
private:
    unordered_map<int, int> keyIndexMap;
    unordered_map<int, int> indexKeyMap;
    int size;

public:
    RandomPool():size(0){}

    void insertKey(int key){
        if (!this->keyIndexMap.count(key)){
            this->keyIndexMap[key] = this->size;
            this->indexKeyMap[this->size] = key;
            this->size++;
        }
    }

    void deleteKey(int key){
        if (!this->keyIndexMap.count(key)){
            return;
        }
        int lastIndex = --this->size;
        int lastKey = this->indexKeyMap[lastIndex];
        int delIndex = this->keyIndexMap[key];

        this->keyIndexMap[lastKey] = delIndex;
        this->indexKeyMap[delIndex] = lastKey;

        this->keyIndexMap.erase(key);
        this->indexKeyMap.erase(lastIndex);

    }

    int getRandom(){
        if (this->size == 0){
            return -1;
        }

        int randomIndex = rand() % this->size;
        return this->indexKeyMap[randomIndex];
    }


};

int main(){
    srand(time(0));
    RandomPool rp;

    for (int i = 1; i <= 5; i++){
        rp.insertKey(i);
    }



    for (int i = 1; i <= 100; i++){
        cout << rp.getRandom() << endl;
    }


    return 0;
}
