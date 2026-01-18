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
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	for (int i = 20; i >= 0; i--) {
		vector<int> A = a, B = b;

		for (int j = 0; j < n; j++) {
			if (A[j] & (1 << i)) {
				A[j] = 1;
			} else {
				A[j] = 0;
			}
			if (B[j] & (1 << i)) {
				B[j] = 1;
			} else {
				B[j] = 0;
			}
		}

		// cout << i << " -> \n";
		// pVec(A);
		// pVec(B);

		int a1 = 0, b1 = 0;
		for (int j = 0; j < n; j++) {
			a1 += A[j];
			b1 += B[j];
		}

		if ((a1 + b1) % 2 == 0) {
			continue;
		}

		int flag = -1;
		for (int j = 0; j < n; j++) {
			if (j % 2) {
				if (A[j] != B[j]) {
					flag = 1;
				}
			}
			else {
				if (A[j] != B[j]) {
					flag = 0;
				}
			}
		}

		if (flag == -1) {
			continue;
		}
		if (flag) {
			cout << "Mai\n";
			return;
		} else {
			cout << "Ajisai\n";
			return;
		}
	}
	cout << "Tie\n";
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