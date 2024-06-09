#include<iostream>
using namespace std;
#define ll long

ll gcd(ll n1 , ll n2){
	if(n2 == 0){
		return n1;
	}
	return gcd(n2 , n1 % n2);
}

int main() {
	ll n1 , n2;
	cin>>n1;
	cin>>n2;
	cout<<gcd(n1 , n2);

	return 0;
}
