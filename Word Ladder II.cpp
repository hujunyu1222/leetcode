#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>

using namespace std;

int minSeq = 0x7FFFFFFF;

vector<vector<int>> pre;
vector<int> visit;
bool canChange(string a, string b){
    int n = a.size();
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (a[i] ^ b[i]) cnt++;
        if (cnt > 1) return false;
    }

    return cnt == 1;
}

void backtracking(string tmpWord, string endWord, vector<string> &wordList, vector<string> &seq,
                  vector<vector<string>> &res, vector<int> &vis){
                      if (seq.size() > minSeq - 2) return;
        for (int i = 0; i < wordList.size(); i++){

            if (canChange(wordList[i], tmpWord) && !vis[i]) {
                    //tmpWord = wordList[i];
                    vis[i] = 1;
            }
            else{
                //cout <<"i: " << i << "tmpWord: " << tmpWord << endl;
                continue;
            }
            if (canChange(wordList[i], endWord)) {
                seq.push_back(wordList[i]);
                seq.push_back(endWord);
                res.push_back(seq);

                minSeq = min(minSeq, (int)seq.size());
                seq.pop_back();


            }
            else{
                seq.push_back(wordList[i]);
                backtracking(wordList[i], endWord, wordList, seq, res, vis);

            }
            //»ØËÝ
            vis[i] = 0;
            seq.pop_back();
        }

        return;
}

vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
    vector<string> vecWordList;
    for (auto it = wordList.begin(); it != wordList.end(); it++){
        vecWordList.push_back(*it);
    }

    vector<vector<string>> res;
    if (vecWordList.size() == 0) return res;

    vector<int> vis(vecWordList.size(), 0);
    vector<string> seq;
    seq.push_back(beginWord);

    if (canChange(beginWord, endWord)){
        seq.push_back(endWord);
        res.push_back(seq);
    }
    else{
        backtracking(beginWord, endWord, vecWordList, seq, res, vis);
        int i;
        for (i = 0; i < res.size(); i++){
            if (res[i].size() == minSeq) break;
        }
        if (i != 0)
        res.erase(res.begin(), res.begin()+i);
    }


    return res;


}

void addPath(string beginWord, string endWord, int pos, vector<vector<int> > &pre, vector<string> &seq, vector<vector<string>> &res, vector<string> &wordList){

    int i, j;
    string s;
    if (pos == -1){
        seq.push_back(endWord);
        minSeq = min((int)seq.size(), minSeq);
        if (seq.size() == minSeq)
        res.push_back(seq);
        seq.pop_back();
        return;
    }
    cout << pos <<": "; for (auto x:pre[pos])cout << x << " ";
    cout << endl;
    for (i = 0; i < pre[pos].size(); i++){
        if (pre[pos][i] == -1) s = beginWord;
        else s = wordList[pre[pos][i]];
        seq.insert(seq.begin(), s);
        addPath(beginWord, endWord, pre[pos][i], pre, seq, res, wordList);
        seq.erase(seq.begin());
    }

}

bool isInPre(int root,int idx, vector<vector<int>> &pre){
    if (root == -1) return false;
    for (int i = 0; i < pre[root].size(); i++){
        if (pre[root][i] == idx) return true;
    }
    return false;
}

vector<vector<string>> findLadders2(string beginWord, string endWord, vector<string> &wordList){
    wordList.push_back(endWord);
    pre = vector<vector<int>>(wordList.size());
    visit = vector<int>(wordList.size(), 0);
    queue<int> q;
    vector<string> seq;
    vector<vector<string>> res;
    //queue<int> idxq;

    int i = 0;
    int mark = -2;
    string tmp;

    bool flag = true;
    q.push(-1);
    q.push(mark);
    while(!q.empty()){

        if (q.front() == mark ){
            if (!flag )
            break;
            else{
                q.pop();
                if (!q.empty())
                q.push(mark);
                continue;
            }
        }
        if (q.front() == -1) tmp = beginWord;
        else tmp = wordList[q.front()];

        //cout << tmp << endl;
        //cout << "1" << endl;

        //idx = idxq.front();

        //cout << "2" << endl;


        for (i = 0; i < wordList.size(); i++){
            if (((wordList[i] == beginWord) || (wordList[i] == endWord)) && (i != wordList.size()-1)) continue;
                cout << tmp << wordList[i] << endl;
            if (!isInPre(q.front(),i, pre) && canChange(tmp, wordList[i])){
                if (!visit[i])
                {
                    q.push(i);
                    visit[i] = 1;
                }
                pre[i].push_back(q.front());
                if (i == int(wordList.size() - 1))
                {
                    flag = false;
                }

            }

        }
        //cout << "2.1" << endl;
        //q.push(mark);
        //cout << "2.2" << endl;

        q.pop();
        //cout << "2.3" << endl;


        //idxq.push(q.front());
        //idx.pop();

    }
    //cout << "3" << endl;
    if(flag) return res;

    //seq.insert(seq.begin(), beginWord);
    addPath(beginWord, endWord, wordList.size()-1, pre, seq, res, wordList);
    /*

    while(!q.empty()){
        if (q.front() == wordList.size() - 1){
            int idx = q.front();
            while(idx != -1){
                seq.insert(seq.begin(),wordList[idx]);
                idx = pre[idx];
            }
            seq.insert(seq.begin(),beginWord);
            res.push_back(seq);
            seq.resize(0);
        }
        q.pop();
    }
    */
    return res;
}

vector<vector<string>> findLadders3(string beginWord, string endWord, vector<string> &wordList){
    unordered_set<string> flag;
    unordered_set<string> q;
    vector<vector<string>> res;


}

void Print(vector<vector<string>> &res){
    if(res.size() == 0) cout << "result is NULL" << endl;
    for (auto x:res){
        for (auto y:x){
            cout << y << " ";
        }
        cout << endl;
    }
}



int main(){
    if (canChange("dog", "hit")) cout << "Yes" << endl;
    string beginWord = "hot";
    string endWord = "dog";
    //unordered_set<string> wordList = {"hot","cog","dog","tot","hog","hop","pot","dot"};
    vector<string> wordList = {"hot","dog",};
    vector<vector<string>> res;

    res = findLadders2(beginWord, endWord, wordList);

    if (res.size() != 0)
    while((*res.begin()).size() > minSeq) res.erase(res.begin());
    /*
    cout << minSeq << endl;
    int i;
    for (i = 0; i < res.size(); i++){
        if (res[i].size() == minSeq) break;
    }
    if (i != 0)
    res.erase(res.begin(), res.begin()+i);
    */

    Print(res);


    return 0;
}
