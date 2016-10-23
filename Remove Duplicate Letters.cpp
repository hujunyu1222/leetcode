#include <iostream>
#include <bits/stdc++.h>

using namespace std;


string removeDuplicateLetters(string s) {
    stack<char> st;
    unordered_map<char, int> m;
    int i;
    string res = "";
    bool vis[26];

    for (i = 0; i < s.size(); i++){
        vis[s[i] - 'a'] = false;
        if (m.find(s[i]) == m.end()){
            m[s[i]] = 1;
        }
        else{
            m[s[i]]++;
        }
    }

    //st.push(s[0]);
    //m[s[0]] --;
    for (i = 0; i < s.size(); i++){

        while (!st.empty() && ((s[i] < st.top()) && m[st.top()] != 0)){
            vis[st.top()-'a'] = false;
            st.pop();
        }
        if (st.empty() || (vis[s[i] - 'a'] == false) ){
            st.push(s[i]);
            vis[s[i] - 'a'] = true;
        }
        m[s[i]]--;
    }

    while(!st.empty()){
        //cout << st.top() << endl;
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());

    return res;
}

//方法类似，写法更加简洁
string removeDuplicateLetters2(string s)
    {
        int char_count[26]{0}; //ensure all letters are covered;
        bool visited[26]{false}; //avoid duplicates and meantime accelerate the checking;
        char t[27]; //collector used to collect the letters;
        int size = 0;
        for(int i = 0; s[i]; ++i) char_count[s[i]-'a']++;
        for(int i = 0; s[i]; ++i)
        {
            char_count[s[i]-'a']--;
            if(visited[s[i]-'a']) continue;
            int j = size-1;
            for(; j >= 0; --j) //use un-visited letters to update the collector t;
            {
                if(s[i]>t[j] || !char_count[t[j]-'a']) break; //s[i] is bigger or there is no t[j] in the following substring any more then we should place s[i] just after t[j];
                else visited[t[j]-'a'] = false; //delete from collector t;
            }
            t[++j] = s[i]; //insert to the right position;
            visited[s[i]-'a'] = true; //label s[i] as visited;
            size = j+1; //update the size of collector t;
        }
        t[size] = '\0'; //terminate the collector;
        return t;
}




int main(){
    string s;
    cin >> s;

    cout << "res:" << removeDuplicateLetters(s) << endl;

    return 0;
}
