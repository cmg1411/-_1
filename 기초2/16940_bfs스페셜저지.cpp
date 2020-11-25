/*
    1. bfs길이보다 짧은 경우
    2. bfs길이보다 긴경우
    3. 상위 노드에 의한 자리가 아닌경우
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>P
#include<cstring>
using namespace std;

int n;
int order[100001];
int parent[100001];
bool check[100001];
vector<int> v[100001];

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=0 ; i<n-1 ; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=0 ; i<n ; i++){
        cin >> order[i];
        order[i]--;
    }

    queue<int> q;
    q.push(0);
    check[0]=true;

    int m=1;
    for(int n=0 ; i<n ; i++){
        if(q.empty()){ // 중간에 bfs가 비었다 >> 예상한 입력이 정답보다 길다.
            cout << 0 ;
            return 0;
        }
        int x = q.front();
        q.pop();
        int cnt=0;
        for(int y : v[x]){
            if(check[y]==false){
                parent[y]=x; //부모노드의 숫자 넣어줌,.
                cnt++; // 이번에 푸시할 요소의 갯수 샌다. size로 하면 안됨(cheeck가 false인거만 해야하니까)
            }
        }
    }

    cout << a;
    return 0;
}