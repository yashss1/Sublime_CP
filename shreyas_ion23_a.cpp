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


/*
3
2 2 2
1 2
3 4
3 3 2
1 1 3
2 2 4
3 3 1
1 2 3
6 5 4
*/

int rankStrongest(priority_queue<int> &pq, int rank) {
	vector<int> temp;
	rank--;
	while (rank--) {
		temp.push_back(pq.top());
		pq.pop();
	}
	int t = pq.top();

	for (auto it : temp) {
		pq.push(it);
	}
	return t;
}

void yash()
{
	int m, n, rank;
	cin >> m >> n >> rank;
	vector<int> a(m), b(n);
	priority_queue<int> pq;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		pq.push(a[i]);
	}

	vector<int> ans;
	ans.push_back(rankStrongest(pq, rank));

	for (int i = 0; i < n; i++) {
		cin >> b[i];
		pq.push(b[i]);
		ans.push_back(rankStrongest(pq, rank));
	}

	int res = 0;
	for (auto it : ans) {
		res += it;
	}
	cout << res << "\n";
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