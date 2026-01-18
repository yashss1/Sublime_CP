//YashS
#include <bits/stdc++.h>
using namespace std;
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

void yash(int TEST)
{
	int n, a, b;
	cin >> n >> a >> b;

	cout << "Case #" << TEST << ": ";
	for (int i = 0; i < (2 * n) - 1; i++) {
		cout << "1 ";
	} cout << b << '\n';
}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		yash(i + 1);
	}
	return 0;
}