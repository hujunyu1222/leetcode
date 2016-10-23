#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class RandomizedCollection {
private:
    vector<int> nums;
    unordered_map<int, vector<int> > m;
    int size;

public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        this->size++;
        nums.push_back(val);
        if (m.find(val) != m.end()){
            m[val].push_back(size - 1);
            return false;
        }
        else{
            m[val] = vector<int>(0);
            m[val].push_back(size - 1);
            return true;
           }

    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (m.find(val) != m.end()){
            this->size--;
            int index = m[val].back();
            m[nums.back()].pop_back();
            m[nums.back()].push_back(index);
            nums[index] = nums.back();

            m[val].pop_back();
            nums.pop_back();
            if (m[val].empty()){
                m.erase(val);
            }

            return true;

        }

        return false;

    }

    /** Get a random element from the collection. */
    int getRandom() {
        int index = rand() % this->size;

        return nums[index];
    }
};

int main(){

    return 0;
}
