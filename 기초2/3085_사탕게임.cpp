/*
    사탕을 옆과 바꾸고 긴 갯수 새고, 밑과 바꾸고 긴 갯수 새고,
    그 옆 사탕 기준으로 위 반복 .... 모든 사탕을 기준으로 위, 아래를 반복.


*/

#include<iostream>
using namespace std;

char candy[50][50];

int search(int n){
    int max = -987654321;;
    for(int i=0 ; i<n ; i++){
        int cnt=1;
        for(int j=1 ; j<n ; j++){ // 가로로 가장 긴 경우
            if(candy[i][j]==candy[i][j-1])
                cnt++;
            else
                cnt=1;
            if(max<cnt) max = cnt;
        }

        cnt=1;
        for(int j=1 ; j<n ; j++){ // 세로로 가장 긴 경우
            if(candy[j][i]==candy[j-1][i])
                cnt++;
            else
                cnt=1;
            if(max<cnt) max = cnt;
        }
    }

    return max;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cin >> candy[i][j]; 
        }
    }

    int max = 0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){ //모든 사탕을 돌면서
            if(j+1<n){ // 옆 사탕과 바꾼다.
                swap(candy[i][j], candy[i][j+1]);
                int temp = search(n);
                if(max<temp) max = temp; // 최댓값이면 갱신
                swap(candy[i][j], candy[i][j+1]);
            }
            if(i+1<n){ // 밑 사탕과 바꾼다.
                swap(candy[i][j], candy[i+1][j]);
                int temp = search(n);
                if(max<temp) max = temp; // 최댓값이면 갱신
                swap(candy[i][j], candy[i+1][j]);   
            }
        }   
    }

    cout << max;

    return 0;
}