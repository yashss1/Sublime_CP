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
	vector<int> l(n), r(n), a(n), b(n);
	vector<pair<int, int>> temp;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i] >> a[i] >> b[i];
		temp.push_back({l[i], b[i]});
	}

	sort(temp.begin(), temp.end());
	vector < pair<int, int>> res;
	int R = temp[0].second, L = temp[0].first;
	for (int i = 1; i < n; i++) {
		if (temp[i].first <= R) {
			R = max(R, temp[i].second);
		}
		else {
			res.push_back({L, R});
			L = temp[i].first, R = temp[i].second;
		}
	}
	res.push_back({L, R});
	sort(res.begin(), res.end());

	// for (auto it : res) {
	// 	cout << it.first << " " << it.second << '\n';
	// }

	int q;
	cin >> q;
	vector<int> answer;
	while (q--) {
		int x;
		cin >> x;
		int i = 0, j = res.size() - 1;
		int ans = -1;
		while (i <= j) {
			int mid = (i + j) / 2;
			if (res[mid].first <= x) {
				ans = mid;
				i = mid + 1;
			}
			else {
				j = mid - 1;
			}
		}
		if (ans == -1) {
			answer.push_back(x);
			continue;
		}

		// cout << res[ans].first << "\n";
		int temp = max(x, res[ans].second);
		answer.push_back(temp);
	}

	pVec(answer);
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