// YashS
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

struct node {
	bool flag;
	map<char, node*> mp;
	int freq;
	node() {
		flag = false;
		freq = 0;
	}
};
node* root;

void insert(string s) {
	node* curr = root;
	for (auto it : s) {
		if (curr -> mp[it] == nullptr) {
			curr -> mp[it] = new node();
		}
		curr = curr -> mp[it];
		curr -> freq++;
	}
	curr -> flag = true;
}

string path = "";
int dfs(node* curr, int lvl) {
	if (curr == nullptr) {
		return 0;
	}
	if (curr -> freq == 2) {
		return lvl;
	}
	int c1 = dfs(curr -> mp['0'], lvl + 1);
	int c2 = dfs(curr -> mp['1'], lvl + 1);
	return max({c1, c2});
}

int maxDepth = 0;
void trace(node* curr, int lvl) {
	if (curr == nullptr) {
		return;
	}
	if (curr -> freq == 2) {
		return;
	}
	int c1 = dfs(curr -> mp['0'], lvl + 1);
	int c2 = dfs(curr -> mp['1'], lvl + 1);
	if (c1 == maxDepth) {
		path += "0";
		trace(curr -> mp['0'], lvl + 1);
	}
	if (c2 == maxDepth) {
		path += "1";
		trace(curr -> mp['1'], lvl + 1);
	}
	// assert(false);
}

vector<int> a, b;
void findSubPaths(node* curr, int prev, vector<int>& x) {
	if (curr == nullptr) {
		return;
	}
	x.push_back(prev);
	findSubPaths(curr -> mp['0'], 0, x);
	findSubPaths(curr -> mp['1'], 1, x);
}

void findBiggestCommonPath(node* curr) {
	if (curr == nullptr) {
		return;
	}
	for (auto it : path) {
		a.push_back(it - '0');
		b.push_back(it - '0');
		curr = curr -> mp[it];
	}
	// int c1 = (curr -> mp['0'] == nullptr ? 0 : curr -> mp['0'] -> freq);
	// int c2 = (curr -> mp['1'] == nullptr ? 0 : curr -> mp['1'] -> freq);
	// if (c1 >= c2 && c1 != 1) {
	// 	a.push_back(0); b.push_back(0);
	// 	findBiggestCommonPath(curr -> mp['0']);
	// }
	// else if (c2 > c1) {
	// 	a.push_back(1); b.push_back(1);
	// 	findBiggestCommonPath(curr -> mp['1']);
	// }
	{
		if (curr != nullptr) {
			findSubPaths(curr -> mp['0'], 0, a);
		}
		if (curr != nullptr) {
			findSubPaths(curr -> mp['1'], 1, b);
		}
	}
}

void yash()
{
	int n, k;
	cin >> n >> k;
	a.clear();
	b.clear();
	root = new node();

	vector<int> v(n);
	map<int, vector<int>> mp;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mp[v[i]].push_back(i + 1);
	}
	for (int i = 0; i < n; i++) {
		string s = bitset<31>(v[i]).to_string();
		reverse(s.begin(), s.end());
		s = s.substr(0, k);
		reverse(s.begin(), s.end());
		insert(s);

	}

	// cout << search("1011") << "\n";
	// cout << search("0100") << "\n";
	// cout << search("1111") << "\n";

	path = "";
	maxDepth = dfs(root, 0);
	trace(root, 0);
	cout << path << '\n';

	findBiggestCommonPath(root);
	pVec(a);
	pVec(b);

	return;

	// main
	int A = 0, B = 0, X = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == 1) {
			A += (pow(2, k - i - 1));
		}
		if (b[i] == 1) {
			B += (pow(2, k - i - 1));
		}
		if (a[i] == b[i] && a[i] == 0) {
			X += (pow(2, k - i - 1));
		}
	}

	if (A == B) {
		cout << mp[A][0] << " " << mp[B][1] << " " << X << "\n";
		return;
	}
	cout << mp[A][0] << " " << mp[B][0] << " " << X << "\n";

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