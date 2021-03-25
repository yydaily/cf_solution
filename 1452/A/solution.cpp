#include<bits/stdc++.h>
using namespace std;
void solve() {
	int a, b;
	cin>>a>>b;
	a = abs(a), b = abs(b);
	int ans = min(a, b);
	a-=ans, b-=ans;
	ans <<= 1;
	if(a) ans += (a<<1) - 1;
	if(b) ans += (b<<1) - 1;
	cout<<ans<<endl;
}
int main() {
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
