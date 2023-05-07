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

int n;
vector<int> v(N);


pair<vector<int>, vector<int>> solve(int sz) { // sz >= 3
	map<int, int> mp;
	multiset<int> st;
	for (int i = 0; i < sz; i++) {
		mp[v[i]]++;
		st.insert(v[i]);
	}

	//
	int k = 3;
	multiset<int>::reverse_iterator rit;
	vector<int> temp;
	for (rit = st.rbegin(); rit != st.rend() && k > 0; rit++) {
		temp.push_back(*rit);
		k--;
	}

	int ans = 0;
	int t1 = temp[0];
	int t2 = temp[1];
	int t3 = temp[2];

	int curr = ((t1 + t2 + t3) - sz + 1);
	ans = max(ans, curr);
	//

	vector<int> v1(n, 0), v2(n, 0);
	curr = INT_MIN;
	for (int i = 0; i < n; i++) {
		curr = max(curr, v[i]);
		v1[i] = max(curr, v[i]);
	}
	curr = INT_MIN;
	for (int i = n - 1; i >= 0; i--) {
		curr = max(curr, v[i]);
		v2[i] = max(curr, v[i]);
	}

	int leftmax = v[0], rightmax = v[n - 1];

	for (int i = 1; i < n; i++) {
		v1[i] = leftmax;
		leftmax = max(leftmax, v[i]);
	}

	for (int i = n - 2; i >= 0; i--) {
		v2[i] = rightmax;
		rightmax = max(rightmax, v[i]);
	}


	for (int i = 1; i < n; i++) {
		int rm = v[i - 1];

		int k = 3;
		multiset<int>::reverse_iterator rit;
		vector<int> temp;
		for (rit = st.rbegin(); rit != st.rend() && k > 0; rit++) {
			temp.push_back(*rit);
			k--;
		}
		// pVec(temp);
		int t1 = temp[0];
		int t2 = temp[1];
		int t3 = temp[2];
		int curr = ((t1 + t2 + t3) - sz + 1);
		ans = max(ans, curr);

		if (temp.size() >= 3) {
			int t1 = temp[0];
			int t2 = temp[1];
			int t3 = temp[2];

			if (rm == t1) {
				st.erase(st.find(t1));
				mp[t1]--;
			}
			else if (rm == t2) {
				st.erase(st.find(t2));
				mp[t2]--;
			}
			else if (rm == t3) {
				st.erase(st.find(t3));
				mp[t3]--;
			}
		}
		else {
			if (mp[rm] > 1) {
				mp[rm]--;
			}
		}

		mp[v[i]]++;
		st.insert(v[i]);
	}

	return {v1, v2};
}



void yash()
{
	cin >> n;
	v.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		v[i] -= 1;
	}


	pair<vector<int>, vector<int>> temp = solve(3);
	// for (int i = 3; i <= n; i++) {
	// 	int curr = solve(i);
	// 	ans = max(ans, curr);
	// }

	pVec(v);
	pVec(temp.first);
	pVec(temp.second);

	int ans = 0;
	for (int i = 1; i < n - 1; i++) {
		int curr = v[i] + temp.first[i] + temp.second[i] + 1;
		ans = max(ans, curr);
	}

	cout << ans << '\n';

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