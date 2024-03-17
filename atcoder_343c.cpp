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
	int n;
	cin >> n;
	vector<int> v = {1,
	                 8,
	                 343,
	                 1331,
	                 1030301,
	                 1367631,
	                 1003003001,
	                 10662526601,
	                 1000300030001,
	                 1030607060301,
	                 1334996994331,
	                 1000030000300001,
	                 1033394994933301,
	                 1331399339931331
	                };

	// pVec(v);
	for (int i = v.size() - 1; i >= 0; i--) {
		if (v[i] <= n) {
			cout << v[i] << "\n";
			return;
		}
	}
}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// test
	yash();
	return 0;
}