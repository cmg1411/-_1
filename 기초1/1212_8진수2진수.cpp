#include<iostream>
#include<stack>
#include<string>
using namespace std;

string ans[8] = {"000","001","010","011","100","101","110","111"};
string ans2[8] = {"0","1","10","11","100","101","110","111"};

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    string str;
    cin >> str;

    for(int i=0 ; i<str.size() ; i++){
        if(i==0) cout << ans2[str[i]-'0'];
        else cout << ans[str[i]-'0'];
    }

    return 0;
}

// #include<iostream>
// #include<stack>
// #include<string>
// using namespace std;


// int main(){
//     cin.tie(0);
//     cout.tie(0);
//     ios_base::sync_with_stdio(false);

//     int arr[3];

//     stack<int> s, ans;
//     string str;
//     cin >> str;

//     if(str=="0"){
//         cout << 0 ; 
//         return 0;
//     }

//     for(int i=0 ; i<str.size() ; i++){
//         s.push(str[i]-'0');
//     }

//     while(!s.empty()){
//         int div=4;
//         int num=s.top();
//         s.pop();
//         for(int i=0 ; i<3 ; i++){
//             if(num/div==1)
//                 arr[i]=1;
//             else arr[i]=0;
//             num=num%div;
//             div=div/2;
//         }

//         for(int i=2 ; 0<=i ; i--){
//             ans.push(arr[i]);
//         }
//     }

//     bool flag = false;
//     while(!ans.empty()){
//         if(ans.top()==0&&!flag){ ans.pop(); continue;}
//         else flag=true;
//         cout << ans.top();
//         ans.pop();
//     }

//     return 0;
// }