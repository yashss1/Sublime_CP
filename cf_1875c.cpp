//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<"\n";cout<<"\n"
int MOD = 1e9 + 7;
int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

vector<int> pre;

int lcm(int a, int b) {
	return (a * b) / __gcd(a, b);
}

void solve(double n) {
	pre.clear();
	int t = 10;
	while (t--) {
		pre.push_back(n * (1e9));
		n /= (float)2;
	}
}

void yash()
{
	int n, m;
	cin >> n >> m;


	if (n % m == 0) {
		cout << "0\n";
		return;
	}

	int x = (n % m);
	double temp = x;

	set<int> st;
	st.insert(x);

	// double t = (x / (float)m);
	// x = (t * 1e9);

	// cout << x << " " << t << '\n';

	int t = lcm(x, m) / x;
	int poww = log2(t);
	if ((1 << (poww)) != t) {
		cout << "-1\n";
		return;
	}

	int ans = 0;
	int tt = 10;
	while (x > 0 && tt--) {
		int l = 0, r = pre.size() - 1;
		int curr = 0;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (pre[mid] <= x) {
				curr = mid;
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}

		double c = (pre[curr] / (float)(1e9));
		if ((int)(c * m) > temp) {
			// cout << "-1\n";
			break;
		}

		temp -= (c * m);
		x -= (pre[curr]);
		ans += ((pow(2, curr) - 1) * (c * m));
		ans = 0;
		// cout << pre[curr]  << " " << temp << '\n';
	}

	while (true) {
		ans += x;
		x *= 2;
		if (x > m) {
			if (st.find(x - m) == st.end()) {
				st.insert(x - m);
			}
			else {
				cout << "-1\n";
				return;
			}
			x -= m;
		}
		if (x == m) {
			break;
		}
	}

	cout << ans << '\n';
}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve(1.0);
	// pVec(pre);
	test
	yash();
	return 0;
}