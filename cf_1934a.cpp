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
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	vector<int> temp;
	temp.push_back(v[0]); temp.push_back(v[1]); temp.push_back(v[n - 1]); temp.push_back(v[n - 2]);
	sort(temp.begin(), temp.end());
	int res = 0;

	do {
		int curr = 0;
		for (int i = 1; i < temp.size(); i++) {
			curr += abs(temp[i - 1] - temp[i]);
		}
		res = max(res, curr + abs(temp[3] - temp[0]));
	} while (next_permutation(temp.begin(), temp.end()));

	cout << res << '\n';

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
