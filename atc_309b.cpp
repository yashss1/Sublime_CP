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
	vector<vector<int>> v(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			v[i][j] = s[j] - '0';
		}
	}

	vector<vector<int>> vv = v;

	vector<int> temp;
	for (int i = 0; i < n; i++) {
		temp.push_back(v[0][i]);
	}
	for (int i = 1; i < n; i++) {
		temp.push_back(v[i][n - 1]);
	}
	for (int i = n - 2; i >= 0; i--) {
		temp.push_back(v[n - 1][i]);
	}
	for (int i = n - 2; i >= 1; i--) {
		temp.push_back(v[i][0]);
	}

	// pVec(temp);
	temp.insert(temp.begin(), temp[temp.size() - 1]);
	temp.pop_back();
	// pVec(temp);


	int k = 0;
	for (int i = 0; i < n; i++) {
		v[0][i] = temp[k];
		k++;
	}
	for (int i = 1; i < n; i++) {
		v[i][n - 1] = temp[k];
		k++;
	}
	for (int i = n - 2; i >= 0; i--) {
		v[n - 1][i] = temp[k];
		k++;
	}
	for (int i = n - 2; i >= 1; i--) {
		v[i][0] = temp[k];
		k++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << v[i][j];
		} cout << '\n';
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