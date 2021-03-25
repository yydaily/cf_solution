#include<bits/stdc++.h>
using namespace std;
int n, ans = 0;
string a;
int main() {
	cin>>n>>a;
	for(int i = 0 ;i<n;i++) {
		if(a[i] == '-') ans--;
		else ans++;
		if(ans<0) ans = 0 ;
	}
	cout<<ans<<endl;
	return 0;
}
