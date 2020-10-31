#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    stack<int> s;

    while(n--){
        string cmd;
        cin >> cmd;
        if(cmd=="push"){
            int num;
            cin >> num;
            s.push(num);
        }else if(cmd=="pop"){
            if(s.empty()) {cout << -1 << '\n'; continue;}
            cout << s.top() << '\n';
            s.pop();
        }else if(cmd=="top"){
            if(s.empty()) {cout << -1 << '\n'; continue;}
            cout << s.top() << '\n';
        }else if(cmd=="empty"){
            cout << s.empty() << '\n';
        }else if(cmd=="size"){
            cout << s.size() << '\n';
        }
    }

    return 0;
}