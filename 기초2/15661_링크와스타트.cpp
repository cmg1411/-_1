#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int s[21][21];
int ans=987654321;

void go(int player, vector<bool> &star){
    if(player==n){
        if(star.size()==0) return;
        int diff=0;
        int a=0;
        int b=0;
        for(int i=0 ; i<star.size() ; i++){
            for(int j=0 ; j<star.size() ; j++){
                if(i==j) continue;
                if(star[i]==true && star[j]==true){
                    a+=s[star[i]][star[j]];
                }else if(star[i]==false && star[j]==false){
                    b+=s[star[i]][star[j]];
                }
            }
        }
        diff = abs(a-b);
        if(diff<ans) ans=diff;
        return;
    }

    star[player] = true;
    go(player+1,star);
    star[player] = false;
    go(player+1,star);
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cin >> s[i][j];
        }
    }

    vector<bool> star;
    go(0, star);

    cout << ans;

    return 0;
}