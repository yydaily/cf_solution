#include <bits/stdc++.h>
using namespace std;
int q,w,e; 
string a; 
int main() {
	cin >> q >> w >> e;
	cin >> a;
	if(a.size()<q*w||a.size()>q*e) cout << "No solution" << endl;
	else {
		int t=0; 	
		int k=a.size();
		while(k!=0) {
			int l=k/q; k-=l;
			while(l--) cout << a[t++]; q--; cout << endl;
		}
	}
}


