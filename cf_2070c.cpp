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
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R') s[i] = '0';
		else s[i] = '1';
	}
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	cout << s << '\n';

	int l = 0, r = 10, ans = INT_MAX;
	while (l <= r) {
		int mid = (l + r) / 2;
		mid = 0;

		vector<int> fixChange(n);
		for (int i = 0; i < n; i++) {
			fixChange[i] = (v[i] > mid) ? 1 : 0;

			if (fixChange[i] == 1 && s[i] == '1') {
				fixChange[i] = 1; // do
			} else if (fixChange[i] == 1 && s[i] == '0') {
				fixChange[i] = 0; // dont
			} else {
				fixChange[i] = 2; // can or cannot
			}
		}

		cout << mid << " -> ";
		pVec(fixChange);

		int partitions = 0, curr = fixChange[0];
		for (int i = 0; i < n; i++) {
			if (fixChange[i] == curr || fixChange[i] == 2) {

			} else {
				curr = fixChange[i];
				partitions++;
			}
		}
		cout << partitions << '\n';
		cout << "\n";


		if (partitions <= k) {
			r = mid - 1;
			ans = mid;
		} else {
			l = mid + 1;
		}

		break;
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