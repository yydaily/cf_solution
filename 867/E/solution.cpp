#include<bits/stdc++.h>
using namespace std; 
long long n, num, ans=0;
priority_queue<int, vector<int>, greater<int>> q;
int main() {
	cin>>n;
	n--;
	cin>>num;
	q.push(num);
	while(n--) {
		cin>>num;
		if(q.top() < num) {
			ans += num - q.top();
			q.pop();
			q.push(num);
		}
		q.push(num);
	}
	cout<<ans<<endl;
	return 0;
}

