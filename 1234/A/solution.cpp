#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n, a;
	int sum = 0;
	cin>>n;
	for(int i = 0;i<n;i++) {
		cin>>a;
		sum+=a;
	}
	cout<<sum/n + (sum%n != 0)<<endl;
}
int main() {
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
