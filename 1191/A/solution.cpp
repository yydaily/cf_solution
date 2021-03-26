#include <bits/stdc++.h>
using namespace std;

int n;
 
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	if (n % 4 == 1) cout << "0 A" << endl;
	if (n % 4 == 2) cout << "1 B" << endl; 
	if (n % 4 == 3)  cout << "2 A" << endl;
	if (n % 4 == 0) cout << "1 A" << endl;
	return 0;
}

