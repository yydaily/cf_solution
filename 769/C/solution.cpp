#include<bits/stdc++.h>
using namespace std;
int n, m, k;
char mat[1005][1005];
int dis[1005][1005];
bool vis[1005][1005];
char ans[1000010];
queue<pair<int,int>> q;
//char ans[100];

bool canDown(int x, int y) { return x<n-1 && mat[x+1][y] == '.'; } 
bool canLeft(int x, int y) { return y > 0 && mat[x][y-1] == '.'; } 
bool canRight(int x,int y) { return y<m-1 && mat[x][y+1] == '.'; }
bool canUp(  int x, int y) { return x > 0 && mat[x-1][y] == '.'; }

void spread(int x, int y, int distance = 0) {
	dis[x][y] = distance;
	q.push(make_pair(x,y));
	while(!q.empty()) {
		auto now = q.front(); q.pop();
		int x = now.first, y = now.second;
		vis[x][y] = true;
		if(canDown( x,y) && dis[x+1][y] > dis[x][y] + 1 && !vis[x+1][y]) {q.push(make_pair(x+1, y)); dis[x+1][y] = dis[x][y]+1;}
		if(canLeft( x,y) && dis[x][y-1] > dis[x][y] + 1 && !vis[x][y-1]) {q.push(make_pair(x, y-1)); dis[x][y-1] = dis[x][y]+1;}
		if(canRight(x,y) && dis[x][y+1] > dis[x][y] + 1 && !vis[x][y+1]) {q.push(make_pair(x, y+1)); dis[x][y+1] = dis[x][y]+1;}
		if(canUp(   x,y) && dis[x-1][y] > dis[x][y] + 1 && !vis[x-1][y]) {q.push(make_pair(x-1, y)); dis[x-1][y] = dis[x][y]+1;}
	}
}

bool solve(int x, int y) {
	spread(x, y);
	mat[x][y] = '.';
	if(k&1) return false;
	for(int i = 1;i<=k;i++) {
		if(canDown(x, y) && dis[x+1][y] <= k-i) {x++; cout<<'D'; continue;}
		if(canLeft(x, y) && dis[x][y-1] <= k-i) {y--; cout<<'L'; continue;}
		if(canRight(x,y) && dis[x][y+1] <= k-i) {y++; cout<<'R'; continue;}
		if(canUp(   x,y) && dis[x-1][y] <= k-i) {x--; cout<<'U'; continue;}
		return false;
	}
	cout<<endl;
	return true;
}

int main() {
	cin>>n>>m>>k;
	for(int i = 0;i<n;i++) cin>>mat[i];
	for(int i = 0;i<n;i++) for(int j = 0;j<m;j++) dis[i][j] = 5000;
	for(int i = 0;i<n;i++) for(int j = 0;j<m;j++) if(mat[i][j] == 'X'&&solve(i, j)) return 0;
	puts("IMPOSSIBLE");
	return 0;
}

