#include<bits/stdc++.h>
using namespace std;
int a, b;
bool check(int cnt) {
	int cnt6 = cnt/6;
	int cnt2 = cnt/2 - cnt6;
	int cnt3 = cnt/3 - cnt6;
	if(cnt2 <= a) {
		cnt6 -= a-cnt2;
	}
	if(cnt3 <= b) {
		cnt6 -= b-cnt3;
	}
	return cnt6 >= 0;
}
int main() {
	cin>>a>>b;
	int l = max(a<<1, b*3);
	int r = l<<1;
	while(l+100<r) {
		int mid = (l+r)>>1;
		if(check(mid)) r = mid; else l = mid;
	}
	for(int i = l;i<=r;i++) if(check(i)) {
		cout<<i<<endl;
		break;
	}
	return 0;
}

