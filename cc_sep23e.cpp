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
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}


	priority_queue<pair<int, int>> pq;

	vector<int> res;
	res.push_back(0);
	res.push_back(m);

	res.push_back(v[0]);
	sort(res.begin(), res.end());

	pq.push({res[1] - res[0], 0});
	pq.push({res[2] - res[1], v[0]});

	map<pair<int, int>, int> mp;
	mp[ {res[1] - res[0], 0}]++;
	mp[ {res[2] - res[1], v[0]}]++;

	// for (auto it : mp) {
	//   cout << it.first.first << " " << it.first.second << '\n';
	// }

	multiset<int> s;
	s.insert(0);
	s.insert(m);
	s.insert(v[0]);

	vector<int> ans;
	ans.push_back(pq.top().first);

	map<int, int> currSize;
	currSize[0] = res[1] - res[0];
	currSize[v[0]] = res[2] - res[1];

	for (int i = 1; i < n; i++) {
		auto it = s.lower_bound(v[i]);
		it--;

		int sz = currSize[(*it)];
		int newSz = v[i] - (*it);
		int newSz2 = ((*it) + sz) - v[i];


		mp[ {sz, (*it)}]--;
		mp[ {newSz, (*it)}]++;
		mp[ {newSz2, v[i]}]++;

		// cout << sz << " " << (*it) << '\n';
		// cout << mp[ {sz, (*it)}] << "\n";
		// cout << v[i] << " -> " << (*it) <<  " " << newSz << " " << newSz2 <<  "\n";

		currSize[(*it)] = newSz;
		currSize[v[i]] = newSz2;

		pq.push({newSz, (*it)});
		pq.push({newSz2, v[i]});

		while (mp[ {pq.top().first, pq.top().second}] == 0) {
			pq.pop();
		}

		s.insert(v[i]);

		int curr = pq.top().first;
		ans.push_back(curr);
	}

	pVec(ans);
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