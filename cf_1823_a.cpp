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

void yash()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int neg = i, pos = n - i;
		int a = neg * (neg - 1), b = pos * (pos - 1);
		if ((a / 2) + (b / 2) == k) {
			cout << "YES\n";
			for (int j = 0; j < n; j++) {
				if (j < i) {
					cout << "-1 ";
					continue;
				}
				cout << "1 ";
			}
			cout << "\n";
			return;
		}
	}
	cout << "NO\n";
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