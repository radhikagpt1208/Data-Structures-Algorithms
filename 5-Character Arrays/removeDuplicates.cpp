#include<iostream>
#include<cstring>
using namespace std;

void removeDuplicates(char a[]){
    int length = strlen(a);
    if(length==0 || length==1){
        return;
    }
    int previous=0;
    for(int current=1;current<length; current++){
        if(a[current]!=a[previous]){
            previous++;
            a[previous]=a[current];
        }
    }
    a[previous+1]='\0';
    return;
}

int main(){
    char a[1000];
    cin.getline(a,1000);
    removeDuplicates(a);
    cout<<a<<endl;

    return 0;
}
