#include<iostream>
using namespace std;
int n;
int num[10000];
int pre[100];
bool vis[100];
int find(int a) {
	if(pre[a] == a) return a;
	pre[a] = find(pre[a]);
	return pre[a];
}
void merge(int a, int b) {
	if(find(a) != find(b)) {
		pre[find(b)] = find(a);
	}
}
bool check() {
	for(int i = 0 ;i<100;i++) pre[i] = i, vis[i] = false;
	for(int i = 1;i<=n;i++) {/*{{{*/
		int last = -1;
		for(int j = 0;(1<<j) <= num[i];j++) {
			if(num[i]&(1<<j)) {
				vis[j] = true;
				if(last==-1) {
					last = j;
					continue;
				} else {
					merge(last, j);
				}
			}
		}
	}/*}}}*/
	int first = -1;
	for(int i = 0;i<100;i++) {
		if(vis[i]) {
			if(first == -1) {
				first = i;
				continue;
			} else {
				if(find(i) != find(first)) return false;
			}
		}
	}
	return true;
}
void solve() {
	int base_ans = 0;
	cin>>n;
	int x = 0;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
		if(num[i] == 0) {
			num[i] = 1;
			base_ans++;
		}
		x = max(x, num[i]&(-num[i]));
	}

	if(check()) {
		cout<<base_ans<<endl;
		for(int i = 1;i<=n;i++) cout<<num[i]<<' ';
		cout<<endl;
		return ;
	}

	for(int i = 1;i<=n;i++) {
		num[i]++;
		if(check()) {
			cout<<base_ans+1<<endl;
			for(int i = 1;i<=n;i++) cout<<num[i]<<' ';
			cout<<endl;
			return ;
		}
		num[i]--;
		if(num[i]<=1) continue;
		num[i]--;
		if(check()) {
			cout<<base_ans+1<<endl;
			for(int i = 1;i<=n;i++) cout<<num[i]<<' ';
			cout<<endl;
			return ;
		}
		num[i]++;
	}

	cout<<base_ans+2<<endl;
	for(int i = 1;i<=n;i++) if(num[i]&(-num[i]) == x) {
		num[i]--;
		break;
	}
	for(int i = 1;i<=n;i++) if(num[i]&(-num[i]) == x) {
		num[i]++;
		break;
	}
	for(int i = 1;i<=n;i++) {
		cout<<num[i]<<' ';
	}
	cout<<endl;
}
int main() {
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
