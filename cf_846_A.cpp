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
  vector<int> v(n), odd, even;
  rep(i, 0, n){
  	cin >> v[i];
  	if(v[i] % 2){
  		odd.push_back(i);
  	}else {
  		even.push_back(i);
  	}
  }

  int p = even.size(), q = odd.size();

  if(q == 0){
  	cout << "NO\n";
  	return;
  }

  vector<int> ans;
  ans.push_back(odd[0]);

  if(even.size() >= 2){
  	ans.push_back(even[0]);
  	ans.push_back(even[1]);

  	cout << "YES\n";
  	pVec(ans);
  	return;
  }

  if(odd.size() >= 3){
  	ans.push_back(odd[1]);
  	ans.push_back(odd[2]);

  	cout << "YES\n";
  	pVec(ans);
  	return;
  }

  cout << "NO\n";

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