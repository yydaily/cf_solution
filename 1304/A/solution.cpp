#include<bits/stdc++.h>
using namespace std; 
void solve() {
	int a, b, c, d;
	cin>>a>>b>>c>>d;
	if(abs(a-b) % (c+d) ==0) cout<<abs(a-b) / (c+d)<<endl;
	else cout<<-1<<endl;
}
int main() {
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
