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
Code for - https://codeforces.com/contest/1878/problem/D
Reference:
https://github.com/mrsac7/CSES-Solutions/blob/master/src/2073%20-%20Substring%20Reversals.cpp
Treap Data structure, for string reversals
*/



struct node {
	node *L, *R;
	int W, S;
	char V;
	bool F;
	node(char x) {
		L = R = 0;
		W = rand();
		S = 1;
		V = x;
		F = 0;
	}
};

int size(node *treap) {
	return (treap == 0 ? 0 : treap->S);
}

void push(node *treap) {
	if (treap && treap->F) {
		treap->F = 0;
		swap(treap->L, treap->R);
		if (treap->L) treap->L->F ^= 1;
		if (treap->R) treap->R->F ^= 1;
	}
}

void split(node *treap, node *&left, node *&right, int k) {
	if (treap == 0)
		left = right = 0;
	else {
		push(treap);
		if (size(treap->L) < k) {
			split(treap->R, treap->R, right, k - size(treap->L) - 1);
			left = treap;
		}
		else {
			split(treap->L, left, treap->L, k);
			right = treap;
		}
		treap->S = size(treap->L) + size(treap->R) + 1;
	}
}

void merge(node *&treap, node *left, node *right) {
	if (left == 0) treap = right;
	else if (right == 0) treap = left;
	else {
		push(left);
		push(right);
		if (left->W < right->W) {
			merge(left->R, left->R, right);
			treap = left;
		}
		else {
			merge(right->L, left, right->L);
			treap = right;
		}
		treap->S = size(treap->L) + size(treap->R) + 1;
	}
}

void print(node *treap) {
	if (treap == NULL) return;
	push(treap);
	print(treap->L);
	cout << treap->V;
	print(treap->R);
}

void yash()
{
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;

	node *treap = 0;
	for (auto i : s) {
		merge(treap, treap, new node(i));
	}

	vector<pair<int, int>> v;
	vector<int> l, r;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		l.push_back(a);
	}
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		r.push_back(a);
		v.push_back({l[i], r[i]});
	}

	sort(v.begin(), v.end());

	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;

		int l = 0, r = m - 1;
		int curr = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (v[mid].first > x) {
				r = mid - 1;
			}
			else if (v[mid].second < x) {
				l = mid + 1;
			}
			else {
				curr = mid;
				break;
			}
		}
		// cout << v[curr].first << " " << v[curr].second << '\n';

		int L = min(x, (v[curr].first + v[curr].second - x));
		int R = max(x, (v[curr].first + v[curr].second - x));

		node *A, *B, *C;
		split(treap, A, B, L - 1);
		split(B, B, C, R - L + 1);
		B->F ^= 1;
		merge(treap, A, B);
		merge(treap, treap, C);
	}

	print(treap);
	cout << "\n";
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