//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
const int MOD = 1e9 + 7;
const int N = 1e5 + 7;
inline int gcd(int a, int b)          {if (b == 0) return a;    return gcd(b, a % b);}

int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

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
map<int, int>mp;

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

	mp[a] = min(mp[a], mp[b]);
}

void union_sets_bySize(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (size[a] < size[b])
			swap(a, b);
		parent[b] = a;
		merge(a, b);
		size[a] += size[b];
	}
}


void yash()
{
	int n;
	cin >> n;
	vector<int> risk(n + 1);
	//https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-fireman-vincent/
	for (int i = 1; i <= n; i++) {
		cin >> risk[i];
		mp[i] += risk[i];
		make_set(i);
	}

	int connected = 0;
	vector<int> size_of_grps;
	int k;
	cin >> k;
	while (k--) {
		// Join grp u & v
		int u, v;
		cin >> u >> v;
		union_sets_bySize(u, v);
	}

	map<int, map<int, int>>mp;
	for (int i = 1; i <= n; i++) {
		mp[find_set(i)][risk[i]]++;
	}

	vector<int> min_in_grp;
	for (auto it : mp) {
		map<int, int> temp = it.second;
		auto it1 = temp.begin();
		min_in_grp.pb(it1->second);
	}
	// pVec(min_in_grp);

	int ans = 1;
	for (int i = 0; i < min_in_grp.size(); i++) {
		ans = mod_mul(ans, min_in_grp[i], MOD);
	}
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