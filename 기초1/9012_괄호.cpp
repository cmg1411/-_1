#include<iostream>
#include<stack>
#include<string>
using namespace std;

string solution(string str){
    stack<char> s;
    for(int i=0 ; i<str.size() ; i++){
        if(str[i]=='('){
            s.push('(');
        }else{
            if(s.empty()){
                return "NO" ;
            }
            s.pop();
        }
    }

    if(s.empty()) return "YES";
    else return "NO";
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string str, ans;

    for(int i=0 ; i<n ; i++){
        cin >> str;

        cout << solution(str) << '\n';
    }

    return 0;
}