#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(const string &s1, const string &s2){
    return s1<s2;
}

int main(){

    queue<char> q1, q2;
    vector<string> v;

    char c;
    while(cin>>c){
        q1.push(c);
    }
    
    while(!q1.empty()){
        string subst;
        q2 = q1;
        while(!q2.empty()){
            subst+=q2.front();
            q2.pop();
        }
        q1.pop();
        v.push_back(subst);
    }

    sort(v.begin(), v.end(), cmp);

    for(int i=0 ; i<v.size(); i++){
        cout << v[i] << '\n';
    }

    return 0;
}