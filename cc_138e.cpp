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

int prime[100010] = {0};
vector<int> temp;
void seive(int n)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (prime[i] == 0)
		{
			for (int j = i * i; j <= n; j += i)
			{
				prime[j] = 1;
			}
		}
	}

	// Now Printing all the unmarked numbers
	for (int i = 2; i <= n; i++)
	{
		if (prime[i] == 0)
		{
			temp.push_back(i);
		}
	}
}

int notSame(int a, int b, int c) {
	set<int> st;
	st.insert(a);
	st.insert(b);
	st.insert(c);
	if (st.size() == 3) return 1;
	return 0;
}

bool isPerfectSquare(int x)
{
	if (x >= 0) {
		long long sr = sqrt(x);
		return (sr * sr == x);
	}
	return false;
}

void yash()
{
	int n;
	cin >> n;
	// pVec(temp);
	// cout << temp.size() << '\n';
	// for (int i = 0; i < temp.size(); i++) {
	// 	cout << temp[i] << " -> " << (temp[i] * temp[i]) << '\n';
	// }
	dc

	// map<int, int> mp;
	for (int i = 0; i < temp.size(); i++) {
		int num = temp[i];
		if (n - (temp[i] * temp[i]) >= 0) {
			int tempp = n - (num * num);
			// cout << temp[i] << " " << tempp << '\n';
			// mp[n - (num * num)]++;

			if (tempp % 2 == 1) {
				if (tempp > 4) {
					// cout << " | " << tempp - 4 << "\n";
					if (isPerfectSquare(tempp - 4)) {
						// cout << "HERE\n";
						if (prime[(int)sqrt(tempp - 4)] == 0 && notSame(temp[i], 2, sqrt(tempp - 4))) {
							cout << "Yes\n";
							return;
						}
					}

				}
			}
			// if (tempp % 2 == 0) {
			// 	if (tempp > 4) {
			// 		if ((sqrt(tempp - 4) * sqrt(tempp - 4)) == (tempp - 4)) {
			// 			if (prime[tempp - 4] == 0 && notSame(temp[i], 2, sqrt(tempp - 4))) {
			// 				cout << "Yes\n";
			// 				return;
			// 			}
			// 		}

			// 	}

			// } else {

			// }
		}
	}
	// for (int i = 0; i < temp.size(); i++) {
	// 	for (int j = i + 1; j < temp.size(); j++) {
	// 		int t = (temp[i] * temp[i]) + (temp[j] * temp[j]);
	// 		if (mp[t] && sqrt(n - t) != temp[i] && sqrt(n - t) != temp[j]) {
	// 			// cout << temp[i] << " " << temp[j] << " | " << n - t << '\n';
	// 			cout << "Yes\n"; return;
	// 		}
	// 	}
	// }
	cout << "No\n";
}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	seive(100001);
	test
	yash();
	return 0;
}