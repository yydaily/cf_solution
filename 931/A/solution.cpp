#include<bits/stdc++.h>
using namespace std;
int add(int a) {
	int ret = 0;
	for(int i = 1;i<=a;i++) ret += i;
	return ret;
}
int main() {
	int a, b;
	cin>>a>>b;
	a -= b;
	if(a<0) a = -a;
	b = a/2;
	cout<<add(b)+ add(a-b)<<endl;
	return 0;
}

