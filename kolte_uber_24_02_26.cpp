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
typedef long long ll;


void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

/*
QUESTION:
given an array of n integers, and a integer k. i want to find the kth largest OR of continguos subarrray. for example for brute force we can calculate all bitwise OR of all contiguos subarrray, and print kth largest from result array. how to optimise it

INPUT:
3
4 6
2 4 1 3
3 2
4 1 3
5 10
5 1 2 4 3


OUTPUT:
4
5
5


*/


struct BitWindow {
	int counts[11] = {0};
	int current_or = 0;

	void add(int val) {
		for (int i = 0; i < 11; ++i) {
			if ((val >> i) & 1) {
				if (++counts[i] == 1) current_or |= (1 << i);
			}
		}
	}

	void remove(int val) {
		for (int i = 0; i < 11; ++i) {
			if ((val >> i) & 1) {
				if (--counts[i] == 0) current_or &= ~(1 << i);
			}
		}
	}
};

ll countGreaterEqual(int X, int n, const vector<int>& a) {
	if (X == 0) return (ll)n * (n + 1) / 2;

	ll total = 0;
	BitWindow window;
	int L = 0;

	for (int R = 0; R < n; ++R) {
		window.add(a[R]);
		while (window.current_or >= X) {
			window.remove(a[L]);
			L++;
		}
		total += L;
	}
	return total;
}

void yash()
{
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int low = 0, high = 1023, ans = 0;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (countGreaterEqual(mid, n, v) >= k) {
			ans = mid;
			low = mid + 1;
		} else {
			high = mid - 1;
		}
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