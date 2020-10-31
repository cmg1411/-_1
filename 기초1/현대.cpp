/*
    n번째에 가장 큰 자본을 가질 수 있는 방법
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> rates = {1500, 1400, 1300, 1200, 1100};
int dp[1001][3];
int dollor[1001][3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //0.아무것도 안함, 1.환전 함, 2.환전받음.
    
    int k=1500;

    dp[1][0]=
    dollor[1][0]=0;
    dp[1][1]=
    dollor[1][1]=1;
    dp[1][2]=1;
    dollor[1][2]=0;



    for(int i=0 ; i<rates.size() ; i++){
        dp[i][0] = max(dp[]);
    }

    return 0;
}