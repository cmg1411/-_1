#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n;
int ap[26][26];
int check[26][26];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int ans[26*26];

void bfs(int x, int y, int cnt){
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    check[x][y] = cnt;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0 ; i<4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<= nx && nx<n && 0 <= ny && ny < n){
                if(check[nx][ny]==0 && ap[nx][ny]!=0){
                    check[nx][ny] = cnt;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    string str;
    for(int i=0 ; i<n ; i++){
        cin >> str;
        for(int j=0 ; j<n ; j++){
            ap[i][j] = str[j]-'0';
        }
    }

    int cnt=0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(ap[i][j]==1 && check[i][j]==0){
                cnt++;
                bfs(i, j, cnt);
            }
        }
    }

    cout << cnt << '\n';

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(check[i][j]!=0){
                ans[check[i][j]]+=1;
            }
        }
    }
    sort(ans+1, ans+cnt+1);

    for(int i=1 ; i<=cnt ; i++){
        cout << ans[i] << '\n';

    }

    return 0;
}