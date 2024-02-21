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
const int N = 5e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int fpow(int x, int y, int p = MOD) {
	x = x % p; int sum = 1; while (y) {
		if (y & 1)sum = sum * x; sum %= p; y = y >> 1; x = x * x; x %= p;
	} return sum;
}

int fact[N] = {0};
void facto() {
	fact[0] = 1; fact[1] = 1; for (int i = 2; i < N; i++)fact[i] = (fact[i - 1] * i) % MOD;
}

void yash()
{
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}


	// max pairs for n * n -> (n * (n - 1) / 2)
	// max strange for n * n -> [n * n] - [n * (n - 1) / 2] = (n * (n + 1) / 2)

	int k = (n * (n + 1) / 2);

	// for max strange each number will have only 1 pair

	// only these should be in diagonal
	int p = n;
	map<int, int> MP;
	for (int i = k; p > 0; p--, i--) {
		MP[i]++;
	}
	for (int i = 0; i < n; i++) {
		if (v[i][i] == 0) continue;
		if (MP[v[i][i]] == 0) {
			cout << "0\n"; return;
		}
	}


	multiset<int> st;
	for (int i = 1; i <= (n * n); i++) {
		int t = i;
		t %= k;
		st.insert(t);
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int a = v[i][j];
			int b = v[j][i];

			if (a == 0 && b == 0) {
				cnt++;
			}
			else if (a == 0) {
				b %= k;
				if (st.find(b) == st.end()) {
					cout << "0\n";
					return;
				}
				st.erase(st.find(b));
				if (st.find(b) == st.end()) {
					cout << "0\n";
					return;
				}
				st.erase(st.find(b));
			}
			else if (b == 0) {
				a %= k;
				if (st.find(a) == st.end()) {
					cout << "0\n";
					cout << a << "\n";
					return;
				}
				st.erase(st.find(a));
				if (st.find(a) == st.end()) {
					cout << "0\n";
					return;
				}
				st.erase(st.find(a));
			}
			else {
				cout << "0\n"; return;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int num = v[i][i];
		if (num == 0) continue;
		num %= k;
		if (st.find(num) == st.end()) {
			cout << "0\n";
			return;
		}
		st.erase(st.find(num));
	}

	vector<int> rem;
	map<int, int> mp;
	for (auto it : st) {
		rem.push_back(it);
		mp[it]++;
	}

	int pairs = 0;
	for (auto it : mp) {
		if (it.second >= 2) {
			pairs++;
			st.erase(st.find(it.first));
			st.erase(st.find(it.first));
		}
	}

	int c1 = (fact[pairs] % MOD) * (fpow(2ll, cnt) % MOD);
	int c2 = fact[st.size()];

	c1 %= MOD;
	c2 %= MOD;

	// cout << pairs << " -> " << c1 << " " << c2 << "\n";

	int ans = c1 * c2;
	ans %= MOD;

	// cout << pairs << " -> " << ans  << "\n";
	cout << ans << "\n";

}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	facto();
	test
	yash();
	return 0;
}