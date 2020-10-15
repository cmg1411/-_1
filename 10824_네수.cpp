#include<iostream>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    long long int a, ans1=0, ans2=0;
    for(int i=0 ; i<4 ;i++){
        cin >> a;

        if(i==0){
            ans1 += a;
        }else if(i==1){
            int tmp = a;
            ans1=ans1*10;
            while(tmp>=10){
                tmp = tmp/10;
                ans1 = ans1*10;
            }
            ans1+=a;
        }else if(i==2){
            ans2 += a;
        }else if(i==3){
            int tmp = a;
            ans2=ans2*10;
            while(tmp>=10){
                tmp = tmp/10;
                ans2 = ans2*10;
            }
            ans2+=a;
        }
    }
    
    cout << ans1 +ans2;
    return 0;
}


