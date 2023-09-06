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

int n;
string a, b;

// int go(int idx, int taken, int flag) {
// 	if (idx == n) {
// 		return (taken == 2);
// 	}
// 	int c1 = 0, c2 = 0;


// 	if (a[idx] == taken) {
// 		if (taken == a[idx] - '0') {
// 			c1 = go(idx + 1, 2);
// 		}
// 		if (taken == 2) {
// 			c1 = go(idx + 1, a[idx] - '0');
// 		}
// 	}

// 	c2 = go(idx + 1, taken);

// 	return c1 | c2;
// }


void yash()
{
	cin >> a >> b;
	n = a.size();


	for (int i = 1; i < n; i++) {
		if (a[i - 1] == '0' && a[i] == '1') {
			if (b[i - 1] == '0' && b[i] == '1') {
				cout << "YES\n"; return;
			}
		}
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