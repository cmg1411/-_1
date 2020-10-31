/*
    1부터 시작하여 e, s, m에 세가지 모두 만족하는 정수를 출력.
*/


#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;

    int i=1;
    while(1){
        if((i%15)==a%15 && (i%28)==b%28 && (i%19)==c%19) break; // 15, 28, 19의 배수시 그냥 abc와 비교하면 0과 비교하게 되므로 틀림.
        i++;
    }

    cout << i;

    return 0;
}