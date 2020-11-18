#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> a[1001];
bool check[1001];

void dfs(int x){
    check[x]=true;
    for(int i=0 ; i<a[x].size() ;i++){
        int next = a[x][i];
        if(!check[next])
            dfs(next);
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for(int i=0 ; i<m ; i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    int ans=0;
    for(int i=1 ; i<=n ; i++){ //1부터 끝까지 돌면서
        if(check[i]==false){ 
            dfs(i);     // 처음 돌면서 연결된거 다 true시키고
            ans++;      // 1개로 만든다.
        }               // 이후 false를 만난다면 앞 그래프와 이어지지 않았단 뜻이고 그거 다 true시키고 1++
    }
    cout << ans;
    return 0;
}