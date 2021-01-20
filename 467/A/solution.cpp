#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, ans = 0;
	cin>>n;
	for(int i = 0, a, b;i<n;i++) {
		cin>>a>>b;
		if(b - a>=2) ans++;
	}
	cout<<ans<<endl;
	return 0;
}

