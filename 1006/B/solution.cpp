#include<bits/stdc++.h>
using namespace std;
const int array_len = 2345;
int n, k; 
pair<int,int> a[array_len];
pair<int,int> b[array_len];
int main() {
	cin>>n>>k;
	for(int i = 0;i<n;i++) cin>>a[i].first, a[i].second = i+1;
	sort(a, a+n);
	int sum = 0;
	for(int i = 1;i<=k;i++) sum += a[n-i].first;
	cout<<sum<<endl;
	for(int i = 1;i<=k;i++) {
		b[i].first = a[n-i].second;
		b[i].second = a[n-i].first;
	}
	sort(b+1, b+k+1);
	for(int i = 1;i<k;i++) cout<<b[i].first - b[i-1].first<<' ';
	cout<<n - b[k-1].first<<endl;
	return 0;
}

