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
	string a, b;
	cin >> a >> b;

	int lasB = -1, firA = n;
	stack<int> st;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) {
			if (a[i] == 'B') {
				lasB = i;
			}
			else if (firA == n) {
				firA = i;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) continue;
		if (a[i] == 'A') {
			if (st.size() > 0) {
				ans++;
				if (firA == n) {
					firA = st.top();
				}
				if (lasB < i) {
					lasB = i;
				}
				st.pop();
				continue;
			}
			if (firA < i) {
				ans++;
			}
			else {
				cout << "-1\n"; return;
			}
		}
		else {
			st.push(i);
		}
	}

	vector<int> temp;
	while (!st.empty()) {
		int t = st.top();
		st.pop();
		if (lasB > t) {
			ans++;
		}
		else {
			cout << "-1\n";
			return;
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
	// test
	yash();
	return 0;
}