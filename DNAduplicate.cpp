#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
        /** cost to store the string directly is high **/
        /** we can change the string segment to a int value **/
        /** we can always use bit map to save memory if 32 bits or 64 bits is enough **/
        /** we use 3 bits to represent 'ACGT' **/

        unordered_map<int, bool> m;
        unordered_map<char, int> dict;
        dict['A']=0, dict['C']=1, dict['G']=2, dict['T']=3;

        vector<string> result;
        for(int t=0, i=0; i<s.size(); i++){
            /** 0xFFFFF : get the last 20 bits of the number **/
            //cout << "before:" << t << endl;
            t=((t<<2) & 0xFFFFF | dict[s[i]]);

            if(i<9) continue;

            cout << "after:" << t << endl;
            if(m.find(t)!=m.end()){

                if(m[t]){
                    result.push_back(s.substr(i-9, 10));
                    m[t]=false;
                }
            }

            else{
                m[t]=true;
            }

        }
        return result;
    }
//思路一样，但是没做string to int的转换，直接将子串作为
//unordered_map 的key。
//经测试方法2比1慢
vector<string> findRepeatedDnaSequences2(string s) {
    vector<string> ans;
    unordered_map<string, int> mp;

    if(s.length()<10)
    return ans;

    for(int i=0;i<s.length()-9;i++)
    {
        mp[s.substr(i,10)]++;
    }

    for(int i=0;i<s.length()-9;i++)
    {
        //checking for frequency of substring
        if(mp.find(s.substr(i,10))->second>1)
        {
            ans.push_back(s.substr(i,10));
            mp[s.substr(i,10)]=0;
        }
    }
    return ans;
}

int main(){
    vector <string> result;
    string s="AAAAACCCCCAAAAACCCCCAAAAAGGGTTT";
    int n;
    int i;
    int test = 0;
    test = 349184<<2 & 0xFFFFF;

    result = findRepeatedDnaSequences(s);
    n = result.size();
    cout << n << endl;
    cout << "test:"<< test <<endl;
    for (i = 0; i < n; i++){
        cout<<result[i]<<endl;
    }
    cout<< "finished!"<<endl;
    return 0;
}
