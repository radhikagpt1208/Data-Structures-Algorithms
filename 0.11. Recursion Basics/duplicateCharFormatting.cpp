#include<iostream>
#include<cstring>
using namespace std;

void formatting(char a[] , int i){
    //base case
	if(i == strlen(a)){
        return;
    }
    //rec case
	if(a[i] == a[i + 1]){
		//shift the character by one place
		for(int j = strlen(a) ; j > i ; j--){
			a[j] = a[j-1];
		}
		a[i + 1] = '*';
	}

	formatting(a , i + 1);
    return;
}

int main(){
    char a[1000];
    cin.getline(a,1000);

    formatting(a , 0);
    cout<<a<<endl;
    return 0;
}

