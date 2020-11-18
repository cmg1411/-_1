#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, s;
    int ans=0;
    cin >> n >> s;

    vector<int> vec(n);

    for(int i=0 ; i<n ; i++){
        cin >> vec[i];
    }

    int bi=0;

    for(int i=1 ; i<(1<<n) ; i++){
        int sum=0;
        for(int k=0 ; k<n ; k++){
            if(i&(1<<k)){
                sum+=vec[k];
            }
        }

        if(sum==s){
            ans+=1;
        }
    }

    cout << ans;
    return 0;
}