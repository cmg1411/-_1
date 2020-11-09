#include<iostream>
#include<algorithm>
using namespace std;

int cnt[10];
int num[10];
int ans[10];

void solve(int idx, int n, int m){
    if(idx==m){
        for(int i=0 ; i<m ; i++){
            cout << num[ans[i]] << ' ';
        }
        cout << '\n';
        return ;
    }

    for(int i=0 ; i<n ; i++){
        if(cnt[i]>0){
            cnt[i]-=1;
            ans[idx]=i;
            solve(idx+1, n, m);
            cnt[i]+=1;
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    int temp[10];
    for(int i=0 ; i<n ; i++){
        cin >> temp[i];
    }
    sort(temp, temp+n);

    int k=0;
    int c=1;
    int x=temp[0];
    for(int i=1 ; i<n ; i++){
        if(x==temp[i]){
            c++;
        }else{
            num[k]=x;
            x=temp[i];
            cnt[k]=c;
            k++;
            c=1;
        }
    }
    num[k]=x;
    cnt[k]=c;
    solve(0, n, m);
    return 0;
}