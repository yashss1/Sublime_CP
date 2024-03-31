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
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	priority_queue<int> pq;
	int sum = 0, ans = 0;

	for (int i = m - 1; i >= 1; i--) {
		pq.push(v[i]);
		sum += v[i];
		while (sum > 0) {
			int top = pq.top();
			if (top < 0) {
				assert(false);
			}
			pq.pop();
			ans++;
			sum -= (2 * top);
		}
	}

	// cout << ans << ' ' << sum << '\n';

	int curr = sum;
	priority_queue<int, vector<int>, greater<int>> pq2;
	for (int i = m; i < n; i++) {
		curr += v[i];
		pq2.push(v[i]);
		while (curr < sum) {
			int top = pq2.top();
			if (top > 0) {
				assert(false);
			}
			pq2.pop();
			ans++;
			curr -= (2 * top);
			pq2.push(top * -1);
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