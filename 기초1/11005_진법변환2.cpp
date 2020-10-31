#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    long long int n, b;
    cin >> n >> b;

    stack<char> s;

    while(n!=0){
        if((n%b)>9) s.push(n%b+'A'-10);
        else s.push(n%b+'0');
        n = n/b;
    }

    while(!s.empty()){
        cout << s.top();
        s.pop();
    }

    return 0;
}