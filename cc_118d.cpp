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

	vector<int> temp;
	for (int i = 32; i >= 0; --i) {
		if (n & (1 << i)) {
			temp.push_back(i);
			break;
		}
	}

	int ans = 0, flag = 0;
	for (int i = temp[0] - 1; i >= 0; i--) {
		if ((n & (1 << i)) == 0) {
			if (flag) {
				ans++;
			}
		} else {
			flag = 1;
		}
	}

	long long RES = pow(2ll, ans);

	cout << RES << "\n";

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