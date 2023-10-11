//YashS
//https://codeforces.com/gym/476638/problem/C

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

	vector<vector<int>> arr = {{v[0]}};
	vector<int> temp = {v[1]};

	for (int i = 2; i < n; i++) {
		if (v[i - 1] < v[i]) {
			temp.push_back(v[i]);
		}
		else {
			arr.push_back(temp);
			temp.clear();
			temp.push_back(v[i]);
		}
	}
	if (temp.size() > 0) arr.push_back(temp);

	for (auto &it : arr) {
		// pVec(it);
		sort(it.begin(), it.end(), greater<int>());
	}

	int ans = 1;

	queue<pair<int, int>> pq;
	for (auto it : arr[1]) {
		pq.push({it, 1});
	}

	for (int i = 2; i < arr.size(); i++) {
		pair<int, int> t = pq.front();
		pq.pop();
		for (auto it : arr[i]) {
			pq.push({it, t.second + 1});
			ans = max(ans, t.second + 1);
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