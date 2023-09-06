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
	int n, k, l;
	cin >> n >> k >> l;
	vector<int> v(n);
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		pq.push(v[i]);
	}

	int i = 1, ans = 0;
	while (!pq.empty()) {
		int t = pq.top();
		pq.pop();
		if (i == l) {
			ans += t;
		}
		i++;
		if (i == k + 1) {
			i = 1;
		}
	}
	cout << ans << '\n';

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