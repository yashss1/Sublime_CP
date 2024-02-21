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
	int n;
	cin >> n;

	vector<vector<int>> v(n, vector<int>(n, 0));
	int ones = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == '0') {
				v[i][j] = 0;
			}
			else {
				v[i][j] = 1;
				ones++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int len = (j - i + 1);
			for (int p = 0; p < n; p++) {
				int q = p + len - 1;
				if (q > n) {
					continue;
				}

				int flag = 1, ONES = 0;
				for (int I = i; I <= j; I++) {
					for (int J = p; J <= q; J++) {
						if (v[I][J] == 0) {
							flag = 0;
						}
						else {
							ONES++;
						}
					}
				}

				if (flag == 1) {
					if (ones == ONES) {
						cout << "SQUARE\n";
						return;
					}
				}
			}
		}
	}

	cout << "TRIANGLE\n";


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