#include <iostream>
#include <string>
#include <vector>
using namespace std;

//O(n)�����Ӵ���Manacher���㷨
//�Ƚ�ԭʼ�ַ����в��롰#����ʹ���Ӵ���������
//P[i]���ڴ洢�������Ӵ�����
string findPstr(const string &str){
    int n = str.size();
    string res;
    vector<int> P(n+1);
    int id, mx;
    int i;
    id = mx = 0;
    P[0] = 0;


    for (i = 1; i < n; i++){
        //�����if-else��֧
        if (mx > i){
            P[i] = (P[id*2 - i] > mx - i ? mx - i : P[id*2 - i]);
        }
        else{
            P[i] = 1;
        }

        //Ѱ�һ��Ĵ�
        while (str[i - P[i]] == str[i + P[i]]){
            P[i]++;
        }
        //cout << P[i] << "i:" << i << endl;

        if (i + P[i] > mx ){
            mx = i + P[i];
            id = i;
        }

    }
    int index = 0;
    int max = -1;
    for (i = 1; i < n; i++){
        if (P[i] > max){
            max = P[i];
            index = i;
        }
    }
    max --;
    int startS = index - max;
    int endS = index + max;
    for (i = startS;i <= endS; i++){
        if (str[i]!='#')
        {
            res+= str[i];
        }
    }
    return res;
}

int main(){

    string s;
    string temp;
    string pSubs;
    int i;
    int n;

    cin >> s;
    n = s.size();
    temp +='$';
    for (i=0;i<n;i++){
        temp += '#';
        temp +=s[i];
    }
    temp += '#';
    cout <<temp << endl;

    pSubs = findPstr(temp);
    cout << pSubs;



    return 0;
}
