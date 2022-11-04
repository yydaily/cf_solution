#include<bits/stdc++.h>
#include<vector>
using namespace std;
int n, u, r;
int a[30], b[30], k[30], p[30];
// 1. a[i]^=b[i]
// 2. a[i] = a[p[i]] + r
// maxm  \sum a[i] * k[i]
void input(int *buf, int len, int add = 0) {
	for(int i = 0;i<len;i++) {
		cin>>buf[i];
		buf[i] += add;
	}
}
struct c {
	int num[30];
	bool last_is_xor;

	c() {};
	c(int *_num, bool _last_is_xor) {
		for(int i = 0;i<n;i++) num[i] = _num[i];
		last_is_xor = _last_is_xor;
	}
};

long long get_value(int *a) {
	long long ans = 0;
	for(int i =0;i<n;i++) ans+=1LL * a[i] * k[i];
	return ans;
}

int buffer[30];

long long dfs(c now, bool adden, int op) {
	long long ret = -4e18;
	if(adden) ret = get_value(now.num);
	if(op <= 0) return ret;

	for(int i = 0;i<n;i++) buffer[i] = now.num[p[i]] + r;
	ret = max(ret, dfs(c(buffer, false), !adden, op-1));

	if(now.last_is_xor) return ret;

	for(int i = 0;i<n;i++) buffer[i] = now.num[i]^b[i];
	ret = max(ret, dfs(c(buffer, true), !adden, op-1));
	return ret;
}

int main() {
	cin>>n>>u>>r;
	input(a, n);
	input(b, n);
	input(k, n);
	input(p, n, -1);

	cout<<dfs(c(a, false), (u&1) == 0, u)<<endl;
	return 0;
}
