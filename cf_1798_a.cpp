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
  int n;
  cin >> n; 
  vector<int> a(n), b(n);
  int mx1 = INT_MIN, mx2 = INT_MIN;
  for(int i = 0; i < n; i++) {
  	cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
  	cin >> b[i];
  	if(a[i] > b[i]) {
  		swap(a[i], b[i]);
  	}
  	mx1 = max(mx1, a[i]);

  	mx2 = max(mx2, b[i]);
  }

  // sort(all(a));
  // sort(all(b));
  // pVec(a);
  // pVec(b);

  if(mx1 == a[n - 1] && mx2 == b[n - 1]) {
  	cout << "Yes\n";
  	return;
  }

  cout << "No\n";


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