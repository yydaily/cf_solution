#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, a;
	double sum = 0;
	cin>>n;
	for(int i = 0;i<n;i++) {
		cin>>a;
		sum+=a;
	}
	cout<<setprecision(8)<<sum/n<<endl;
	return 0;
}
