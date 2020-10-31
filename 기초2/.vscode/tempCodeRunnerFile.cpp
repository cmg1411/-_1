#include<iostream>
#include<cstring>
using namespace std;

string hexa[550];
int paper[550][550];

int change(char a){
    if('a'<=a && a<='f'){
        return a-87;
    }
    else return a-'0';
}

void draw(string hex, int x, int y){
    int f = change(hex[0]);
    int b = change(hex[1]);
    for(int i=x*8+3 ; x*8<=i ; i--){
        paper[i][y] = f%2;
        f = f/2;
    }
    for(int i=x*8+7 ; x*8+4<=i ; i--){
        paper[i][y] = b%2;
        b = b/2;
    }
}

void encrypt(int xs, int ys, int n){
    bool flag = true;
    for(int i=xs ; i<n+xs ; i++){
        for(int j=ys ; j<n+ys ; j++){
            if(paper[xs][ys] !=paper[i][j]){
                flag = false;
                break;
            }
        }
    }

    if(!flag){
        cout << 'Q';
        encrypt(xs, ys, n/2);
        encrypt(xs, ys+n/2, n/2);
        encrypt(xs+n/2, ys, n/2);
        encrypt(xs+n/2, ys+n/2, n/2);
    }else{
        if(paper[xs][ys] == 1){
            cout << 'W';
        }else{
            cout << 'B';
        }
    }
}




int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    getline(cin, str2);

    str1 = str1.substr(23);
    int n = atoi(str1.c_str()); // atoi(char>int) char을 int로 바꿔줌
                                // atoi(const char *str) 이므로 str을 넘겨줘야함
                                // c_str() 반환형이 char * 이다. 해당 string의 첫번째 문자 주소값을 전달한다.


    for(int i=0 ; i<=n ; i++){
        getline(cin, hexa[i]);
    }

    for(int y=0 ; y<n ; y++){
        for(int x=0 ; x<n/8 ; x++){
            draw(hexa[y].substr(2,4), x, y);
            hexa[y] = hexa[y].substr(5);
        }
    }

    cout << n << '\n';
    encrypt(0,0,n);

    return 0;
}