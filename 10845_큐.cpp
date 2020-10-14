#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    string str;

    queue<int> q;
    for(int i=0 ; i<n ; i++){

        cin >> str;

        if(str=="push"){
            int cmd;
            cin >> cmd;
            q.push(cmd);
        }else if(str=="pop"){
            if(q.empty()) cout << "-1" << '\n';
            else{
                cout << q.front() << '\n';
                q.pop();
            }
        }else if(str=="size"){
            cout << q.size() << '\n';
        }else if(str=="empty"){
            if(q.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }else if(str=="front"){
            if(q.empty()) cout << "-1"<< '\n';
            else cout << q.front() << '\n';
        }else if(str=="back"){
            if(q.empty()) cout << "-1" << '\n';
            else cout << q.back() << '\n';
        }
    }

    return 0;
}