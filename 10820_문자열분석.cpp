#include<stdio.h>
#include<string>
using namespace std;

int arr[4] = {0,};

int main(){

    char c;
    while((scanf("%c",&c))!=EOF){
        
        if(c=='\n'){
            for(int i=0 ; i<4 ; i++){
                printf("%d ", arr[i]);
            }
            for(int i=0 ; i<4 ; i++) arr[i] = 0;
        }

        if(c>='a'&&c<='z'){
            arr[0]++;
        }else if(c>='A'&&c<='Z'){
            arr[1]++;
        }else if(c>='0'&&c<='9'){
            arr[2]++;
        }else if(c==' '){
            arr[3]++;
        }
    }
    return 0;
}