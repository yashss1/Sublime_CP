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
	string a, b, c;
	cin >> a;
	getline(cin, c);
	getline(cin, b);
	transform(a.begin(), a.end(), a.begin(), ::tolower);
	transform(b.begin(), b.end(), b.begin(), ::tolower);

	// cout << a << "\n" << b << "\n";

	int n = a.size();
	map<int, int> mp;

	for (int i = 0; i < n; i++) {
		// if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= '0' && a[i] <= '9'))
		mp[a[i]]++;
	}

	for (auto it : mp) {
		if (it.second > 1) {
			cout << "New Language Error\n";
			return;
		}
	}

	vector<string> temp;
	string curr;
	vector<pair<int, string>> v;

	for (int i = 0; i < (int)b.size(); i++) {
		if (b[i] == ' ') {
			temp.push_back(curr);
			curr = "";
			continue;
		}
		if (mp[b[i]] != 0) {
			curr.push_back(b[i]);
		}
	}
	if (curr.size() > 0) {
		temp.push_back(curr);
	}

	// pVec(temp);

	string ans;
	for (auto it : temp) {
		string s = it;
		map<int, int> mp2;
		for (int i = 0; i < (int)s.size(); i++) {
			mp2[s[i]]++;
		}

		string tt = "";
		for (int i = 0; i < n; i++) {
			// if (a[i] == ' ') continue;
			for (int j = 0; j < mp2[a[i]]; j++) {
				tt.push_back(a[i]);
			}
		}

		// cout << tt << '\n';
		ans += tt;
		ans += " ";
	}
	// ans.pop_back();

	cout << ans << '\n';
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