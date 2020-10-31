#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

double alp[101];

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    string cal;
    cin >> cal;

    for(int i=0 ; i<n ; i++){
        double num;
        cin >> num;
        alp[i] = num;
    }


    stack<double> s;
    int len = cal.size();
    for(int i=0 ; i<len ; i++){
        double a, b;
        if(cal[i]=='+'){
            b = s.top();
            s.pop();
            a = s.top();
            s.pop();
            s.push(a+b);
        }else if(cal[i]=='-'){
            b = s.top();
            s.pop();
            a = s.top();
            s.pop();
            s.push(a-b);
        }else if(cal[i]=='*'){
            b = s.top();
            s.pop();
            a = s.top();
            s.pop();
            s.push(a*b);
        }else if(cal[i]=='/'){
            b = s.top();
            s.pop();
            a = s.top();
            s.pop();
            s.push(a/b);            
        }else{
            s.push(alp[cal[i]-'A']);
        }
    }

    cout << fixed; // 소수점 아래 수로 고정.
    cout.precision(2); // 고정 후 소수점 아래를 2자리로.
    cout << s.top();
    return 0;
}