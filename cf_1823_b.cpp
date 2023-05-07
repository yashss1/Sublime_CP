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
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> temp;
	map<int, vector<int>> mp, mp1;
	for (int i = 0; i < n; i++) {
		int k1 = i % k;
		mp[k1].push_back(v[i]);
	}

	map<int, int> done;
	for (int i = 0; i < n; i++) {
		done[i % k]++;
		if (done[i % k] == 1) {
			for (int j = i; j < n; j += k) {
				mp1[i % k].push_back(j + 1);
			}
		}
	}

	int flag = 0;
	for (int i = 0; i < k; i++) {
		vector<int> a = mp[i], b = mp1[i];
		sort(all(a)); sort(all(b));
		// cout << i << " -> \n";
		// pVec(a);
		// pVec(b);

		if (a == b) {
			continue;
		}
		else {
			flag++;
			int flag1 = 0;
			map<int, int> t1, t2;
			for (int j = 0; j < a.size(); j++) {
				t1[a[j]]++;
				t2[b[j]]++;
			}
			for (int j = 1; j <= n; j++) {
				if (t1[j] != t2[j]) {
					flag1++;
				}
			}
			if (flag1 != 2) {
				cout << "-1\n";
				return;
			}
		}

	}
	if (flag == 2) {
		cout << "1\n";
		return;
	}
	if (flag != 0) {
		cout << "-1\n";
		return;
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