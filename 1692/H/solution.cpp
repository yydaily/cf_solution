#include<iostream>
#include<vector>
#include<map>
using namespace std;
int cal(vector<int> v, int &l, int &r) {
	if(v.size() == 1) {
		l = r = v[0];
		return 1;
	}
	int ll = -1;
	int last = -1;
	int now = 0;
	int ret = 0;
	for(auto i : v) {
		if(last == -1) {
			ll = i;
			last = i;
			now = 1;
			continue;
		}
		now = now + 1 - (i - last - 1);
		last = i;
		if(now <= 0) {
			ll = i;
			now = 1;
		}
		if(now > ret) {
			ret = now;
			l = ll;
			r = i;
		}
	}
	return ret;
}
void solve() {
	int len, a, l, r, end;
	cin>>len;
	map<int, vector<int> > m;
	for(int i = 1;i<=len;i++) {
		cin>>a;
		end = a;
		m[a].push_back(i);
	}
	if(m.size() == 1) {
		cout<<end<<' '<<1<<' '<<len<<endl;
		return ;
	}
	int max_len = -1;
	int ans = -1, ansl = -1, ansr = -1;
	for(auto i : m) {
		auto len = cal(i.second, l, r);
		if(len>max_len) {
			max_len = len;
			ans = i.first;
			ansl = l;
			ansr = r;
		}
	}
	cout<<ans<<' '<<ansl<<' '<<ansr<<endl;
}
int main() {
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
