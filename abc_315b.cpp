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
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}

	int t = (sum + 1) / 2;
	int curr = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] + curr >= t) {
			cout << i + 1 << " " << (t - curr) << '\n';
			return;
		}
		else {
			curr += v[i];
		}
	}


	// cout << sum << '\n';
	t = (sum / 2) + 1;
	curr = 0;
	int idx = 0;
	for (int i = 0; i < n; i++) {
		if (curr + v[i] < t) {
			curr += v[i];
			idx = i;
		}
		else {
			break;
		}
	}
	// cout << curr << '\n';
	int rem = t - curr;
	// cout << rem << '\n';
	if (curr != 0) {
		idx++;
	}
	cout << idx + 1 << " " << rem << '\n';

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