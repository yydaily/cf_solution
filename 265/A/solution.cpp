#include<bits/stdc++.h>
using namespace std;
string a, b;
int main() {
	cin>>a>>b;
	int ind = 0;
	for(int i = 0;i<b.length();i++) {
		if(b[i] == a[ind]) ind++;
	}
	cout<<ind+1<<endl;
	return 0;
}

