//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<"\n";
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

	string curr = to_string(v[0]);

	vector<int> seq = {v[0]};
	// pVec(seq);

	for (int i = 1; i < n; i++) {
		vector<int> temp = seq;
		int back = temp[temp.size() - 1];

		if (back == v[i]) {
			if (v[i] == 1) {
				temp.push_back(1);
				goto end;
			}

			temp.pop_back();
			if (!temp.empty())
				while (back + 1 != v[i]) {
					if (temp.size() == 0) {
						break;
					}
					back = temp[temp.size() - 1];
					temp.pop_back();
				}
			temp.push_back(v[i]);
		}
		else if (v[i] < back) {
			if (back + 1 == v[i] || temp.size() == 1) {

			}
			else {
				// cout << "BACK " << back << '\n';
				while (back + 1 != v[i]) {
					temp.pop_back();
					if (temp.size() == 0) {
						break;
					}
					back = temp[temp.size() - 1];
				}
			}
			if (back <= v[i]) {
				temp.pop_back();
			}

			temp.push_back(v[i]);
		}
		else {
			while (temp.size() != 0) {
				back = temp[temp.size() - 1];
				if ((back + 1 != v[i])) {
					temp.pop_back();
				}
				else {
					temp.pop_back();
					break;
				}
			}
			temp.push_back(v[i]);
		}


end:
		string curr = "";
		for (int i = 0; i < temp.size(); i++) {
			curr += to_string(temp[i]);
			curr += ".";
		}
		curr.pop_back();
		seq = temp;
		cout << curr << '\n';
	}
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