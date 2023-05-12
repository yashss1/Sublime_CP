//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
int MOD = 1e9 + 7;
int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

map<int, int> mp;

void go(int x, int y) {
	if (y == 0) {
		return;
	}
	mp[x]++;
	go(x + 2, y - 1);
	go(x - 1, y - 1);
}

void yash()
{
	int n;
	cin >> n;

	if (n == 0) {
		cout << "1\n"; return;
	}
	// go(0, n);
	int ans = n;
	cout << (3 * ans) << '\n';
}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	test
	yash();
	return 0;
}