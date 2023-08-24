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

int n, m, d;
int solve(int n) {
	if (n < 0) return 0;
	return (n / d);
}

int ans(vector<int> &v) {
	int res = m;
	if (v[0] != 1) res++;

	int prev = 1;
	for (int i = 0; i < m; i++) {
		if (v[i] == 1) continue;
		int t = (v[i] - prev - 1);
		res += (t / d);
		prev = v[i];
	}
	if (v[m - 1] != n) {
		int t = (n - v[m - 1]);
		res += (t / d);
	}
	return res;
}

void yash()
{
	cin >> n >> m >> d;
	vector<int> v(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());


	vector<int> dis;
	for (int i = 1; i < m; i++) {
		dis.push_back(v[i] - v[i - 1] - 1);
	}

	int res1 = ans(v);
	// cout << res1 << " ans\n";

	vector<int> temp;
	int res = res1;

	// remove first
	{
		// int t = v[0] - 1 - 1;
		// if (t >= 0) {
		int space = v[1] - 1 - 1;
		int benefit = solve(space) - solve(v[0] - 2) - solve(v[1] - v[0] - 1);
		if (v[0] != 1) {
			benefit--;
		}
		// cout << benefit << '\n';
		temp.push_back(res1 + benefit);
		res = min(res, res1 + benefit);
		// }

	}
	// remove last
	{
		// int t = n - v[m - 1] - 1;
		// if (t >= 0) {
		int space = n - v[m - 2];
		int benefit = solve(space) - solve(dis[dis.size() - 1]) - solve(n - v[m - 1] - 1) - 1;
		// cout << benefit << " last\n";
		temp.push_back(res1 + benefit);
		res = min(res, res1 + benefit);
		// }
	}

	// pVec(dis);
	for (int i = 1; i < dis.size(); i++) {
		int t = dis[i - 1] + dis[i] + 1;
		int benefit = solve(t) - solve(dis[i - 1]) - solve(dis[i]) - 1;
		temp.push_back(res1 + benefit);
		res = min(res, res1 + benefit);
	}

	int yash = 0;
	// if (temp[0] == res && v[0] == 1) yash--;
	for (auto it : temp) {
		if (it == res) yash++;
	}
	cout << res << " " << yash << "\n";
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