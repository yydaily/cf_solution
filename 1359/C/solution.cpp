#include<bits/stdc++.h>
using namespace std;

void solve() {
	long long a, b, c;
	cin>>a>>b>>c;
	c-=b, a-=b, b=0;
	if(c<=a/2) {printf("2\n"); return;}
	if(c>=a) {printf("1\n"); return;}
	long long x = (c-a) / (a - 2*c);
	long long ans = x*2+1;
	long long diff = abs((x+1) * a - (2*x+1) * c);
	for(long long i = x-3;i<=x+3;i++) {
		long long now_diff = abs((i+1)*a - (2*i+1)*c);
		if((now_diff-diff)*ans < (2*i+1-ans)*diff){
			ans = i<<1|1;
			diff = now_diff;
		}
	}
	cout<<ans<<endl;
}

int main() {
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}

