#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, n;
    char c;
    cin >> n;


    for(int i = 0 ; i < n ; i++){
        int a, b;
        cin >> a >> c >> b;
        cout << a+b << '\n';
    }

    return 0;
}