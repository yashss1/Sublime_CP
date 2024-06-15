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
	vector<int> v(n);
	int a = 0, b = 0, common = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		if (v[i] != i + 1 && v[i] != (n - i)) {
			common++;
			continue;
		}
		if (v[i] != i + 1) {
			a++;
		}
		if (v[i] != (n - i)) {
			b++;
		}
	}

	// cout << a << " " << b << " " << common << '\n';

	// first unlock khudke, fir common

	int chance = 0;
	int t = 2 * n;
	while (t--) {
		if (!chance) {
			if (a > 0) {
				a--;
			}
			else {
				if (common > 1) {
					common--;
				}
				else if ((common == 1 && b > 0) || common == 0) {
					cout << "First\n";
					return;
				}
			}
		}
		else {
			if (b > 0) {
				b--;
			}
			else {
				if (common > 1) {
					common--;
				}
				else if ((common == 1 && a > 0) || common == 0) {
					cout << "Second\n";
					return;
				}
			}
		}

		chance ^= 1;
	}

	cout << "Tie\n";
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