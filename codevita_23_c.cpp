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
	string s, c;
	cin >> s >> c;
	int l = 0;
	vector<int> a;

	for (char ch : s) {
		a.push_back(ch - '0');
	}

	int n = c.length();
	int i = 0;
	while (i < n) {
		if (c[i] == 'R') {
			l++;
		} else if (c[i] == 'L') {
			l--;
		} else if (c[i] == 'T') {
			a[l]++;
			a[l] = min(a[l], 9ll);
		} else if (c[i] == 'D') {
			a[l]--;
			a[l] = max(a[l], 0ll);
		} else if (c[i] == 'S') {
			swap(a[l], a[c[i + 1] - '0' - 1]);
		}
		i++;
	}

	string ans;
	for (int num : a) {
		ans += to_string(num);
	}

	cout << ans << endl;
}

signed main()
{
	// init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// test
	yash();
	return 0;
}