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

int isLarge(int n) {
	if (n  >= 5 && n <= 9) {
		return 1;
	}
	return 0;
}

void yash()
{
	string s;
	cin >> s;
	reverse(s.begin(), s.end());

	if (s[s.size() - 1] != '1') {
		cout << "NO\n";
		return;
	}

	int prev = 0;
	vector<int> a, b;
	for (int i = 0; i < s.size() - 1; i++) {
		int t = (s[i] - '0') - prev;
		t += 10;
		// cout << i << " " << t << '\n';
		if (t % 2 == 0) {
			if (!isLarge(t / 2)) {
				cout << "NO\n";
				return;
			}
			a.push_back(t / 2);
			b.push_back(t / 2);
		} else {
			t++;
			if (!isLarge((t / 2) - 1)) {
				cout << "NO\n";
				return;
			}
			if (!isLarge(t / 2)) {
				cout << "NO\n";
				return;
			}
			a.push_back((t / 2) - 1);
			b.push_back(t / 2);
		}
		prev = 1;
	}

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	pVec(a);
	pVec(b);
	cout << "YES\n";
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