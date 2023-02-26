//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n;
vector<string> v(N);
string solve(string a) {

	vector<int> type(2 * n - 2);
	for(int i = 0; i < 2 * n - 2; i++) {
		int pref = 0, suff = 0;
  		// check if it is prefix of a
		int p = 0, q = 0;
		while(p < v[i].size() && q < n) {
			if(v[i][p] == a[q]) {
				p++, q++;
			}
			else {
				break;
			}
		}
		if(p == v[i].size()) pref = 1;

  		// check if it is suffix of b
		p = v[i].size(), q = n - 1;
		while(p > 0 && q > 0) {
			if(v[i][p - 1] == a[q]) {
				p--, q--;
			}
			else {
				break;
			}
		}
		if(p == 0) suff = 1;

		if(pref && suff) {
			type[i] = 2;
		}
		else if(pref) {
			type[i] = 0;
		}
		else if(suff) {
			type[i] = 1;
		}
	}

	// pVec(type);
	string ans(2 * n - 2, '-');
	int sLeft = n - 1, pLeft = n - 1;

	map<int, int> preL, sufL;

	for(int i = 0; i < 2 * n - 2; i++) {
		if(type[i] == 2) continue;
		if(type[i] == 0) {
			ans[i] = 'P';
			preL[v[i].size()] = 1;
			pLeft--;
		}else {
			ans[i] = 'S';
			sufL[v[i].size()] = 1;
			sLeft--;
		}
	}


	for(int i = 0; i < 2 * n - 2; i++) {
		if(sLeft > 0) {
			if(ans[i] == '-' && sufL[v[i].size()] == 0) {
				ans[i] = 'S';
				sufL[v[i].size()] = 1;
				sLeft--;
				continue;
			}
		}
		if(pLeft > 0) {
			if(ans[i] == '-' && preL[v[i].size()] == 0) {
				ans[i] = 'P';
				preL[v[i].size()] = 1;
				pLeft--;
				continue;
			}
		}
	}

	if(sLeft > 0 || pLeft > 0) {
		return "-";
	}
	return ans;
}

bool check(string a, string b) {
	// :( i dont wanna do this checking

	// cout << a << " " << b << '\n';

	for(int i = 0; i < 2 * n - 2; i++) {
		if(b[i] == 'P') {
			string temp = a.substr(0, v[i].size());
			if(temp != v[i]) {
				return false;
			}
		}
		if(b[i] == 'S') {
			reverse(a.begin(), a.end());
			reverse(b.begin(), b.end());
			string temp = a.substr(0, v[i].size());
			reverse(temp.begin(), temp.end());
			if(temp != v[i]) {
				return false;
			}
			reverse(a.begin(), a.end());
			reverse(b.begin(), b.end());
		}
	}

	return true;
}

void yash()
{
	cin >> n; 
	map<int, vector<string>> mp;

	for(int i = 0; i < 2 * n - 2; i++) {
		cin >> v[i];
		mp[v[i].size()].push_back(v[i]);
	}

	string a = "", b = "";
	a.push_back(mp[n - 1][0][0]);
	a += mp[n - 1][1];
	b.push_back(mp[n - 1][1][0]);
	b += mp[n - 1][0];

	// cout << a << " " << b << '\n';

  	// If b is our final string ? 
  	string res1 = solve(b);
  	if(res1 != "-" && check(b, res1)) {
  		cout << res1 << "\n";
  		return;
  	}

  	// If a is our final string ? 
  	string res2 = solve(a);	
 	if(res2 != "-" && check(a, res2)) {
 	 	cout << res2 << "\n";
 	 	return;
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