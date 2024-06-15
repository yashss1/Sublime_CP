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
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> v;
	vector<int> a(n + m + 1), b(n + m + 1), sumA(n + m + 2, 0), sumB(n + m + 2, 0);
	for (int i = 0; i < n + m + 1; i++) {
		cin >> a[i];
		sumA[i + 1] = sumA[i] + a[i];
	}
	for (int i = 0; i < n + m + 1; i++) {
		cin >> b[i];
		sumB[i + 1] = sumB[i] + b[i];
	}

	for (int i = 0; i < n + m + 1; i++) {
		v.push_back({a[i], b[i]});
	}


	vector<pair<int, int>> pref(n + m + 2, {0, 0}), sum(n + m + 2, {0, 0});
	for (int i = 0; i < n + m + 1; i++) {
		// cout << v[i].first << " " << v[i].second << "\n";
		pref[i + 1].first = pref[i].first + ((v[i].first > v[i].second) ? 1 : 0);
		pref[i + 1].second = pref[i].second + ((v[i].first < v[i].second) ? 1 : 0);
		if (v[i].first > v[i].second) {
			sum[i + 1].first = sum[i].first + v[i].first;
			sum[i + 1].second += sum[i].second;
		} else {
			sum[i + 1].second = sum[i].second + v[i].second;
			sum[i + 1].first += sum[i].first;
		}
	}

	// for (int i = 0; i <= n + m + 1; i++) {
	// 	cout << pref[i].first << " " << pref[i].second << " | " << sum[i].first << " " << sum[i].second << '\n';
	// } cout << "\n";

	vector<int> ohpls;

	int nTaken = 0, mTaken = 0, nSum = 0, mSum = 0;
	for (int i = 1; i <= n + m + 1; i++) {
		int findA = (n - nTaken) + pref[i].first, findB = (m - mTaken) + pref[i].second;
		// cout << "find " << findA << " " << findB << '\n';
		int ans = 0;

		int idxa = n + m + 1, idxb = n + m + 1;
		int l = i, r = n + m + 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (pref[mid].first >= findA) {
				idxa = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		l = i, r = n + m + 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (pref[mid].second >= findB) {
				idxb = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}

		// cout << findA << " " << findB << " -> " << idxa << " " << idxb << '\n';
		if (idxa < idxb) {
			ans += (sum[idxa].first - sum[i].first) + (sum[idxa].second - sum[i].second);
			ans += (sumB[n + m + 1] - sumB[idxa]);
		} else {
			ans += (sum[idxb].first - sum[i].first) + (sum[idxb].second - sum[i].second);
			ans += (sumA[n + m + 1] - sumA[idxb]);
		}
		ans += nSum + mSum;

		ohpls.push_back(ans);

		if (v[i - 1].first > v[i - 1].second && nTaken < n) {
			nTaken++;
			nSum += v[i - 1].first;
		} else if (v[i - 1].first > v[i - 1].second) {
			mTaken++;
			mSum += v[i - 1].second;
		}

		if (v[i - 1].first < v[i - 1].second && mTaken < m) {
			mTaken++;
			mSum += v[i - 1].second;
		} else if (v[i - 1].first < v[i - 1].second) {
			nTaken++;
			nSum += v[i - 1].first;
		}
		// cout << "taken N " << nTaken << " " << nSum << " M " << mTaken << " " << mSum << '\n';
		// cout << '\n';
	}
	pVec(ohpls);
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