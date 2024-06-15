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
	int n, f, k;
	cin >> n >> f >> k;
	vector<int> v(n);
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mp[v[i]]++;
	}
	int num = v[f - 1];


	sort(all(v), greater<int>());

	map<int, int> mp2, mp3;
	for (int i = k; i < n; i++) {
		mp2[v[i]]++;
		// cout << v[i] << " ";
	}
	// cout << '\n';
	for (int i = 0; i < k; i++) {
		mp3[v[i]]++;
		// cout << v[i] << " ";
	}
	// cout << '\n';

	if (mp2[num] >= 1 && mp3[num] >= 1) {
		cout << "MAYBE\n";
		return;
	}
	if (mp2[num] >= 1) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";

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