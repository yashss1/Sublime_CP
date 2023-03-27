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
const int N = 2e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n, m, a, b;
vector<int> v;
int flag = 0;

bool solve(int k) {
	int temp = (flag == 0) ? (b - 1) : (n - a);
	for(int i = k - 1; i >= 0; i--) {
		if(v[i] + 1 > temp) {
			return 0;
		}
		temp--;
	}
	return 1;
}

void yash()
{
  cin >> n >> m >> a >> b; 
  v.assign(m, 0);
  flag = 0;
  for(int i = 0; i < m; i++) {
  	cin >> v[i];
  }
  sort(v.begin(), v.end());

  if(b < a) {
  	swap(a, b);
  	flag = 1;
  }


  int l = 0, r = min(m, (b - a - 1)), ans = 0;
  while(l <= r) {
  	int mid = (l + r) / 2;
  	if(solve(mid)) {
  		ans = mid;
  		l = mid + 1;
  	}
  	else {
  		r = mid - 1;
  	}
  }

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