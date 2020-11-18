#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, m;
vector<int> g[1001];
bool check[1001];

void dfs(int v){
    check[v] = true;
    cout << v << ' ';
    for(int i=0 ; i<g[v].size() ; i++){
        int next = g[v][i];
        if(check[next]==false){
            dfs(next);
        }
    }
}

void bfs(int v){
    queue<int> q;
    memset(check, false, sizeof(check)); //cstring 헤더에 들어있다.
    check[v]=true;
    q.push(v);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << ' ';
        for(int i=0 ; i<g[node].size() ; i++)
        {
            int next = g[node][i];
            if(check[next]==false){
                check[next]=true;
                q.push(next);
            }
        }
    }

}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int v;
    cin >> n >> m >> v;

    for(int i=0 ; i<m ; i++){
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a); // 방향성 없으므로 양방향 모두 저장
    }

    for(int i=1 ; i<n ; i++){
        sort(g[i].begin(), g[i].end());
    }

    dfs(v);
    cout << '\n';
    bfs(v);

    return 0;
}