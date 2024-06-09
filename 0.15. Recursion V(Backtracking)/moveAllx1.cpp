#include<iostream>
#include<cstring>
using namespace std;

void move_all_x(char *str , int len , int i){
	//base case
	if(i == len){
		str[i] = '\0';
		cout<<str;
		return;
	}
	//rec case
	if(str[i] == 'x'){
		for(int k = i ; k < strlen(str) ; k++){
			str[k] = str[k + 1];
		}
		str[len - 1] = 'x';
	}
	move_all_x(str , len , i + 1);
}

int main() {
	char str[1000];
	cin>>str;

	int len = strlen(str);
	move_all_x(str , len , 0);
	return 0;
}
