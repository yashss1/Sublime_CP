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
	vector<int> v(n), temp;
	temp.clear();
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int sum = v[0];
	for (int i = 1; i < n; i++) {
		if (v[i] > 0 && v[i - 1] > 0) {
			sum += v[i];
		}
		else if (v[i] < 0 && v[i - 1] < 0) {
			sum += v[i];
		}
		else {
			temp.push_back(sum);
			sum = v[i];
		}
	}
	temp.push_back(sum);

	int mx = 0, mn = 0;
	for (int i = 0; i < n; i++) {
		mx += v[i];
		mn += v[i];

		mx = max(abs(mx), abs(mn));
	}
	cout << mx << '\n';

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