//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               int64_t
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
constexpr uint64_t MOD = (1ULL << 61) - 1;
const int N = 1e6 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}


// constexpr uint64_t MOD = (1ULL << 61) - 1;
const uint64_t seed = chrono::system_clock::now().time_since_epoch().count();
const uint64_t base = mt19937_64(seed)() % (MOD / 3) + (MOD / 3);

uint64_t base_pow[N];
int64_t modmul(uint64_t a, uint64_t b)
{
	uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
	uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
	uint64_t ret = (l & MOD) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
	ret = (ret & MOD) + (ret >> 61);
	ret = (ret & MOD) + (ret >> 61);
	return ret - 1;
}

void init() {
	base_pow[0] = 1;
	for (int i = 1; i < N; i++)
	{
		base_pow[i] = modmul(base_pow[i - 1], base);
	}
}

struct PolyHash
{
	/// Remove suff vector and usage if reverse hash is not required for more speed
	vector<int64_t> pref, suff;
	PolyHash() {}

	template <typename T>
	PolyHash(const vector<T> &ar)
	{
		if (!base_pow[0])
			init();

		int n = ar.size();
		assert(n < N);
		pref.resize(n + 3, 0), suff.resize(n + 3, 0);

		for (int i = 1; i <= n; i++)
		{
			pref[i] = modmul(pref[i - 1], base) + ar[i - 1] + 997;
			if (pref[i] >= MOD)
				pref[i] -= MOD;
		}

		for (int i = n; i >= 1; i--)
		{
			suff[i] = modmul(suff[i + 1], base) + ar[i - 1] + 997;
			if (suff[i] >= MOD)
				suff[i] -= MOD;
		}
	}

	PolyHash(string str)
		: PolyHash(vector<char>(str.begin(), str.begin() + (int)str.size())) {}

	uint64_t get_hash(int l, int r)
	{
		int64_t h = pref[r + 1] - modmul(base_pow[r - l + 1], pref[l]);
		return h < 0 ? h + MOD : h;
	}

	uint64_t rev_hash(int l, int r)
	{
		int64_t h = suff[l + 1] - modmul(base_pow[r - l + 1], suff[r + 2]);
		return h < 0 ? h + MOD : h;
	}
};

string s;
int n;
PolyHash H;

bool solve(int k, int prefix) {

	rep(i, 1, s.size() - k) {
		int hsh1 = H.get_hash(i, i + k - 1);
		if (hsh1 == prefix) {
			return true;
		}
	}

	return false;
}

vector<pair<int, int>> temp;
int go(int idx, int rem) {
	if (idx == n) {
		return 0;
	}
	if (rem < 0) {
		return -1e18;
	}

	int c1 = temp[idx].first + go(idx + 1, rem - temp[idx].second);
	int c2 = go(idx + 1, rem);

	return max({c1, c2});
}

void yash()
{
	int k;
	cin >> n >> k;
	cin >> s;
	n = s.size();
	H = PolyHash(s);

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans = 0;

	// cout << H.get_hash(0, 5) << " " << H.get_hash(12, 17) << "\n";
	// cout << solve(6) << "\n";

	vector<int> v;
	rep(i, 1, n) {
		int prefix = H.get_hash(0, i - 1);
		int suffix = H.get_hash(n - i, n - 1);
		if (prefix != suffix) {
			continue;
		}
		v.push_back({i});
	}

	if (v.size() == 0) {
		cout << ans << "\n"; return;
	}

	// int l = 0, r = v.size() - 1;
	// while (l <= r) {
	// 	int mid = (l + r) / 2;
	// 	int prefix = H.get_hash(0, v[mid] - 1);
	// 	if (solve(v[mid], prefix)) {
	// 		ans = s.substr(0, v[mid]);
	// 		l = mid + 1;
	// 	} else {
	// 		r = mid - 1;
	// 	}
	// }

	temp.clear();
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > k) {
			break;
		}

		int prefix = H.get_hash(0, v[i] - 1);
		if (solve(v[i], prefix)) {
			temp.push_back({v[i], a[v[i] - 1]});
		}
	}

	// pVec(temp);
	// cout << ans << "\n";

	n = temp.size();
	ans = go(0, k);

	cout << ans << '\n';
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