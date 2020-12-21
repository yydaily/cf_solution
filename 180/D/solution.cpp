#include<bits/stdc++.h>
using namespace std;
string a, b, c;
bool check(int len) {/*{{{*/
	int cnt[26];
	for(int i = 0;i<26;i++) cnt[i] = 0;
	for(int i = 0;i<a.length();i++) cnt[a[i]-'a'] ++;
	for(int i = 0;i<len;i++) {
		if(cnt[b[i]-'a'] < 1) return false;
		cnt[b[i]-'a']--;
	}
	if(a.length() == len) return false;
	bool flag = false;
	for(int i = 0;i<26;i++) {
		if(cnt[i] != 0 && i+'a' > b[len]) {
			flag = true;
			break;
		}
	}
	return flag;
}/*}}}*/
void print(int len) {
	int cnt[26];
	for(int i = 0;i<26;i++) cnt[i] = 0;
	for(int i = 0;i<a.length();i++) cnt[a[i]-'a'] ++;
	for(int i = 0;i<len;i++) {
		cout<<b[i];
		cnt[b[i]-'a']--;
	}
	for(int i = 0;i<26;i++) {
		if(cnt[i] != 0 && i+'a' > b[len]) {
			cout<<char(i+'a');
			cnt[i]--;
			break;
		}
	}
	for(int i = 0;i<26;i++) {
		while(cnt[i]) {
			cnt[i]--;
			cout<<char(i+'a');
		}
	}
	cout<<endl;
}
void solve() {
	bool flag = true;
	for(int i = min(a.length(), b.length());i>=0;i--) if(check(i)) {
		flag = false;
		print(i);
		break;
	}
	if(flag) puts("-1");
}
int main() {
	cin>>a>>b;
	c = a;
	sort(c.begin(), c.end());
	reverse(c.begin(), c.end());
	if(c <= b) {cout<<-1<<endl; return 0;}
	solve();
	return 0;
}

