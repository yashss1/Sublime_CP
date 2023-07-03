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

bool check(vector<int> v) {
	int n = v.size();
	for (int i = 1; i < n - 1; i++) {
		if ((v[i] > v[i + 1] && v[i] > v[i - 1]) || (v[i] < v[i + 1] && v[i] < v[i - 1])) {
		}
		else {
			return 0;
		}
	}

	if ((v[0] > v[n - 1] && v[0] > v[1]) || (v[0] < v[n - 1] && v[0] < v[1])) {}
	else return 0;
	if ((v[n - 1] > v[n - 2] && v[n - 1] > v[0]) || (v[n - 1] < v[n - 2] && v[n - 1] < v[0])) {}
	else return 0;

	return 1;
}

void yash()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	vector<int> ans(n, 0), ans2(n, 0);
	int k = 0;
	for (int i = 0; i < n; i += 2) {
		ans[i] = v[k];
		k++;
	}
	for (int i = 1; i < n; i += 2) {
		ans[i] = v[k];
		k++;
	}

	reverse(v.begin(), v.end());
	k = 0;
	for (int i = 0; i < n; i += 2) {
		ans2[i] = v[k];
		k++;
	}
	for (int i = 1; i < n; i += 2) {
		ans2[i] = v[k];
		k++;
	}

	if (check(ans)) {
		cout << "YES\n";
		pVec(ans);
		return;
	}
	if (check(ans2)) {
		cout << "YES\n";
		pVec(ans2);
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