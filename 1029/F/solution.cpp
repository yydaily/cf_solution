#include<bits/stdc++.h>
using namespace std;
void solve(long long a, long long b) {
	vector<pair<long long, long long>> v;
	for(int i = 1;i<=2e7;i++) {
		if(a%i==0) v.push_back(make_pair(i, a/i));
		if(b%i==0) v.push_back(make_pair(i, b/i));
	}
	a+=b;
	long long ans = a*2 + 2;
	for(int i = 1;i<=2e7;i++) {
		if(a%i==0) {
			for(auto x : v) {
				if(x.first <= i && x.second <=a/i)  ans = min(ans, i*2 + (a/i)*2);
				if(x.first <= a/i && x.second <= i) ans = min(ans, i*2 + (a/i)*2);
			}
		}
	}
	cout<<ans<<endl;
}
int main() {
	long long a, b;
	while(cin>>a>>b){
		solve(a,b);
	}
	return 0;
}

