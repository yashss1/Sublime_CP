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
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n), b(m);
	map<int, int> A, B;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		A[a[i]]++;
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		B[b[i]]++;
	}

	vector<int> v(k + 1, 0);
	int aa = 0, bb = 0;
	set<int> st;
	for (int i = 1; i <= k; i++) {
		st.insert(i);
	}

	for (int i = 1; i <= k; i++) {
		if (A[i] > 0 && B[i] > 0) {
			v[i] += 2;
			continue;
		}
		if (A[i] > 0) {
			aa++;
			st.erase(st.find(i));
			continue;
		}
		if (B[i] > 0) {
			bb++;
			st.erase(st.find(i));
		}
		else {
			cout << "NO\n";
			return;
		}
	}

	int remA = ((k / 2) - aa);
	int remB = ((k / 2) - bb);

	if (remA < 0 || remB < 0) {
		cout << "NO\n";
		return;
	}

	vector<int> temp;
	for (auto it : st) {
		temp.push_back(it);
	}

	// cout << remA << " " << remB << '\n';
	// pVec(temp);

	if (temp.size() == remA + remB) {
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
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