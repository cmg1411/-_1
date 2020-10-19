#include<iostream>
using namespace std;

void answer(int ten, int m){
    if(ten==0) return;
    answer(ten/m, m);
    cout << ten%m << ' ';
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int num;
    cin >> num;

    int ten=0;
    for(int i=num ; 0<i ; i--){
        int c;
        cin >> c;
        ten = ten*n + c;
    }

    answer(ten, m);

    return 0;
}