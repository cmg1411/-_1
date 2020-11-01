#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;

	while(n--){
		int m,n,x,y;
		cin >> m >> n >> x >> y;
        if(x==1 && y==1){
            cout << 1 << '\n';
            continue;
        }
		x--;
		y--;
		bool flag=true;
        int i;
		for(i=x ; i<=m*n ; i=i+m){
			if(i%n==y){
				flag=false;
				break;
			}
        }
        if(flag){
            cout << -1 << '\n';
        }else{
            cout << i+1 << '\n';
	    }
	}
	return 0;
}