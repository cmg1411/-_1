#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int n;
int ans[11];
int bu[11][11];

bool check(int idx){
	int sum = 0;
    for (int i=idx; i>=0; i--) {
        sum += ans[i];
        if (bu[i][idx] == 0) {
            if (sum != 0) return false;
        } else if (bu[i][idx] < 0) {
            if (sum >= 0) return false;
        } else if (bu[i][idx] > 0) {
            if (sum <= 0) return false;
        }
    }
    return true;
}
// 틀린거 or 틀린거 or 틀린거 if로 가능
// 맞는거는 셋 다 맞아야함 and로 구현해야함

bool go(int idx){
	if(idx==n) return true;

	if(bu[idx][idx]==0){
		ans[idx]=0;
		return check(idx) && go(idx+1);
	}

	for(int i=1 ; i<=10 ; i++){
		ans[idx] = bu[idx][idx]*i;
		if(check(idx) && go(idx+1)) return true;
	}

	return false;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

	cin >> n;
	string str;
	cin.ignore();
	getline(cin, str);
	int cnt=0;
	for(int i=0 ; i<n ; i++){
		for(int j=i ; j<n ; j++){
			if(str[cnt]=='0'){
				bu[i][j]=0;
			}else if(str[cnt]=='-'){
				bu[i][j]=-1;
			}else if(str[cnt]=='+'){
				bu[i][j]=1;
			}
			cnt++;
		}
	}

	go(0);

	for(int i=0 ; i<n ; i++){
		cout << ans[i] << ' ';
	}

    return 0;
}