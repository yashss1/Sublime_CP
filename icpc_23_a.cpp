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
	string s;
	cin >> s;

	int pointer = 0;
	int dir = 0;
	for (int i = 0; i < k; i++) {
		if (s[i] == 'U') {
			if (dir == 0) {
				pointer++;
				pointer %= n;
			}
			else {
				pointer--;
				if (pointer == -1) {
					pointer = n - 1;
				}
			}
		}
		if (s[i] == 'S') {
			if (dir == 0) {
				pointer += 2;
				pointer %= n;
			}
			else {
				pointer -= 2;
				if (pointer == -1) {
					pointer = n - 1;
				}
				if (pointer == -2) {
					pointer = n - 2;
				}
			}
		}
		if (s[i] == 'R') {
			dir ^= 1;
			if (dir == 0) {
				pointer++;
				pointer %= n;
			}
			else {
				pointer--;
				if (pointer == -1) {
					pointer = n - 1;
				}
			}
		}
	}

	cout << pointer + 1 << '\n';

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