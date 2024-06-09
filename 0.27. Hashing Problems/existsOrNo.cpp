#include<iostream>
#include<unordered_set>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;

		unordered_set<int> s;
		for(int i = 0 ; i < n ; i++){
            int d;
			cin>>d;
			s.insert(d);
		}

		int q;
        cin>>q;
		while(q--){
            int qt;
			cin>>qt;
			if(s.find(qt) != s.end()){
				cout<<"Yes"<<endl;
			}
			else{
				cout<<"No"<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}
