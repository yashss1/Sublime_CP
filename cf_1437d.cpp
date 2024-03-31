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
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	if (n == 2) {
		cout << "1\n";
		return;
	}


	queue<pair<int, int>> q;
	q.push({1, 0});
	vector<int> temp;
	int ans = 0;
	for (int i = 1; i < n - 1; i++) {
		if (v[i] <= v[i + 1]) {
			temp.push_back(v[i]);
		}
		else {
			temp.push_back(v[i]);
			// pVec(temp);
			pair<int, int> front = q.front();
			q.pop();
			for (auto it : temp) {
				q.push({it, front.second + 1});
				ans = max(ans, front.second + 1);
			}
			temp.clear();
		}
	}
	temp.push_back(v[n - 1]);
	pair<int, int> front = q.front();
	q.pop();
	for (auto it : temp) {
		q.push({it, front.second + 1});
		ans = max(ans, front.second + 1);
	}
	// pVec(temp);
	// cout << "-1\n";

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