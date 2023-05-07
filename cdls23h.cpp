//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
int MOD = 1e9 + 7;
int N = 1e5 + 7;

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int32_t main() {
	init_code();
	int n;
	cin >> n;
	vector<int> A(n);
	for (int& x : A)
		cin >> x;

	int Q;
	cin >> Q;
	while (Q--) {
		int K;
		cin >> K;
		int ans = 0;
		F0R(i, n) F0R(j, n) if (i < j) {
			if (A[i] * A[j] < 0) {
				if (j % K == i % K) {
					cout << i + 1 << " " << j + 1 << "\n";
					++ans;
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
	return 0;
}