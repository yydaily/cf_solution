#include<bits/stdc++.h>

using namespace std;
int len, a, ind = 1;
const int maxm = 2e5 + 10;
int num[maxm];

int main() {
	cin>>len>>num[1];
	while(--len) {
		cin>>a;
		while(num[ind] == a) ind--, a++;
		num[++ind] = a;
	}
	cout<<ind<<endl;
	for(int i = 1;i<=ind;i++) cout<<num[i]<<' ';
    return 0;
}

