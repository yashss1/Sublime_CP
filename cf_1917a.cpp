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
	int a = 0, b = 0, flag = 0;
	int pro = 1;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		pro *= v[i];
		if (v[i] > 0) {
			a++;
		}
		else if (v[i] < 0) {
			b++;
		}
		else {
			flag = 1;
		}
	}

	if (flag == 1) {
		cout << "0\n";
		return;
	}

	if (b == 0) {
		cout << "1\n";
		cout << "1 0\n";
		return;
	}
	if (b % 2 == 0) {
		cout << "1\n";
		for (int i = 0; i < n; i++) {
			if (v[i] < 0) {
				cout << i + 1 << " 0\n";
				return;
			}
		}
	}

	cout << "0\n";
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