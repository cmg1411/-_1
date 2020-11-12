#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> vec;

bool next_per(int n){
    int i=n-1;
    while(i>0 && vec[i-1]>=vec[i]) i-=1;
    if(i<=0) return false;

    int j=n-1;
    while(vec[i-1]>=vec[j]) j-=1;

    swap(vec[i-1], vec[j]);

    j=n-1;
    while(i<j){
        swap(vec[i], vec[j]);
        j-=1; i+=1;
    }
    return true;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i=0 ; i<n ; i++){
        int num;
        cin >> num;
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end());

    int max = -987654321;
    do{
        int sum=0;
        for(int i=0 ; i<n-1 ; i++){
            sum+=abs(vec[i]-vec[i+1]);
        }
        if(max<sum) max=sum;
    }while(next_per(n));

    cout << max;
    return 0;
}