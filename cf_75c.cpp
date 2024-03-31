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

map<int, int> mp;
vector<int> printDivisors(int n)
{
	vector<int> divisors;
	for (int i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			if (n / i == i) {
				divisors.pb(i);
				mp[i]++;
			}

			else {
				divisors.pb(i);
				mp[i]++;
				divisors.pb(n / i);
				mp[(n / i)]++;
			}
		}
	}
	return divisors;
}

void yash()
{
	int a, b, n;
	cin >> a >> b >> n;
	vector<int> divisorsA = printDivisors(a);
	vector<int> divisorsB = printDivisors(b);

	vector<int> common;
	for (auto it : mp) {
		if (it.second == 2) {
			common.push_back(it.first);
		}
	}
	sort(common.begin(), common.end());

	// pVec(common);


	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;

		int flag = 0;
		for (int j = common.size() - 1; j >= 0; j--) {
			if (common[j] >= l && common[j] <= r) {
				cout << common[j] << "\n";
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			cout << "-1\n";
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