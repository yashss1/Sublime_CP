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
	int mx = INT_MIN;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mx = max(mx, v[i]);
	}

	vector<int> temp;
	for (int i = 0; i < n; i++) {
		int t = mx - v[i];
		if (t > 0) {
			temp.push_back(t);
		}
	}
	sort(temp .begin(), temp.end(), greater<int>());

	// pVec(temp);

	int rem = 0;

	int ans = 0;
	for (int i = 0; i < temp.size();) {
		int sz = i + (m - 1);
		if (rem > 0) {
			if (temp[i] > rem) {
				temp[i] -= rem;
			}
			else {
				rem -= temp[i];
				i++;
				continue;
			}
		}
		rem = 0;

		ans += temp[i];
		// cout << temp[i] << " " << sz << " - ";
		if (sz >= temp.size()) {
			break;
		}

		vector<int> temp1;
		temp1.push_back(temp[i]);

		for (int j = i + 1; j < sz; j++) {
			temp1.push_back(temp[j]);
		}
		sort(temp1.begin(), temp1.end(), greater<int>());

		for (int j = 1; j < temp1.size(); j++) {
			rem += (temp1[0] - temp1[j]);
		}

		// cout << i << " " << rem << "|\n";
		i += m;
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