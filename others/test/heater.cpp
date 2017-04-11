#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(heaters.begin(), heaters.end());
    int minRadius = 0;
    
    for (int i = 0; i < houses.size(); ++i){
        vector<int>::iterator beh, pre;
        beh = lower_bound(heaters.begin(), heaters.end(), houses[i]);

        //Must inside the loop
        int curRadius = 0x7FFFFFFF;
        //If we found such a heater
        if (beh != heaters.end()){
            curRadius = *beh - houses[i];
        }

        if (beh != heaters.begin()){
            curRadius = min(curRadius, houses[i] - *(beh - 1) );
        }
        
        minRadius = max(minRadius, curRadius);
    }

    return minRadius;
    
}


int main(){
    vector<int> houses{4,7};
    vector<int> heaters{1};

    cout << findRadius(houses, heaters) << endl;

    system("pause");

    return 0;
}