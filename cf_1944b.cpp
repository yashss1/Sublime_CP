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
	k *= 2;
	vector<int> v(2 * n), a(n), b(n);
	map<int, int> A, B;

	for (int i = 0; i < 2 * n; i++) {
		cin >> v[i];
		if (i < n) {
			a[i] = v[i];
			A[a[i]]++;
		}
		else {
			b[i - n] = v[i];
			B[b[i - n]]++;
		}
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	// pVec(a);
	// pVec(b);

	vector<int> p, q;
	map<int, int> taken;

	int doubles = 0;
	for (auto it : A) {
		if (it.second == 2 && k > 1) {
			p.push_back(it.first);
			p.push_back(it.first);
			taken[it.first]++;
			k -= 2;
			doubles++;
		}
	}
	for (auto it : A) {
		// cout << it.first << " " << it.second << '\n';
		if (it.second == 1 && k > 0) {
			p.push_back(it.first);
			q.push_back(it.first);
			k--;
		}
	}

	for (auto it : B) {
		if (it.second == 2 && doubles > 0) {
			q.push_back(it.first);
			q.push_back(it.first);
			taken[it.first]++;
			doubles--;
		}
	}

	pVec(p);
	pVec(q);
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