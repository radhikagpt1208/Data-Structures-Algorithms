#include<iostream>
using namespace std;
#include<cstring>

void replacePi(char *a , int i){
    if(a[i] == '\0' || a[i + 1] == '\0'){
        return;
    }
    if(a[i]=='p' && a[i + 1] == 'i'){
        //shift the further elements by 2 spaces + replace with 3.14
        //shifting from right to left
        for(int j = strlen(a) ; j >= i + 2 ; j--){
            a[j + 2] = a[j];
        }
        //replacing
        a[i] = '3';
        a[i + 1] = '.';
        a[i + 2] = '1';
        a[i + 3] = '4';
        //recursive call on the remaining part
        replacePi(a , i + 4);
    }
    else{
        replacePi(a , i + 1);
    }
    return;
}

int main(){
    char a[1000];
    cin>>a;
    replacePi(a , 0 );
    cout<<a<<endl;
    return 0;
}
