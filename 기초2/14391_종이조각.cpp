#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int sq[5][5];
int ans=-987654321;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    string str;
    for(int i=0 ; i<n ; i++){
        cin >> str; //문제가 띄워쓰기 없이 주어진다. 스트링으로 받은 다음 숫자로 바꿔서 입력받기
        for(int j=0 ; j<m ; j++){
            sq[i][j] = str[j]-'0';
        }
    }

    for(int s=0 ; s<(1<<(n*m)) ; s++){ //n*m개의 사각형 갯수만큼 브루트포스 돌기
        //1 가로 0 세로
        int sum=0;
        for(int i=0 ; i<n ; i++){
            int cur=0;
            for(int j=0 ; j<m ; j++){
                int k = m*i + j; //가로먼저 본다. 가로순서대로 그 사각형의 번호 = k
                if((s&(1<<k))!=0){ // k번째가 있는 경우의 수인가 확인.
                    cur=cur*10 + sq[i][j]; //있다면 더한다.
                }else{
                    sum+=cur; // 세로가 나왔다면 지금까지 한거 더해주고
                    cur=0; // 자릿수 초기화와 값 초기화 위해 0으로
                }
            }
            sum+=cur; //마지막에 남은거 더해줌
        }

        for(int i=0 ; i<m ; i++){ //세로 봐야하니까 가로인 m을 먼저 고정시켜주고
            int cur=0;
            for(int j=0 ; j<n ; j++){ // 새로 증가시키면서
                int k = m*j + i; // k값 구함.
                if((s&(1<<k))==0){ //0이면 세로
                    cur=cur*10 + sq[j][i];
                }else{
                    sum+=cur;
                    cur=0;
                }
            }
            sum+=cur;
        }

        if(ans<sum) ans = sum;
        
    }

    cout << ans;

    return 0;
}