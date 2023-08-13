//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define ll                long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
const int MOD = 1e9 + 7;
const int N = 6000;

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

ll fact[3000007] = {0};
void facto() {
	fact[0] = 1; fact[1] = 1; for (int i = 2; i < 300000; i++)fact[i] = (fact[i - 1] * i) % MOD;
}

ll ncr(ll n, ll r) {
	if (r > n)return 0;
	ll res = 1; res = fact[n]; res = (res * (fpow(fact[r], MOD - 2))) % MOD; res = (res * (fpow(fact[n - r], MOD - 2))) % MOD; return res;
}


vector<int> adj[N];
vector<vector<int>> v(N);

int dfs(int node, int par) {
	int curr = 1;
	for (auto it : adj[node]) {
		if (it != par) {
			int temp = dfs(it, node);
			v[node - 1].push_back(temp);
			curr += temp;
		}
	}

	return curr;
}

void yash()
{
	int n;
	cin >> n;
	v.resize(n);
	priority_queue<pair<int, int>> pq;

	for (int i = 2; i <= n; i++) {
		int a; cin >> a;
		adj[i].push_back(a);
		adj[a].push_back(i);
	}

	dfs(1, -1);

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int curr = 0;
		sort(v[i].begin(), v[i].end(), greater<int>());

		cout << i << " -> ";
		pVec(v[i]);

		for (int j = 1; j < v[i].size(); j++) {
			curr += v[i][0] * v[i][j];
		}

		cout << curr << "\n";
		ans += curr;
	}

	cout << ans << '\n';
}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	facto();
	// test
	yash();
	return 0;
}