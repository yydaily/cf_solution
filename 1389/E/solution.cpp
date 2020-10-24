#include<bits/stdc++.h>
using namespace std;

void solve() {
	long long m,d,w;
	cin>>m>>d>>w;
	long long x = gcd(d-1, w);
	long long upper = min(m, d)-1;
	long long b = w/x;
	long long y = upper / b;
	cout<< (upper+1) * y - y*(y+1) / 2 * b<<endl;
}

int main() {
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}

