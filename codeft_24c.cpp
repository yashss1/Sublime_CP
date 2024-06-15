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
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mp[v[i]] = i;
	}

	// vector<int> temp;
	// temp.push_back(v[0]);
	// for (int i = 1; i < n; i++) {
	// 	if (v[i] == v[i - 1] + 1) {

	// 	}
	// 	else {
	// 		temp.push_back(v[i]);
	// 	}
	// }

	// // pVec(temp);
	// cout << temp.size() << '\n';
	// return;

	set<int> st;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (st.find(i) != st.end()) {
			continue;
		}
		int pos = mp[i];
		st.insert(i);
		int want = i + 1;
		for (int j = pos + 1; j < n; j++) {
			if (st.find(v[j]) != st.end()) continue;
			if (v[j] == want) {
				want++;
				st.insert(v[j]);
			} else {
				break;
			}
		}
		ans++;

	}
	cout << ans << '\n';


	// set<int> st;
	// while (curr <= n) {
	// 	if (st.find(curr) != st.end()) {
	// 		// cout << "HERE " << curr << '\n';
	// 		curr++;
	// 		continue;
	// 	}
	// 	int pos = mp[curr];
	// 	int i = pos; i++;
	// 	int prev = curr;
	// 	st.insert(prev);
	// 	// cout << i << " " << prev << " -> ";
	// 	while (i < n) {
	// 		if (v[i] == prev + 1) {
	// 			// cout << v[i] << " ";
	// 			st.insert(v[i]);
	// 			prev = v[i];
	// 			i++;
	// 		}
	// 		else {
	// 			break;
	// 		}
	// 	}
	// 	// cout << "\n";
	// 	curr++;
	// 	ans++;
	// }
	// cout << ans << '\n';
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