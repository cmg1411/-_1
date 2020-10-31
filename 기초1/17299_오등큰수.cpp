#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int freq[1000001];

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> ans(n);
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }

    stack<int> s;
    s.push(0);

    for(int i=1 ; i<n ; i++){
        while(!s.empty()&&freq[arr[s.top()]]<freq[arr[i]]){
            ans[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    while(!s.empty()){
        ans[s.top()]=-1;
        s.pop();
    }

    for(int i=0 ; i<n ; i++){
        cout << ans[i] << ' ';
    }

    return 0;
}