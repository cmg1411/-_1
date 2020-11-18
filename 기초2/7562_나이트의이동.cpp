#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int chess[301][301];
int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {2,1,-1,-2,-2,-1,1,2};
int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        memset(chess, 0, sizeof(chess));
        int x, y, destx, desty;
        cin >> x >> y;
        cin >> destx >> desty;
        queue<pair<int, int> > q;
        q.push(make_pair(x, y));
        chess[x][y]=1;
        bool flag = false;
        while(!q.empty()){
            if(flag) break;
            x = q.front().first;
            y = q.front().second;
            q.pop();

            for(int i=0 ; i<8 ; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(0<=nx && 0<= ny && nx<n && ny<n){
                    if(chess[nx][ny]==0){
                        chess[nx][ny]=chess[x][y]+1;
                        q.push(make_pair(nx, ny));
                    }
                    if(nx==destx && ny==desty){
                        cout << chess[nx][ny]-1 << '\n';
                        flag=true;
                        break;
                    }
                }
            }
        }  
    }

    return 0;
}