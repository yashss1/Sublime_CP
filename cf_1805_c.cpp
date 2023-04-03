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

void yash()
{
  int n, m;
  cin >> n >> m; 
  vector<pair<int, int>> v;
  for(int i = 0; i < n; i++) {
  	int a, b;
  	cin >> a;
  	b = i + 1;
  	v.push_back({a, b});
  }
  sort(all(v));

  for(int i = 0; i < m; i++) {
  	int a, b, c;
  	cin >> a >> b >> c;

  	int want = 4 * a * c;
  	int l = 0, r = n - 1, curr = 0;
  	while(l <= r) {
  		int mid = (l + r) / 2;

  		if(v[mid].first < b) {
  			curr = mid;
  			l = mid + 1;
  		}
  		else{
  			r = mid - 1;
  		}
  	}

  	int t1 = curr;
  	int t2 = (curr > 0) ? curr - 1 : curr;
  	int t3 = (curr < n - 1) ? curr + 1 : curr;

  	if((v[t1].first - b) * (v[t1].first - b) < want) {
  		cout << "YES\n";
  		cout << v[t1].first << '\n';
  		continue;
  	}
  	if((v[t2].first - b) * (v[t2].first - b) < want) {
  		cout << "YES\n";
  		cout << v[t2].first << '\n';
  		continue;
  	}
  	if((v[t3].first - b) * (v[t3].first - b) < want) {
  		cout << "YES\n";
  		cout << v[t3].first << '\n';
  		continue;
  	}
  	cout << "NO\n";
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