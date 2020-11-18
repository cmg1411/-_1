#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int s=0;

    while(n--){
        string str;
        int x;
        cin >> str;
        
        if(str=="add"){
            cin >> x; x--;
            s = (s|(1<<x));
        }else if(str=="remove"){
            cin >> x;
            x--;
            s = (s & ~(1<<x));
        }else if(str=="check"){
            cin >> x;
            x--;
            if((s & (1<<x))==0){
                cout << 0 << '\n';
            }else{
                cout << 1 << '\n';
            }
        }else if(str=="toggle"){
            cin >> x;
            x--;
            s = (s ^ (1<<x));
        }else if(str=="all"){
            s = (1<<20)-1;
        }else if(str=="empty"){
            s=0;
        }
    }

    return 0;
}