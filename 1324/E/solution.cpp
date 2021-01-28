#include<bits/stdc++.h>
using namespace std;
const int maxm = 1e4;
int a, b, c, d, e;
int ans[2][maxm];
void cal(int e, bool init = false) {
	if(!init) {
		for(int i = 0;i<b;i++) {
			ans[0][i] = ans[1][i];
			ans[1][i] = -100000000;
		}
	}
	for(int i = 0;i<b;i++) { // i means last
		int nxt = (i+e)%b;
		ans[1][nxt] = max(ans[1][nxt],
				ans[0][i] + (c <= nxt && nxt <= d));
		nxt = (i+e-1)%b;
		ans[1][nxt] = max(ans[1][nxt],
				ans[0][i] + (c <= nxt && nxt <= d));
	}
}
int main() {
	cin>>a>>b>>c>>d;
	int ret = 0;
	for(int i = 0;i<b;i++) ans[0][i] = ans[1][i] = -1000000000;
	ans[0][0] = 0;
	for(int i = 0;i<a;i++) {
		cin>>e; 
		cal(e, i==0);
	}
	for(int i = 0;i<b;i++) ret = max(ret, max(ans[1][i], ans[0][i]));
	cout<<ret<<endl;
	return 0;
}

