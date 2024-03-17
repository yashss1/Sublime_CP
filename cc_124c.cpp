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
	string s;
	cin >> s;
	n = s.size();

	map<char, int> mp;
	vector<vector<int>> v(26, vector<int>(n + 1, 0));
	for (int i = 0; i < n; i++) {
		mp[s[i]]++;
		for (int j = 0; j < 26; j++) {
			v[j][i + 1] += v[j][i];
		}
		v[s[i] - 'a'][i + 1]++;
	}


	int ans = INT_MAX;
	for (auto it : mp) {
		char c = it.first;
		int count = it.second;

		// vector<int> temp;
		// int curr = 0;
		// for (int i = 0; i < n; i++) {
		//     if (s[i] == c) {
		//         curr++;
		//     }
		//     else {
		//         if (curr) {
		//             temp.push_back(curr);
		//         }
		//         curr = 0;
		//     }
		// }
		// if (curr) {
		//     temp.push_back(curr);
		// }

		// // cout << c << " -> ";
		// // pVec(temp);

		// sort(temp.begin(), temp.end(), greater<int>());
		// int res = 0;
		// for (int i = 1; i < temp.size(); i++) {
		//     res += temp[i];
		// }

		// ans = min(ans, res);

		// cout << c << '\n';
		// pVec(v[c - 'a']);

		int res = INT_MAX;
		for (int i = 0; i < n; i++) {
			int l = i;
			int r = i + count - 1;
			if (r >= n) {
				break;
			}

			int num = v[c - 'a'][r + 1] - v[c - 'a'][l];
			// cout << l << " " << r << " -> " << num << "\n";

			res = min(res, count - num);
		}
		ans = min(ans, res);
	}
	cout << ans << "\n";
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