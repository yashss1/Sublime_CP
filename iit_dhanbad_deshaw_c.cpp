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

int n, k;
vector<int> v, cost;
vector<int> preV, preCost;

int go(int idx, int prev, int grpNo) {
	if (idx == n) {
		if (grpNo == 1) return 0;
		int x = preV[idx];
		int y = preCost[idx] - preCost[prev];
		int temp = (x + (k * grpNo)) * (y);
		cout << prev << " -> " <<  x << " " << grpNo*k << " " << y << " " << temp << "\n";
		return temp;
	}


	// break here
	int x = preV[idx];
	int y = preCost[idx] - preCost[prev];
	int temp = (x + (k * grpNo)) * (y);
	cout << idx << " " << prev << " " << grpNo << " " << x << " " << y << " " << temp << '\n';

	int c1 = temp + go(idx + 1, idx + 1, grpNo + 1);
	// continue
	int c2 = go(idx + 1, prev, grpNo);

	return max({c1, c2});
}

void yash()
{

	cin >> n >> k;
	v.resize(n); cost.resize(n);
	preV.resize(n + 1, 0); preCost.resize(n + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}

	for (int i = 0; i < n; i++) {
		preV[i + 1] = preV[i] + v[i];
	}
	for (int i = 0; i < n; i++) {
		preCost[i + 1] = preCost[i] + cost[i];
	}

	pVec(preCost);
	pVec(preV);
	cout << '\n';

	int ans = go(0, 0, 1);
	cout << ans << '\n';
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



/*
(pref[j] + (k * no)) * (cost[j] - cost[i]);
[pref[j] * (cost[j] - cost[i])] + [(k * no * (cost[j] - cost[i]))]

go(i + 1, n)
go(i + 1, n + 1)... go(i + 2, n + 1).. (solve(i, i + 3)) + go(i + 3, n + 1)...

bij -> costi.j
*/


