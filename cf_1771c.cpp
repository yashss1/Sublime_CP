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

int gcd(int a, int b)
{
	while (a > 0 && b > 0) {
		if (a > b) {
			a = a % b;
		}
		else {
			b = b % a;
		}
	}
	if (a == 0) {
		return b;
	}
	return a;
}

int prime[32006] = {0};
vector<int> primes;
void seive(int n)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (prime[i] == 0)
		{
			for (int j = i * i; j <= n; j += i)
			{
				prime[j] = 1;
			}
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (prime[i] == 0)
		{
			primes.push_back(i);
		}
	}
}

void yash()
{
	int n;
	cin >> n;
	vector<int> v(n);
	unordered_map<int, int> mp;
	unordered_map<int, int> freq;
	// pVec(primes);
	// cout << primes.size() << '\n';

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		freq[v[i]]++;
		for (int j = 0; v[i] / primes[j] >= primes[j] ; j++) {
			int num = v[i];
			while (num % primes[j] == 0) {
				num /= primes[j];
				if (num > 1) {
					mp[num]++;
				}
			}
		}
	}
	// cout << gcd(v[0], v[1]) << '\n';
	for (auto it : freq) {
		// cout << it.first << " " << it.second << '\n';
		if (it.second >= 2) {
			cout << "YES\n";
			return;
		}
	}
	for (auto it : mp) {
		// cout << it.first << " " << it.second << '\n';
		if (it.second >= 2) {
			cout << "YES\n";
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
	seive(32000);
	test
	yash();
	return 0;
}