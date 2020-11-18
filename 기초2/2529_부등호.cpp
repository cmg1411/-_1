#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
char bu[10];
bool use[10];
vector<string> ans;

bool check(char x, char y, char bu){
    if(bu=='<'){
        return x<y;
    }else if(bu=='>'){
        return x>y;
    }else{
        return false;
    }
}

void go(int idx, string str){
    if(idx==n+1){
        ans.push_back(str);
        return ;
    }
    for(int i=0 ; i<=9 ; i++){
        if(use[i]) continue;
        if(idx==0 || check(str[idx-1], i+'0', bu[idx-1])){
            use[i]=true;
            go(idx+1, str+to_string(i));
            use[i]=false;
        }
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=0 ; i<n ; i++){
        cin >> bu[i];
    }

    
    go(0, "");

    sort(ans.begin(), ans.end());
    cout << ans[ans.size()-1] << '\n' << ans[0];

    return 0;
}