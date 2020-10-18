#include<iostream>
#include<stack>
#include<deque>
#include<string>
using namespace std;


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    stack<int> s;
    string str;
    cin >> str;
    for(int i=0 ; i<str.size() ; i++){
        s.push(str[i]-'0');
    }

    deque<char> d;
    while(!s.empty()){
        int n=3, two=1;
        int ans=0;
        while(n>0){
            if(s.top()==1) ans+=two;
            two*=2;
            n--;
        }
        d.push_front(ans);
    }

    
    while(!d.empty()){
        cout << d.front();
        d.pop_front();
    }
    return 0;
}