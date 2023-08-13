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

// question -> naman WA chat -> 15-7-23
bool cmp(pair<int, int>&p1, pair<int, int>&p2) {
	if (p1.first != p2.first) return p1.first < p2.first;
	else {
		return p1.second < p2.second;
	}
}

void yash()
{
	int n, max_sum;
	cin >> n >> max_sum;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v[i] = {a, i};
	}
	sort(v.begin(), v.end(), cmp);

	int t = 0, i = 0;

	while (t) {
		t += v[i].first;


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