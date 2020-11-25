#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int n;
vector<int> v[3001];
int check[3001]; //0:미방문 1:방문 2:싸이클
int dist[3001];

int dfs(int x, int p){
    if(check[x]==1) return x;
    check[x]=1; //방문체크
    for(int y : v[x]){ //인접리스트 확인
        if(y==p) continue;
        int res = dfs(y, x);
        if(res==-2) return -2;
        if(res>=0){
            check[x]=2;
            if(res==x) return -2;
            else return res;
        }
    }
    return -1;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0 ; i<n ; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1, -1);

    queue<int> q;
    for(int i=1 ; i<=n ; i++){
        if(check[i]==2){
            dist[i]=0;
            q.push(i);
        }else{
            dist[i]=-1;
        }
    }

    while(!q.empty()){
        int nx = q.front();
        q.pop();
        for(int dx : v[nx]){
            if (dist[dx]==-1){
                dist[dx] = dist[nx]+1;
                q.push(dx);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << ' ';
    }
    

    return 0;
}