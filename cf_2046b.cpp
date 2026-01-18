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
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<int> temp = v;
	sort(temp.begin(), temp.end());

	vector<int> ans;
	vector<pair<int, int>> rem;
	set<int> st;
	int idx = 0, idx2 = -1;
	for (int i = 0; i < n; i++) {
		if (temp[idx] == v[i]) {
			ans.push_back(v[i]);
			idx++;
			idx2 = i;
		} else {
			rem.push_back({v[i], i});
			st.insert(i);
		}
	}
	pVec(ans);
	// pVec(rem);

	sort(rem.begin(), rem.end());
	for (int i = idx2 + 1; i < n; i++) {
		if ((rem[0].first + 1) >= v[i]) {
			ans.push_back(v[i]);
			st.erase(st.find(i));
		}
	}

	// cout << idx2 << '\n';



	for (auto it : rem) {
		if (st.find(it.second) == st.end()) {
		}
		else ans.push_back(it.first + 1);
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