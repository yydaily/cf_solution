#include<bits/stdc++.h>
using namespace std;
const int maxm = 1e5 + 10;
int cnt[maxm];
int n;
double m;
int main() {
	cin>>n>>m;
	for(int i = 1, a, b;i<n;i++) {
		cin>>a>>b;
		cnt[a]++;
		cnt[b]++;
	}
	for(int i = 1;i<=n;i++) if(cnt[i] == 1) cnt[0]++;
	printf("%.10f\n", m/cnt[0]*2);
	return 0;
}

