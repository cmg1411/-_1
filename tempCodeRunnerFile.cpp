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
    stack<char> s;
    cin.ignore();

    while(n--){
        string str;  
        getline(cin, str);
        str += '\n';
        char ch;

        for(int i=0 ; i<str.size()+1 ; i++){
            ch = str[i];
            if(ch==' '||ch=='\n'){
                while(!s.empty()){
                    cout<< s.top();
                    s.pop();
                } 
                cout << ch;
            }else{
                s.push(ch);
            }
        }
    }
    return 0;
}