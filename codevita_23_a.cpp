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

pair<int, int> solve(int n, vector<int> v) {
	// two options -> taken (n / 2) elements or (n / 2 + 1) elements

	// taking (n / 2) elements (leave smallest element for other person)
	vector<int> A, B;

	// if (v[(n / 2)] > v[(n / 2) + 1]) {
	// 	swap(v[(n / 2)], v[(n / 2) + 1]);
	// }

	// pVec(v);

	int mn = INT_MAX, idx = 0;
	for (int i = 0; i < n; i++) {
		if (i > (n / 2)) {
			if (mn > v[i]) {
				mn = v[i];
				idx = i;
			}
		}
	}

	if (v[idx] < v[(n / 2)]) {
		swap(v[idx], v[n / 2]);
	}

	// pVec(v);

	for (int i = 0; i < n; i++) {
		if (i <= (n / 2)) {
			A.push_back(v[i]);
		}
		else {
			B.push_back(v[i]);
		}
	}
	// int mid = A[A.size() - 1];
	// A.pop_back();

	// sort(B.begin(), B.end());



	// if (B[B.size() - 1] < mid) {
	// 	A.push_back(B[B.size() - 1]);
	// 	B[B.size() - 1] = mid;
	// }
	// else {
	// 	A.push_back(mid);
	// }
	// pVec(A);
	// pVec(B);

	int a = 0, b = 0;
	for (auto it : A) {
		a += it;
	}
	for (auto it : B) {
		b += it;
	}
	// cout << a << " " << b << " a  b\n";

	if (a >= b) {
		return {0, abs(a - b)};
	}
	return {1, abs(a - b)};
}

void yash()
{
	int n;
	cin >> n;
	vector<int> v(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}

	if (n == 1) {
		cout << v[0] << "\n";
		return;
	}
	if (n == 3) {
		int a = 0;
		for (int i = 0; i <= 1; i++) {
			a += v[i];
		}

		int mx = max(a, sum - a);
		int mn = min(a, sum - a);
		cout << abs(mx - mn) << "\n";
		return;

	}

	if (n % 2 == 0) {
		int a = 0, b = 0;
		for (int i = 0; i < n; i++) {
			if (i < (n / 2)) {
				a += v[i];
			}
			else b += v[i];
		}
		int ans = abs(a - b);
		cout << ans << '\n';
		return;
	}

	// two options -> starting from left or right

	// starting from left
	pair<int, int> ans1 = solve(n, v);

	// starting from right
	reverse(v.begin(), v.end());
	pair<int, int> ans2 = solve(n, v);


	// int ans = min(ans1, ans1);

	if (ans1.first == 0) {
		cout << ans1.second << '\n';
		return;
	}
	cout << ans2.second << '\n';
}

signed main()
{
	// init_code();
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);
	// test
	yash();
	return 0;
}