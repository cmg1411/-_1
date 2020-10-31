#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    queue<int> q;
    for(int i=1 ; i<=n ; i++){
        q.push(i);
    }

    cout << '<';
    for(int j=0 ; j<n-1 ; j++){ // ,처리를 위해 -1번만 돈다.
        for(int i=0 ; i<m-1 ; i++){
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ", ";
        q.pop();
    }

    cout << q.front();
    cout << '>' ;
    return 0;
}