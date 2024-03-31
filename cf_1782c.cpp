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

// not done
void yash()
{
	int n;
	cin >> n;
	string s;
	cin >> s;

	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		mp[s[i]]++;
	}

	vector<int> temp;
	for (auto it : mp) {
		temp.push_back(it.second);
	}

	pVec(temp);

	for (int letters = 1; letters <= 26; letters++) {
		if (n % letters == 0) {
			int times = n / letters;
			cout << letters << " " << times << '\n';

			vector<int> curr;
			for (auto it : temp) {
				if (abs(times - it) != 0)
					curr.push_back(times - it);
			}

			pVec(curr);
		}
	}
	cout << '\n';
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