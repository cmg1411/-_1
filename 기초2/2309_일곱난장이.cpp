    /*
        9명의 몸무게의 합을 구한 뒤 그중 2명을 빼서 100이면 7난장이가 된다.

        9C2를 N^2만큼 하면 되는데 값이 9이므로 충분히 브루트포스 방법이 가능.
    */
    
    #include<iostream>
    #include<algorithm>
    using namespace std;

    int hobit[9];

    int main(){
        cin.tie(nullptr);
        ios_base::sync_with_stdio(false);

        int sum=0;
        for(int i=0 ; i<9 ; i++){
            cin >> hobit[i];
            sum += hobit[i];
        }

        sort(hobit, hobit+9); // 오름차순으로 정렬하라 그랬음.

        for(int i=0 ; i<9 ; i++){
            for(int j=0 ; j<9 ; j++){
                if(sum-hobit[i]-hobit[j]==100 && i!=j){
                    for(int k=0 ; k<9 ; k++){
                        if(k!=i && k!=j)
                            cout << hobit[k] << '\n';
                    }
                    return 0; // 하나만 출력하고 관두기.
                }
            }
        }

        return 0;
    }