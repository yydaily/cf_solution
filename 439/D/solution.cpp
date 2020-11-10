#include<bits/stdc++.h>
using namespace std;
const int len = 1e6 + 10;
int n, m;
long long num1[len], num2[len], all_num[len<<1];
long long cal(long long val) {
	long long ret = 0;
	for(int i = 0;i<n;i++) {
		if(num1[i]>=val) continue;
		ret += val - num1[i];
	}
	for(int i = 0;i<m;i++) {
		if(num2[i]<=val) continue;
		ret += num2[i] - val;
	}
	return ret;
}
int main() {
	cin>>n>>m;
	for(int i = 0;i<n;i++) cin>>num1[i], all_num[++all_num[0]] = num1[i];
	for(int i = 0;i<m;i++) cin>>num2[i], all_num[++all_num[0]] = num2[i];
	sort(all_num+1, all_num+n+m+1);
	int l = 1, r = n+m;
	while(l+10<r) {
		int lmid = ((l<<1)+r)/3;
		int rmid = (l+(r<<1))/3;
		long long lcost = cal(all_num[lmid]);
		long long rcost = cal(all_num[rmid]);
		if(rcost > lcost) {
			r = rmid;
		} else {
			l = lmid;
		}
	}
	long long cost = 2e18+10;
	for(int i = l;i<=r;i++) {
		cost = min(cost, cal(all_num[i]));
	}
	cout<<cost<<endl;
	return 0;
}

