
#include<iostream>
using namespace std;
#define ll long

ll gcd(ll n1 , ll n2){
	if(n2 == 0){
		return n1;
	}
	return gcd(n2 , n1 % n2);
}

ll lcm(ll n1 , ll n2 , ll hcf){
	return (n1 * n2)/hcf;
}

int main() {
	ll n1 , n2;
	cin>>n1;
	cin>>n2;
	int hcf = gcd(n1 , n2);
	cout<<lcm(n1 , n2 , hcf);

	return 0;
}
