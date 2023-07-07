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

void yash()
{
	int n, b, h;
	cin >> n >> b >> h;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), greater<int>());

	double ans = 0;
	double basic = (b * h * 0.5);
	ans += basic;
	int prev = v[0];



	for (int i = 1; i < n; i++) {
		// calculate height till prev only
		if (v[i] + h <= prev) {
			ans += (basic);
			prev = v[i];
			continue;
		}

		double diff = prev - v[i];
		double bb = (diff * b) / (float)(h * 2);

		double rec_b = ((double)b - (double)(2 * (bb)));
		double rec_h = diff;

		double triArea = ((0.5) * bb * diff);

		double curr = (double)(rec_h * rec_b) + (double)(triArea * 2);

		// cout << i << " -> " << diff << " " << rec_h << " " << rec_b << " " << bb << "\n";
		// cout << triArea << " " << curr << '\n';

		ans += curr;

		prev = v[i];
	}

	cout << fixed << setprecision(9) << ans << '\n';
	// pVec(temp);
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