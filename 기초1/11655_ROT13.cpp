#include<cstdio>
using namespace std;

int main(){
    char c;
    while((c=getchar())!='\n'){
        if('a'<=c && 'z'>=c){
            c = (c-97+13)%26+'a';
        }else if('A'<=c && 'Z'>=c){
            c = (c-65+13)%26+'A';
        }
        printf("%c", c);   
    }
    return 0;
}


