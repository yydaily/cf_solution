#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	int base = 1;
	while(n) {
		if(n==3) {
			cout<<base<<' '<<base<<' '<<base*3;
			break;
		}
		int cnt = n/2 + (n&1);
		for(int i = 0;i<cnt;i++) cout<<base<<' ';
		n -= cnt;
		base <<= 1;
	}
	return 0;
}

