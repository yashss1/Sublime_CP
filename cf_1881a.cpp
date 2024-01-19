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
	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	// if (a.size() > b.size()) {
	//     cout << "-1\n";
	//     return;
	// }

	string aa = a;
	int temp = 0;
	while (aa.size() < b.size()) {
		aa += aa;
		temp++;
	}

	for (int j = 0; j < aa.size(); j++) {
		if (j + b.size() > aa.size()) {
			break;
		}
		string s = aa.substr(j, b.size());
		if (s == b) {
			cout << temp << '\n';
			return;
		}
	}


	aa += aa;
	temp++;
	for (int j = 0; j < aa.size(); j++) {
		if (j + b.size() > aa.size()) {
			break;
		}
		string s = aa.substr(j, b.size());
		if (s == b) {
			cout << temp << '\n';
			return;
		}
	}

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