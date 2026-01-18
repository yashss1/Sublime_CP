//YashS
#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
const int MOD = 1e9 + 7;
int N = 1e5 + 7;

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


int ncr(int n, int r) {
	if (r < 0 || r > n) return 0;
	r = min(r, n - r);
	int res = 1;
	for (int i = 1; i <= r; ++i) {
		res = res * ((n - r + i) % MOD) % MOD;
		res = res * fpow(i, MOD - 2) % MOD;
	}
	return res;
}

vector<pair<int, int>> factorize(int x) {
	vector<pair<int, int>> factz;
	for (int d = 2; d * d <= x; ++d) {
		if (x % d == 0) {
			int cnt = 0;
			while (x % d == 0) {
				x /= d;
				++cnt;
			}
			factz.push_back({d, cnt});
		}
	}
	if (x > 1) factz.push_back({x, 1});
	return factz;
}

int ans = 0;
vector<pair<int, int>> pf;
vector<int> ex;
void dfs(
    int index,
    long long currentVal,
    unordered_map<int, int>& selected,
    long long lowerBound,
    long long upperBound,
    int numPrimes,
    int n
) {
	if (index == numPrimes) {
		if (currentVal <= lowerBound) {
			long long waysX = 1, waysY = 1;
			for (int i = 0; i < numPrimes; ++i) {
				int expX = selected.count(i) ? selected[i] : 0;
				int expY = ex[i] - expX;
				waysX = (waysX * ncr(expX + n - 1, n - 1)) % MOD;
				waysY = (waysY * ncr(expY + n - 1, n - 1)) % MOD;
			}
			ans = (ans + (waysX * waysY) % MOD) % MOD;
		}
		return;
	}

	int prime = pf[index].first;
	long long power = 1;

	for (int k = 0; k <= ex[index]; ++k) {
		if (k > 0) {
			if (power > LLONG_MAX / prime) break;
			power *= prime;
		}

		if (currentVal > LLONG_MAX / max(1LL, power)) break;
		long long newVal = currentVal * power;

		if (newVal > upperBound) break;

		if (k > 0)
			selected[index] = k;
		else
			selected.erase(index);

		dfs(index + 1, newVal, selected, lowerBound, upperBound, numPrimes, n);
	}
}


void yash(int TEST)
{
	int n, A, B;
	cin >> n >> A >> B;
	pf = factorize(B);
	int m = pf.size();
	ex.assign(m, 0);
	for (int i = 0; i < m; ++i) ex[i] = pf[i].second;
	ans = 0;
	unordered_map<int, int> chosen;
	dfs(0, 1, chosen, A, B, m, n);

	cout << "Case #" << TEST << ": " << ans % MOD << '\n';
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