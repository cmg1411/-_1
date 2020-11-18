#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool check(string v){
    int a=0;
    int b=0;
    for(int i=0 ; i<v.size() ; i++){
        if(v[i]=='a' || v[i]=='e' || v[i]=='o' || v[i]=='i' || v[i]=='u'){
            a+=1;
        }
        else{
            b+=1;
        }
    }

    return (a>=1 && b>=2) ;
}

void go(int l, vector<char> &v, string pass, int idx){
    
    if(pass.size()==l){
        if(check(pass)){
            cout << pass << '\n';
            return;
        }else{
            return ;
        }
    }

    if(idx>=v.size()) return;
    go(l, v, pass+v[idx], idx+1);
    go(l, v, pass, idx+1);
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int l, c;
    cin>> l >> c;

    vector<char> v(c);
    for(int i=0 ; i<c ; i++){
        cin >> v[i];
    }    

    sort(v.begin(), v.end());
    string str="";
    go(l, v, str, 0);

    return 0;
}