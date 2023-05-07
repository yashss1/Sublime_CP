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

string query(int x, int y) {
	cout << "1 " << x << " " << y << endl;
	string s;
	cin >> s;
	return s;
}

void ans(int n) {
	cout << "2 " << n << endl;
}

void yash()
{
	int n;
	cin >> n;
	pair<int, int> curr_big_at;
	curr_big_at.first = 1, curr_big_at.second = 1;
	for (int i = 2; i <= n; i++) {
		string s = query(curr_big_at.first, i);

		if (s == "First") {
			curr_big_at.first = i;
		}
		else {
			curr_big_at.second = i;
		}
	}

	ans(curr_big_at.second);
}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// 	test
	yash();
	return 0;
}