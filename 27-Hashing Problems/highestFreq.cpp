#include<iostream>
#include<unordered_map>
#include<climits>
using namespace std;

int main() {
	int n;
	cin>>n;

	unordered_map<int, int> m;

	int d;
	for(int i = 0 ; i < n ; i++){
		cin>>d;
		m[d]++;
	}

	int ans = 0;
	int max = INT_MIN;

	for(unordered_map<int, int> :: iterator it = m.begin(); it != m.end() ; it++){
		if(it->second > max){
			ans = it->first;
			max = it->second;
		}
	}
	cout<<ans;

	return 0;
}
