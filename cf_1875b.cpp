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

void swwap(multiset<int>&A, multiset<int>&B) {
	int a = *A.begin();
	int b = *B.rbegin();

	if (a < b) {
		A.erase(A.find(a));
		B.erase(B.find(b));
		B.insert(a);
		A.insert(b);
	}
}

void yash()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n), b(m);

	multiset<int> A, B;
	int suma = 0, sumb = 0;
	for (int i = 0; i < n ; i++) {
		cin >> a[i];
		suma += a[i];
		A.insert(a[i]);
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		sumb += b[i];
		B.insert(b[i]);
	}

	swwap(A, B);

	sort(all(a), greater<int>());
	sort(all(b), greater<int>());


	if (k % 2 == 0) {
		swwap(B, A);
	}

	int ans = 0;
	for (auto it : A) {
		ans += it;
	}
	cout << ans << "\n";

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