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

// int solveA(vector<int> v) {
// 	int count = 1;
// 	int last = A[1];
// 	for (int i = 2; i <= N; i++) {
// 		if (A[i] > last) {
// 			count++;
// 			last = A[i];
// 		}
// 	}
// 	return count;
// }

void yash()
{
	int n, x;
	cin >> n >> x;

	vector<int> v;
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
	}

	// do {
	// 	for (auto it : v) {
	// 		cout << it << " ";
	// 	} cout << '\n';

	// } while (next_permutation(v.begin(), v.end()));

	if (x == 0) {
		for (auto it : v) {
			cout << it << " ";
		}
		cout << "\n";
		return;
	}

	if (x > n - 2) {
		cout << "-1\n";
		return;
	}

	int idx = 0, r = -1;
	int k = n - x - 1;

	for (int i = n; i >= 0; i--) {
		cout << i << " ";
		idx++;
		r = i;
		if (idx == k) break;
	}
	for (int i = 1; i < r; i++) {
		cout << i << " ";
	}
	cout << "\n";

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