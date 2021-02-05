#include<bits/stdc++.h>
using namespace std;
const int len = 1000;
struct arr {
	private:
		int a[len];
	public:
		int& operator[](int i) {
			return a[i+(len>>1)];
		}
};
struct m {
	private:
		arr mat[len];
	public:
		arr& operator[](int i) {
			return mat[i+(len>>1)];
		}
} ans;
void init(int n) {
	bool needUpdate = true;
	ans[0][0] = n;
	while(needUpdate) {
		needUpdate = false;
		for(int i = -100;i<=100;i++) {
			for(int j = -100;j<=100;j++) {
				if(ans[i][j] >= 4) {
					needUpdate = true;
					int cnt = ans[i][j]/4;
					ans[i][j] -= cnt<<2;
					ans[i+1][j] += cnt;
					ans[i-1][j] += cnt;
					ans[i][j+1] += cnt;
					ans[i][j-1] += cnt;
				}
			}
		}
	}
}
int main() {
#ifdef DEBUG
    freopen("./317/B/in", "r", stdin);
#endif
	int n, m;
	cin>>n>>m;
	init(n);
	while(m--) {
		int a, b;
		cin>>a>>b;
		if(a<-100 || a > 100 || b<-100|| b>100) {
		    cout<<0<<endl;
		    continue;
		}
		cout<<ans[a][b]<<endl;
	}
	return 0;
}

