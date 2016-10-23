#include <iostream>
#include <string>
#include <vector>
using namespace std;

int maxFont(int N, int P, int W, int H, vector<int> graph){
    int n = graph.size();
    int i;
    int maxSize = (W > H ? H: W);
    int eachPage = (W / maxSize) * (H / maxSize);
    int totalPage;
    int l, r, mid;
    int maxPages = -1;
    l = 1;
    r = maxSize;
    mid = (l + r) / 2;
    maxSize = mid;
    while (l<=r){

        totalPage = 0;
        eachPage = (W / maxSize) ;
        for (i = 0; i < n; i++){
                if (graph[i] % eachPage ==0){
                    totalPage += graph[i] / eachPage;
                }
                else{
                    totalPage += graph[i] / eachPage + 1;
                }
        }
        if (totalPage % (H / maxSize) == 0){
            totalPage = totalPage / (H / maxSize);
        }
        else{
            totalPage = totalPage / (H / maxSize) + 1;
        }


        if (totalPage > P){
            r = mid - 1;
            mid = (l + r) / 2;
            maxSize = mid;
        }
        else{
            l = mid + 1;
            mid = (l + r) / 2;
            maxSize = mid;
        }

    }
    return maxSize;
}

int main(){
    vector<int> graph;
    int n;
    int N,P,W,H;
    int i = 0;
    while( cin >> n){
        while(n--){
        cin >> N >> P >> W >> H;
        graph.resize(N);
        for (i=0;i< N; i++){
            cin >> graph[i];
        }

        cout << maxFont(N,P,W,H,graph) << endl;
        }
    }
    //graph.push_back(10);
    return 0;

}
