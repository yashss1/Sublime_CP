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
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	vector<int> hsh(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		hsh[i] = hsh[i - 1] + v[i];
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int sum = 0, k = v[1] + 1;
	for (int i = 2; i <= n; i++) {
		if (i <= k) {
			// cout << v[i] << ' ' << i << '\n';
			sum += v[i];
			pq.push({v[i], i});
			continue;
		}
		if (pq.size() == 0) {
			break;
		}
		pair<int, int> temp = pq.top();
		pq.pop();

		if (hsh[min(i + v[i], n)] - hsh[i - 1] >= temp.first) {
			k += temp.first;
			sum -= temp.first;
			sum += v[i];
			pq.push({v[i], i});
			// i--;
		}
		else {
			break;
		}
	}
	cout << max(v[0], sum) << '\n';
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