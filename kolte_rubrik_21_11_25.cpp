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
vector<int> pref[26];

int go(int idx, int sameTime, int partionTime) {
	if (idx == n) {
		return 0;
	}

	int ans = INT_MAX;
	for (int i = idx; i < n; i++) {
		// partition karo
		// calculate idx to i
		int curr_ans = 0;
		for (int a = 0; a < 26; a++) {
			int temp = pref[a][i + 1] - pref[a][idx];

			// if (temp != 0)
			//   cout << (char)(a + 'a') << " -> " << idx << " to " << i << " -> " << temp << '\n';

			curr_ans += ((temp * (temp - 1) / 2) * sameTime);
		}

		curr_ans += ((i + 1 == n) ? 0 : (partionTime)) + go(i + 1, sameTime, partionTime);

		ans = min(ans, curr_ans);
	}

	return ans;
}

int getMinimumTime(int sameTime, int partionTime, string s) {
	n = s.size();
	for (int i = 0; i < 26; i++) {
		pref[i].assign(n + 1, 0);
	}

	for (char a = 'a'; a <= 'z' ; a++) {
		int ch = a - 'a';
		for (int i = 0; i < n; i++) {
			pref[ch][i + 1] += pref[ch][i];
			if (s[i] == a) {
				pref[ch][i + 1]++;
			}
		}

		// cout << a << " -> ";
		// pVec(pref[ch]);
	}

	int ans = go(0, sameTime, partionTime);

	return ans;
}

void yash()
{
	string s;
	cin >> s;
	int a, b;
	cin >> a >> b;


	int ans = getMinimumTime(a, b, s);
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