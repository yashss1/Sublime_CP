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

struct node {
	map<char, node*> mp;
	int val;
	set<int> st;
	node() {
		val = 0;
	}
};
node* root;

void insert(string s, int idx) {
	node* curr = root;
	for (auto it : s) {
		if (curr->mp[it] == nullptr) {
			curr->mp[it] = new node();
		}
		curr->mp[it]->val = idx;
		curr->mp[it]->st.insert(idx);
		curr = curr->mp[it];
	}
}

pair<int, int> get(string s) {
	node* curr = root;
	pair<int, int> ans = { -1, -1};
	for (auto it : s) {
		if (curr->mp[it] == nullptr) {
			ans = { -1, -1};
			return ans;
		}
		ans = {curr->mp[it]->st.size(), curr->mp[it]->val};
		curr = curr->mp[it];
	}
	return ans;
}

void yash()
{
	int n;
	cin >> n;
	vector<string> v(n);
	root = new node();

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		string s = v[i];
		for (int j = 0; j < s.size(); j++) {
			string temp = s.substr(j);
			insert(temp, i);
		}
	}

	int q;
	cin >> q;
	while (q--) {
		string s;
		cin >> s;
		pair<int, int> ans = get(s);
		if (ans.first == -1 && ans.second == -1) {
			cout << "0 -\n";
			continue;
		}

		cout << ans.first << " " << v[ans.second] << '\n';
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