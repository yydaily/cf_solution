#include<bits/stdc++.h>
using namespace std;
int main() {
	int a;
	cin>>a;
	for(int i = 1;i<=a;i++) {
		for(int j = i;j<=a;j+=i) {
			if(j * i > a && j / i < a) {
				cout<<j<<' '<<i<<endl;
				return 0;
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}
