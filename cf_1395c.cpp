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

string toBinary(int n)
{
	return bitset<10> (n).to_string();
}


void yash()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int j = 0; j < m; j++) {
		cin >> b[j];
	}

	for (int i = 0; i < pow(2ll, 9ll); i++) {
		map<int, int> unset;
		for (int j = 0; j < 9; j++) {
			if (!(j & (1 << i))) {
				unset[j] = 1;
			}
		}

		map<vector<int>, int> mp;
		int flagg = 1;
		for (int j = 0; j < n; j++) {
			int flag = 0;
			for (int k = 0; k < m; k++) {
				if (((a[j] & b[k]) | i) == i) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				flagg = 0;
				break;
			}
		}
		if (flagg) {
			cout << i << '\n'; return;
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