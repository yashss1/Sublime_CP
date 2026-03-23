//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<endl;
const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int query(int i, int j) {
	cout << "? " << i << " " << j << endl;
	int n;
	cin >> n;
	return n;
}

void ansP(int n) {
	cout << "! ";
	cout << n << endl;
}

void yash()
{
	int n;
	cin >> n;

	int flag = 0;
	vector<int> res;
	for (int i = 2 * n; i > 2; i -= 2) {
		int ans = query(i, i - 1);
		res.push_back(ans);
		if (ans == 1) {
			ansP(i);
			flag = 1;
			break;
		}
	}

	if (flag == 0) {
		if (query(1, 3) == 1) {
			ansP(1);
		} else {
			if (query(1, 4) == 1) {
				ansP(1);
			} else {
				ansP(2);
			}
		}
	}
}

signed main()
{
	// init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	test
	yash();
	return 0;
}