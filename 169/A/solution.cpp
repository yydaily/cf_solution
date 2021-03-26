#include<bits/stdc++.h>
using namespace std;
int n, a, b;
int num[3000]; // <= b
int main() {
	cin>>n>>a>>b;
	for(int i = 0;i<n;i++) cin>>num[i];
	sort(num, num+n);
	cout<<num[b] - num[b-1]<<endl;
	return 0;
}
