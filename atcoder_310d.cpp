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
const int N = 1e2 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int parent[N];
int size[N];
int ranks[N];
multiset<int> sizes;

void make_set(int v) {
	parent[v] = v;
	size[v] = 1;
	ranks[v] = 0;
	sizes.insert(1);

}
int find_set(int v) {
	if (v == parent[v]) {
		return v;
	}
	return parent[v] = find_set(parent[v]);
}


// Have to edit this merge function in many questions
void merge(int a, int b) {
	//merge a in b
	// sizes.erase(size[a]); // THis will remove all the elements of that value
	sizes.erase(sizes.find(size[a]));
	sizes.erase(sizes.find(size[b]));

	sizes.insert(size[a] + size[b]);
}

void union_sets_bySize(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		// if (size[a] < size[b])
		// 	swap(a, b);
		parent[b] = a;
		// merge(a, b);
		// size[a] += size[b];
	}
}


void yash()
{
	int n, t, m;
	cin >> n >> t >> m;
	vector<pair<int, int>> v(m);
	for (int i = 1; i <= n; i++) {
		make_set(i);
	}

	set<pair<int, int>> pairs;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			pairs.insert({i, j});
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> v[i].first >> v[i].second;
		if (v[i].first > v[i].second) {
			swap(v[i].first, v[i].second);
		}

		pairs.erase(pairs.find({v[i].first, v[i].second}));
	}


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