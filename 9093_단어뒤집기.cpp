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
    cin.ignore();  //띄워쓰기가 있는 입력(getline)는 개행문자까지만 읽는다 --> 앞의 것 무시해야한다. 

    while(n--){
        string str;  
        getline(cin, str);
        str += '\n'; //문자열 여러개 받을 떄 문자열의 끝을 구분하기 위해 '\n' 삽입
        char ch;

        for(int i=0 ; i<str.size() ; i++){
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