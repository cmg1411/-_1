#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    string ans;
    int n, num, m=1;
    cin >> n;

    stack<int> chk;
    for(int i=0 ; i<n ; i++){
        cin >> num;
        if(m<=num){
            while(m<=num){
                chk.push(m);
                m++;
                ans += "+";
            }
            chk.pop();
            ans += "-";
        }else{
            if(num==chk.top()){
                chk.pop();
                ans += "-";
            }
            else{
                cout << "NO";
                return 0;
            }
        }
    }

    for(char c : ans){
        cout << c << '\n';
    }
    return 0;
}