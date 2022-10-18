#include<iostream>
using namespace std;
void solve() {
	int len, a;
	cin>>len;
	long long ans = 0;
	int last = 0;
	for(int i = 1;i<=len;i++) {
		cin>>a;
		last = min(i, min(a, last+1));
		ans+=last;
	}
	cout<<ans<<endl;
}
int main() {
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}
