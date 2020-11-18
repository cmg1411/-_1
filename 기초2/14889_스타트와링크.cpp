#include<iostream>
#include<vector>
using namespace std;

int s[21][21];
int n;
int ans = 987654321;

void go(int player, vector<int> &star, vector<int> &link){
    if(star.size()>n/2) return;
    if(link.size()>n/2) return;
    if(player==n){
      int diff=0;
      int a=0, b=0;
      for(int i=0 ; i<n/2 ; i++){
        for(int j=0 ; j<n/2 ; j++){
            if(i==j) continue;
            a+=s[star[i]][star[j]];
            b+=s[link[i]][link[j]];
        }
      }
      diff=abs(a-b);
      if(ans>diff) ans=diff;
      return ;
    }

    star.push_back(player);
    go(player+1, star, link);
    star.pop_back();
    link.push_back(player);
    go(player+1, star, link);
    link.pop_back();

}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cin >> s[i][j];
        }
    }

    vector<int> star, link;
    go(0, star, link);

    cout << ans;

    return 0;
}