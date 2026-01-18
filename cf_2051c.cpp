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
	int n, m, k;
	cin >> n >> m >> k; 
	vector<int> a(m), q(k);

	set<int> missing;
	for(int i = 1; i <= n; i++) {
		missing.insert(i);
	}

	for(int i = 0; i < m; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < k; i++) {
		cin >> q[i];
		missing.erase(missing.find(q[i]));
	}

	if(missing.size() > 1) {
		for(int i = 0; i < m; i++) {
			cout << "0";
		}cout << '\n';
		return;
	}
	if(missing.size() == 0) {
		for(int i = 0; i < m; i++) {
			cout << "1";
		}cout << '\n';
		return;
	}

	int num = (*missing.begin());

	for(int i = 0; i < m; i++) {
		if(num == a[i]) {
			cout << "1";
		} else {
			cout << "0";
		} 
	} cout << '\n';
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