/*
    재귀 : 모든것을 다 해보는 브루트포스

    1. 불가능한 경우
    2. 답을 찾은 경우
    3. 다음 방법을 봐야하는 경우
*/

#include<iostream>
using namespace std;

int go(int count, int sum, int goal){
    if(sum>goal) return 0;
    if(sum==goal) return 1;

    int now=0;
    for(int i=1 ; i<=3 ; i++){
        now += go(count+1, sum+i, goal);
    }
    return now;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i=0 ; i<n ; i++){
        int m;
        cin >> m;
        cout << go(0, 0, m) << '\n';
    }

    return 0;
}