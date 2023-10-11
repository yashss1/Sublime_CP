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

double dist(int x, int y, int a, int b) {
	double t = ((x - a) * (x - a)) + ((y - b) * (y - b));
	double dis = sqrt(t);
	return dis;
}

void yash()
{
	int n, m, x, y, a, b;
	cin >> n >> m >> x >> y >> a >> b;

	double temp1 = dist(x, y, 0, 0);
	double temp2 = dist(x, y, n, m);

	double temp3 = dist(a, b, 0, 0);
	double temp4 = dist(a, b, n, m);

	double ans1 = max({temp1, temp2});
	double ans2 = max({temp3, temp4});


	double btw = dist(a, b, x, y) / (float)2.0;


	double pdist = min({temp2, temp4});
	double odis = min({temp1, temp3});


	double ans3 = INT_MAX;
	if (btw >= pdist && btw >= odis) {
		ans3 = btw;
	}

	// cout << ans1 << " " << ans2 << " " << ans3 << '\n';
	double ans = min({ans1, ans2, ans3});

	double ans4 = max(dist(a, b, n, m), dist(x, y, 0, 0));
	double ans5 = max(dist(x, y, n, m), dist(a, b, 0, 0));

	if (ans4 >= btw) {
		ans = min({ans, ans4});
	}
	if (ans5 >= btw) {
		ans = min({ans, ans5});
	}


	cout << fixed << setprecision(9) << ans << '\n';
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