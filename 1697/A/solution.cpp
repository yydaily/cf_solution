#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n, m, a;
	cin>>n>>m;
	m = -m;
	while(n--) {
		cin>>a;
		m+=a;
	}
	if(m<0) m = 0;
	cout<<m<<endl;
}
int main() {
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
