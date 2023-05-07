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
int N = 1e7 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int prime[10000000 + 1] = {0};
void seive()
{
	prime[1] = -1;
	for (int i = 2; i <= N; i++)
	{
		if (prime[i] == 0)
		{
			for (int j = i * i; j <= N; j += i)
			{
				prime[j] = 1;
			}
		}
	}

	// // Now Printing all the unmarked numbers
	// for (int i = 2; i <= N; i++)
	// {
	// 	if (prime[i] == 0)
	// 	{
	// 		cout << i << " ";
	// 	}
	// }
	// cout << endl;
}

pair<int, int> printDivisors(int n)
{
	vector<int> divisors;
	int a = 0;
	for (int i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			if (n / i == i) {
				if (prime[i] == 0) {
					a++;
				}
				divisors.pb(i);
			}

			else {
				if (prime[i] == 0) {
					a++;
				}
				divisors.pb(i);
				if (prime[(n / i)] == 0) {
					a++;
				}
				divisors.pb(n / i);
			}
		}
	}
	sort(all(divisors));
	// pVec(divisors);
	return {a, divisors.size() - a - 1};
}

void yash()
{
	int n;
	cin >> n;
	vector<int> v(n);
	int p = 0, q = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		pair<int, int> temp = printDivisors(v[i]);
		cout << temp.first << " " << temp.second << '\n';
		if (temp.first <= temp.second) {
			ans++;
			continue;
		}

		p += temp.first;
		q += temp.second;
	}

	if (p == 0) {
		cout << ans << '\n';
		return;
	}
	cout << p << " " << q << '\n';
}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	seive();
	test
	yash();
	return 0;
}

#define MAXN 10000001

ll spf[MAXN];
void sieve()
{
	spf[1] = 1;
	for (int i = 2; i < MAXN; i++)
		spf[i] = i;
	for (int i = 4; i < MAXN; i += 2)
		spf[i] = 2;

	for (int i = 3; i * i < MAXN; i++)
	{
		if (spf[i] == i)
		{
			for (int j = i * i; j < MAXN; j += i)
				if (spf[j] == j)
					spf[j] = i;
		}
	}
}

vector<int> getFactorization(int x)
{
	vector<int> ret;
	while (x != 1)
	{
		ret.push_back(spf[x]);
		x = x / spf[x];
	}
	return ret;
}

void PerformOp() {

	ll n;
	cin >> n;

	vll v(n);
	for (auto &i : v)
		cin >> i;

	ll cnt = 0;
	map<ll, ll> mp;
	for (auto &i : v) {
		auto x = getFactorization(i);
		cnt += x.size();
		for (auto &j : x) {
			mp[j]++;
		}
	}

	ll twos = 0;
	for (auto &i : mp) {
		ll sz = i.ss;
		twos += sz / 2;
	}
	cnt -= twos * 2;
	auto check = [&](ll x)->bool{
		ll req = x - twos;
		ll have = cnt / 3;
		if (have >= req) {
			return 1;
		}
		return 0;
	};

	ll l = 1, r = 1e9;
	ll res = 0;
	while (l <= r) {
		ll mid = l + (r - l) / 2;
		if (check(mid)) {
			res = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	cout << res;

}
