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

// 1) Check BST
struct Node
{
	Node* left, *right;
	int val;
	Node(int x) {
		left = NULL, right = NULL;
		val = x;
	}
};

bool dfs(Node* node, int mn = -1e9, int mx = 1e9) {
	if (node == NULL) {
		return true;
	}

	bool ans = true;
	if (!(node->val > mn && node->val < mx)) {
		ans = false;
	}

	return ans && dfs(node->left, mn, node->val) && dfs(node->right, node->val, mx);
}

bool question(Node* node) {
	return dfs(node);
}


// 2) Number of pairs such that XOR lies between L to R
/*

5
2 3 5 1 8


0010
0011
0101
0001
1000



*/

void yash()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int l, r;
	cin >> l >> r;

	for (int i = 0; i < n; i++) {
		int num = v[i];

		cout << bitset<4>(num) << '\n';

		// for (int j = 4; j >= 0; j--) {
		// 	if (num & (1 << j)) {
		// 		cout << "1";
		// 	} else {
		// 		cout << "0";
		// 	}
		// }
		// cout << '\n';
	}
	cout << "\n" << bitset<4>(l) << "\n" << bitset<4>(r) << '\n';

	/*
	0100
	0010
	 110

	0100
	0111
	 011

	1010

	1100

	0, 1 -> 0, 0 -> any choice will work -> (2 * 2)
		 -> 1, 1 -> 0 X
		 		 -> 1, 1 -> 0, 1
		 		 		 -> 1, X


	*/

	/*
	https://leetcode.com/contest/weekly-contest-354/problems/maximum-beauty-of-an-array-after-applying-operation/
	4,6,1,2

	2 4 -1 0
	6 8  3 4

	4 6
	4 						minimum ka maximum
	6 l <= r possible		maximum ka minimum

	4 6 1
	4
	3 l > r not possible

	1 2
	0
	3 l <= r possible
	*/
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