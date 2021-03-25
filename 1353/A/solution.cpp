#include<bits/stdc++.h>
using namespace std; 
void solve() {
	int a, b;
	cin>>b>>a;
	if(b==1) cout<<0<<endl;
	else if(b==2) cout<<a<<endl;
	else cout<<(a<<1)<<endl;
}
int main() {
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
