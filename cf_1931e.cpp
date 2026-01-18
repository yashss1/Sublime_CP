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
	int n, m, ans = 0;
	cin >> n >> m;
	vector<int> v(n), temp;
	for (int i = 0 ; i < n; i++ ) {
		cin >> v[i];
		string s = to_string(v[i]);
		int zero = 0;
		for (int j = s.size() - 1; j >= 0; j--) {
			if (s[j] == '0') {
				zero++;
			} else break;
		}

		if (zero != 0)
			temp.push_back(zero);
		ans += s.size();
	}

	// if len(numLast) > m sasha wins, else anna

	// pVec(temp);
	sort(temp.begin(), temp.end(), greater<int>());

	for (int i = 0; i < temp.size(); i++) {
		if (!(i % 2)) {
			ans -= (temp[i]);
		}
	}

	// cout << ans << " ";
	if (ans > m) {
		cout << "Sasha\n";
		return;
	}
	cout << "Anna\n";
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