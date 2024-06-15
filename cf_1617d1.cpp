//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout << '\n'
int MOD = 1e9 + 7;
int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int ask(int a, int b, int c) {
	cout << "? " << a << " " << b << " " << c << endl;
	int n;
	cin >> n;
	return n;
}

void answer(vector<int> v) {
	cout << "! " << v.size() << " ";
	pVec(v);
	cout << endl;
}

void yash()
{
	int n;
	cin >> n;

	int x = 0, y = 0;
	map<int, int> mp;
	int prev = ask(1, 2, 3);
	for (int i = 4; i <= n; i++) {
		int curr = ask(i, i - 1, i - 2);
		if (curr != prev) {
			x = i - 2, y = i - 1;
			break;
		}
		prev = curr;
	}

	// x and y are diff
	// cout << x << " " << y << '\n';

	vector<int> a, b;
	for (int i = 1; i <= n; i++) {
		if (i == x || i == y) continue;
		int curr = ask(x, y, i);
		if (curr == 0) {
			a.push_back(i);
		} else {
			b.push_back(i);
		}
	}

	if (a.size() >= 1 && b.size() >= 1) {
		int curr = ask(a[0], b[0], x);
		if (curr == 0) {
			a.push_back(x);
			b.push_back(y);
		} else {
			a.push_back(y);
			b.push_back(x);
		}
	}

	// pVec(a);
	// pVec(b);
	if (a.size() >= 3) {
		int curr = ask(a[0], a[1], a[2]);
		if (curr == 0) {
			answer(a);
		} else {
			answer(b);
		}
		return;
	} else {
		int curr = ask(b[0], b[1], b[2]);
		if (curr == 0) {
			answer(b);
		} else {
			answer(a);
		}
		return;
	}
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