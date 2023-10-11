//YashS
//https://codeforces.com/gym/476638/problem/E
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

	int ans = 0;
	stack<pair<int, int>> st;

	vector<int> pref(n, -1);

	int used = n;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			st.push({v[i], i});
		}
		else {
			int curr = v[i];
			int curr_ans = 0;
			while (!st.empty()) {
				pair<int, int> top = st.top();
				st.pop();
				if (top.first >= curr) {
					curr_ans += curr;
					int rem = top.first - curr;
					curr = 0;
					if (rem > 0)
						st.push({rem, top.second});
					break;
				}
				curr_ans += top.first;
				curr -= top.first;
			}

			// cout << i << " -> " << curr_ans << '\n';
			if (st.size() != 0) {
				pair<int, int> top = st.top();
				if (top.second + 1 < used) {
					pref[top.second + 1] = 0;
					used = top.second + 1;
				}
			}
			if (st.size() == 0) {
				pref[i] = 0;
			}
			ans += curr_ans;
		}
	}

	// cout << ans << '\n';

	for (int i = 1; i < n; i += 2) {
		cout << i << " -> " << pref[i] << '\n';

		int curr = 0;
		for (int j = i - 2; j >= 0; j -= 2) {
			if (pref[j] != -1) {
				curr++;
			}
			else {
				break;
			}
		}
		ans += curr;
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