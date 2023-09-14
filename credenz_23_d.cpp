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

long long solution(const vector<int> &v) {
	const int n = v.size();
	unordered_map<int, list<int>> last;
	long long r = 0, sum = 0;
	for (int i = 0; i < n; ++i) {
		if (last.count(v[i])) {
			sum += i - last[v[i]].back();
			auto t = last[v[i]].end();
			--t;
			if (t != last[v[i]].begin()) {
				sum -= last[v[i]].back() - *(--t);
			} else {
				sum -= *t + 1;
			}
		} else {
			sum += i + 1;
		}
		last[v[i]].push_back(i);
		if (last[v[i]].size() > 2) {
			last[v[i]].pop_front();
		}
		r += sum;
	}
	return r;
}

void yash()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}


	vector<long long> L(n, -1), R(n, -1);
	map<int, int> lastL, lastR;
	map<int, int> lastLL, lastRR;

	for (int i = 0; i < n; i++) {
		if (lastLL[v[i]] == 0) {
			L[i] = i - (-1);
		}
		else {
			L[i] = i - lastL[v[i]];
		}
		lastL[v[i]] = i;
		lastLL[v[i]] = 1;
	}

	for (int i = n - 1; i >= 0; i--) {
		if (lastRR[v[i]] == 0) {
			R[i] = n - i;
		}
		else {
			R[i] = lastR[v[i]] - i;
		}

		lastR[v[i]] = i;
		lastRR[v[i]] = 1;
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		ans = (ans + (L[i] * R[i]) );
	}

	// int ans = solution(v);
	cout << ans << "\n";
}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// test
	yash();
	return 0;
}