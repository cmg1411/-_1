#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<pair<int,int> > edge; //간선리스트
vector<int> g[2000]; //인접리스트
bool a[2000][2000];

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin >> n >> m;

    int ans=0;
    for(int i=0 ; i<m ; i++){
        int from, to;
        cin >> from;
        cin >> to;
        edge.push_back({from, to});
        edge.push_back({to, from});
        a[from][to] = true;
        a[to][from] = true;
        g[from].push_back(to);
        g[to].push_back(from);
    }

    m=m*2;

    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<m ; j++){
            int A = edge[i].first;
            int B = edge[i].second;

            int C = edge[j].first;
            int D = edge[j].second;

            if(A==D || B==D || C==D || A==B || A==C || B==C){
                continue;
            }

            if(!a[B][C]){
                continue;
            }

            for(int E : g[D]){
                if(A==E || B==E || C==E || D==E) continue;
                cout << 1 ;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}