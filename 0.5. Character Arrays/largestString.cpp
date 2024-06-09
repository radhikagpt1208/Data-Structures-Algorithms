#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int n;
    cin>>n;
    char a[1000];
    cin.get();    //to accept the new line character
    char largestString[1000];

    int currentLength=0;
    int maxLength=0;

    for(int i=0; i<n; i++){
        cin.getline(a,1000);
        currentLength = strlen(a);
        if(currentLength>maxLength){
            maxLength = currentLength;
            strcpy(largestString,a);
        }
    }

    cout<<"Largest string is "<<largestString<<" "<<maxLength;
    return 0;
}
