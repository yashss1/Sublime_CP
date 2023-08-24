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
	int a, b, c;
	cin >> a >> b >> c;
	int f = 0;
	if (c % 2 == 0) {
		f = 0;
	}
	else {
		f = 1;
	}

	if (a > b) {
		cout << "First\n"; return;
	}
	if (a < b) {
		cout << "Second\n"; return;
	}

	if (f == 1) {
		cout << "First\n"; return;
	}
	cout << "Second\n";
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