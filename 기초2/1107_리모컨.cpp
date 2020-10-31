/*
    번호가 다 고장나거나 해서 +=만 누르는경우 = 최대경우 = abs(눌러야 하는 번호 - 100)

    번호가 고장나지 않아 근접하게 갈 수 있는 경우 = abs(눌러야하는 번호 - 브루트포스 i) + 번호의길이

    중 최솟값을 구해준다.
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool broken[10];

int search(int tmp){
    int res=0;
    if(tmp==0){ // 0의 경우 밑에서 %연산이 먹통됨. 따로 예외처리. 
        if(broken[tmp]) return 0;
        else return 1;
    }else{
        while(tmp>0){
            if(broken[tmp%10]){
                res = 0;
                break;
            }
            res++;
            tmp/=10;
        }
    }
    return res;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int num;
    cin >> num;
    int bronum;
    cin >> bronum;

    for(int i=0 ; i<bronum ; i++){
        int n;
        cin >> n;
        broken[n]=true;
    }

    int ans = abs(100-num); // 눌러야 하는 번호들이 고장나서 +-로만 이동해야하는 최대 경우로 초기화
    for(int i=0 ; i<1000001 ; i++){
        int tmp = i;
        int len = search(tmp); // 고장 났는지 안났는지 확인(고장 났으면 0)
        if(len>0){ // 고장 안났다면, 차이와 번호를 더한다. 모두 고장났다면 초기값이 들어간다.
            int pn = abs(num-i);

            if(ans > pn+len) ans = pn+len; // 100의 경우에는 초기값이 0이므로 이 조건문이 실행되지 않는다.
        }
    }

    cout << ans;
    return 0;
}