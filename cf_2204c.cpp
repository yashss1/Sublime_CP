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

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

void yash()
{
	int a, b, c, m;
	cin >> a >> b >> c >> m;

	int AB = m / (lcm(a, b));
	int AC = m / (lcm(a, c));
	int BC = m / (lcm(b, c));
	int ABC = m / (lcm((lcm(a, b)), c));

	int aOnly = (m / a) - AB - AC + ABC;
	int bOnly = (m / b) - AB - BC + ABC;
	int cOnly = (m / c) - AC - BC + ABC;

	int onlyAB = AB - ABC;
	int onlyAC = AC - ABC;
	int onlyBC = BC - ABC;

	vector<int> ans;

	ans.push_back((aOnly * 6) + onlyAB * 3 + onlyAC * 3 + ABC * 2);
	ans.push_back((bOnly * 6) + onlyAB * 3 + onlyBC * 3 + ABC * 2);
	ans.push_back((cOnly * 6) + onlyAC * 3 + onlyBC * 3 + ABC * 2);


	for (auto it : ans) {
		cout << it << ' ';
	} cout << '\n';

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