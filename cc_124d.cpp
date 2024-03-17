//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<""
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
	int l, r;
	cin >> l >> r;

	vector<int> v;
	for (int i = l; i <= r; i++) {
		v.push_back(i);
	}

	if (v.size() == 1) {
		if (l == 1) {
			cout << "1\n";
			return;
		}
		cout << "-1\n";
		return;
	}

	// pVec(v);
	if (v.size() % 2 == 0) {
		for (int i = 0; i < v.size(); i += 2) {
			cout << v[i + 1] << " " << v[i] << ' ';
		}
		cout << '\n';
		return;
	}

	vector<int> ans;
	vector<int> temp;
	temp.push_back(v[0]); temp.push_back(v[1]); temp.push_back(v[2]);
	for (int i = 3; i < v.size(); i += 2) {
		ans.push_back(v[i + 1]);
		ans.push_back(v[i]);
	}

	do {
		int res = l, flag = 0;
		for (int i = 0; i < temp.size(); i++) {
			if (__gcd(res, temp[i]) != 1) {
				flag = 1;
			}
			res++;
		}
		if (flag == 0) {
			pVec(temp);
			pVec(ans);
			cout << "\n";
			return;
		}
	} while (next_permutation(temp.begin(), temp.end()));

	cout << "-1\n";

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