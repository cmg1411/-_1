#include<iostream>
#include<deque>
#include<string>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string str;

    deque<int> d;
    for(int i=0 ; i<n ; i++){

        cin >> str;

        if(str=="push_front"){
            int cmd;
            cin >> cmd;
            d.push_front(cmd);
        }else if(str=="push_back"){
            int cmd;
            cin >> cmd;
            d.push_back(cmd);
        }else if(str=="pop_front"){
            if(d.empty()) cout << "-1\n" ;
            else{
                cout << d.front() <<'\n';
                d.pop_front();
            }
        }else if(str=="pop_back"){
            if(d.empty()) cout << "-1\n" ;
            else{
                cout << d.back() <<'\n';
                d.pop_back();
            }
        }else if(str=="size"){
            cout << d.size() << '\n';
        }else if(str=="empty"){
            if(d.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }else if(str=="front"){
            if(d.empty()) cout << "-1"<< '\n';
            else cout << d.front() << '\n';
        }else if(str=="back"){
            if(d.empty()) cout << "-1" << '\n';
            else cout << d.back() << '\n';
        }
    }

    return 0;
}