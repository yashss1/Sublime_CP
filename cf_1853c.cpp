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
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	if (v[0] != 1) {
		cout << "1\n";
		return;
	}

	set<int> st1;
	for (int i = 1; i < 400; i++) {
		st1.insert(i);
	}


	int prev = 0, idx = 0, num = 0;
	for (int K = 1; K <= 10; K++) {
		set<int> st = st1;

		for (int i = 0; i < K; i++) {
			vector<int> temp;
			for (auto it : st) {
				temp.push_back(it);
			}
			st.clear();

			int kk = 0;
			for (int j = 0; j < temp.size(); j++) {
				if (kk < n && j + 1 == v[kk]) {
					kk++;
				}
				else {
					st.insert(temp[j]);
				}
			}
		}
		int t = (*st.begin());
		// cout << t << "\n";
		if (k == K) {
			cout << t << "\n";
			return;
		}
		if (prev + n == t) {
			num = prev;
			break;
		}
		prev = t;
		idx++;
	}

	// cout << idx << " " << num << "\n";
	int rem = k - idx;
	int ans = (rem * n) + num;
	// pVec(st);
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