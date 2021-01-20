#include<bits/stdc++.h>
using namespace std;
const int maxm = 1000;
int n, m;
int num[maxm];
int main() {
	cin>>n>>m;
	for(int i = 1;i<=n;i++) cin>>num[i];
	num[n+1] = 100000;
	int cnt = 0;
	for(int i = 1;i<=n;i++) {
		if(num[i]&1) cnt++;
		else cnt--;
		if(cnt==0) {
			num[++num[0]] = num[i+1] - num[i];
			if(num[num[0]] < 0) num[num[0]] = -num[num[0]];
		}
	}
	sort(num+1, num+num[0]);
	int ans = 0;
	for(int i = 1;i<=num[0];i++) {
		if(m >= num[i]) {
			m -= num[i];
			ans++;
		} else break;
	}
	cout<<ans<<endl;
	return 0;
}

