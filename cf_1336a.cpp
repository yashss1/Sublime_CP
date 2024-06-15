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

int fpow(int x, int y, int p = MOD) {
	x = x % p; int sum = 1; while (y) {
		if (y & 1)sum = sum * x; sum %= p; y = y >> 1; x = x * x; x %= p;
	} return sum;
}
int fact[3000007] = {0};
void facto() {
	fact[0] = 1; fact[1] = 1; for (int i = 2; i < 300000; i++)fact[i] = (fact[i - 1] * i) % MOD;
}

int ncr(int n, int r) {
	if (r > n)return 0;
	int res = 1; res = fact[n]; res = (res * (fpow(fact[r], MOD - 2))) % MOD; res = (res * (fpow(fact[n - r], MOD - 2))) % MOD; return res;
}
int npr(int n, int r) {
	if (r > n)return 0;
	int res = 1; res = fact[n]; res = (res * (fpow(fact[n - r], MOD - 2))) % MOD; return res;
}

int isPrime(int n) {
	rep(i, 2, ceil(sqrt(n)) + 1) {
		if (n % i == 0)return 0;
	}
	return 1;
}

void solve() {
	// vector<int> fibo(1000);
	// fibo[0] = 1, fibo[1] = 2;
	// int ans = 2;
	// for (int i = 2; i <= 100; i++) {
	//     fibo[i] = fibo[i - 1] + fibo[i - 2];
	//     if (fibo[i] > 4e6) {
	//         break;
	//     }
	//     // cout << fibo[i] << '\n';

	//     if (fibo[i] % 2 == 0) {
	//         ans += fibo[i];
	//     }
	// }
	// cout << ans << '\n';

	// int ans = 0;
	// for (int i = 1; i <= 94500; i++) {
	//     string s = to_string(i);
	//     int flag = 1;
	//     for (int j = 0; j < s.size() / 2; j++) {
	//         if (s[j] != s[s.size() - j - 1]) {
	//             flag = 0;
	//         }
	//     }
	//     if (flag == 1 && isPrime(i)) {
	//         ans++;
	//     }
	// }
	// cout << ans << '\n';



}

int go1(int a, int b) {
	if (a > 0) {
		return (a % b + go1(a / b, b));
	}
	return 0;
}

int prime[1000006] = {0};
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

	// // Now Printing all the unmarked numbers
	// for (int i = 2; i <= n; i++)
	// {
	//     if (prime[i] == 0)
	//     {
	//         cout << i << " ";
	//     }
	// }
	// cout << endl;
}


vector<pair<int, int>> printPrimeFactors(int n)
{
	vector<pair<int, int>> primeFactors;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			int cnt = 0;
			while (n % i == 0) {
				cnt += 1;
				n /= i;
			}
			primeFactors.push_back({i, cnt});
		}
	}
	if (n >= 2)
		primeFactors.push_back({n, 1});
	return primeFactors;
}

int go(int idx, map<int, int> mp) {
	if (idx < 0) {
		return 0;
	}
	if (idx == 0) {
		return 1;
	}


	int ans = 0;
	for (int i = 1; i <= 10; i++) {
		if (mp[i] == 0) {
			map<int, int> mp1 = mp;
			mp1[i] = 1;
			ans += go(idx - i, mp1);
		}
	}
	return ans;
}

void yash()
{
	int n;
	cin >> n;

	int ans = go1(475, 10);
	cout << ans << '\n';
	// solve();
	// seive(1e6 + 2);

	// vector<int> primes;
	// primes.push_back(0);
	// for (int i = 1; i <= 1e6; i++) {
	//     if (prime[i] == 0) {
	//         primes.push_back(i);
	//     }
	// }

	// map<int, int> mp;
	// int ans = go(10, mp);
	// cout << ans << '\n';


	// int res = 0 ;
	// for (int i = 1000; i <= 9999; i++) {
	//     string s = to_string(i);
	//     reverse(all(s));
	//     int ans = i + stoi(s);

	//     if (ans == 9999) {
	//         res++;
	//     }
	// }
	// cout << res << '\n';


	// cout << primes.size() << '\n';
	// for (int i = 0; i <= 10; i++) {
	// cout << primes[i] << " ";
	// } cout << '\n';
	// n = primes.size();
	// for (int i = 1; i < primes.size(); i++) {
	//     primes[i] += primes[i - 1];
	// }

	// for (int i = 0; i <= 10; i++) {
	//     cout << primes[i] << " ";
	// } cout << '\n';

	// int mx = 0;
	// for (int i = 1; i < n; i++) {
	//     for (int j = i; j < n; j++) {
	//         int ans = primes[j] - primes[i - 1];
	//         if (ans > 1e6) continue;
	//         if (prime[ans] == 0) {
	//             mx = max(mx, ans);
	//         }
	//     }
	// }
	// cout << mx << "\n";
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