#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int s[21][21];
int ans=987654321;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cin >> s[i][j];
        }
    }


    for(int i=0 ; i<(1<<n) ; i++){
    vector<int> star;
    vector<int> link;
        for(int j=0 ; j<n ; j++){
            if(i & (1<<(j)))
                star.push_back(j);
            else
                link.push_back(j);
        }

        if(star.size()!=n/2) continue;
        if(link.size()!=n/2) continue;

        int a=0;
        int b=0;
        for(int i=0 ; i<star.size() ; i++){
            for(int j=0 ; j<star.size() ; j++){
                if(i==j) continue;
                a+=s[star[i]][star[j]];
            }
        }
        for(int i=0 ; i<link.size() ; i++){
            for(int j=0 ; j<link.size() ; j++){
                if(i==j) continue;
                b+=s[link[i]][link[j]];
            }
        }

        int diff=abs(a-b);
        if(ans>diff) ans=diff;
    }    

    cout << ans;

    return 0;
}