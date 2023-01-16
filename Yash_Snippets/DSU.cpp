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

// Make new individual grp
void make_set(int v) {
	parent[v] = v;
	size[v] = 1;
	ranks[v] = 0;
}


//Returns root of each grp
int find_set(int v) {
	if (v == parent[v]) {
		return v;
	}
	return parent[v] = find_set(parent[v]);
}

//Find root of a & root of b and then merge the smaller grp in larger (this will reduce the depth of resulted tree), so as the root of larger grp is now the parent of all the nodes in the merged grp
// We can union based on size/rank
void union_sets_bySize(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (size[a] < size[b])
			swap(a, b);
		parent[b] = a;
		size[a] += size[b];
	}
}
void union_sets_byRank(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (ranks[a] < ranks[b])
			swap(a, b);
		parent[b] = a;
		if (ranks[a] == ranks[b])
			ranks[a]++;
	}
}

void yash()
{
	int n, k;
	cin >> n >> k;
	// Find number of distinct connected components after all the k operations;
	// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/

	for (int i = 1; i <= n; i++) {
		make_set(i);
	}

	while (k--) {
		// Join grp u & v
		int u, v;
		cin >> u >> v;
		union_sets_bySize(u, v);
	}

	int connected = 0;
	for (int i = 1; i <= n; i++) {
		if (find_set(i) == i) {
			connected++;
		}
	}
	cout << connected << '\n';
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