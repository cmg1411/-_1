#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;

	int temp = n;
	int cnt=0;
    while(n>0){
		n=n/10;
		cnt++;
	}

	int ans=0;
	int digit=1;
	for(int i=1 ; i<cnt ; i++){
		ans+=9*digit*i;
		digit*=10;
	}

	for(int i=0 ; i<=temp-digit ; i++){
		ans += cnt;
	}

	cout << ans;
	return 0;
}

//자릿수 - 9

// 1 - 9
// 2 - 90
// 3 - 900