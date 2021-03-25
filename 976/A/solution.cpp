#include<bits/stdc++.h>
using namespace std; 
int n;
string a;
int main() {
	cin>>n>>a;
	bool acc_1 = false;
	int cnt_0 = 0;
	for(int i = 0;i<n;i++) {
		if(a[i] == '0') cnt_0++;
		else acc_1 = true;
	}
	if(acc_1) cout<<1;
	while(cnt_0--) cout<<0;
	cout<<endl;
	return 0;
}
