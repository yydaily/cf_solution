#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n, m, k;
	cin>>n>>m>>k;
	int start = 1;
	int big_table = n%m, big_count = n/m+1;
	int small_table = m - big_table, small_count = n/m;
	while(k--) {
		for(int i = 0;i<big_table;i++) {
			cout<<big_count<<' ';
			for(int j = 0;j<big_count;j++) {
				cout<<start++<<' ';
				if(start > n) start = 1;
			}
			cout<<endl;
		}
		int ano = start;
		for(int i = 0;i<small_table;i++) {
			cout<<small_count<<' ';
			for(int j = 0;j<small_count;j++) {
				cout<<ano++<<' ';
				if(ano > n) ano = 1;
			}
			cout<<endl;
		}
	}
}
int main() {
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}
