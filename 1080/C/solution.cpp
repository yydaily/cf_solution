#include<bits/stdc++.h>
using namespace std;
int cal(int a, int b){
	return a / b + (a%b!=0);
}
int main() {
	int a, b;
	cin>>a>>b;
	cout<<cal(a<<1, b) + cal(a*5, b) + cal(a<<3, b)<<endl;
	return 0;
}

