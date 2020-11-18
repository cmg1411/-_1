#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> a[20001];
int check[20001];

void dfs(int x, int c){
    check[x] = c;
    for(int i=0 ; i<a[x].size() ; i++){
        int next = a[x][i];
        if(!check[next]){
            dfs(next, 3-c);
        }
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int k;
    cin >> k;

    while(k--){
        int n, m;
        cin >> n >> m;

        for(int i=0 ; i<=n ; i++){
            a[i].clear();
            check[i]=0;
        }

        for(int i=0 ; i<m ; i++){
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }

        for(int i=1 ; i<=n ; i++){
            if(check[i]==0){
                dfs(i, 1);
            }
        }

        bool ans = true;
        for(int i=1 ; i<=n ; i++){
            for(int j=0 ; j<a[i].size() ; j++){
                int b = a[i][j];
                if(check[i]==check[b])
                    ans = false;
            }
        }

        if(ans) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }


    return 0;
}