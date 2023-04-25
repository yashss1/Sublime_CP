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
  vector<int> v(n);
  for(int i = 0; i < n; i++) {
  	cin >> v[i];
  }

  int curr_mex = 0;
  vector<int> v1 = v;
  sort(all(v1));
  for(int i = 0; i < n; i++) {
  	if(v1[i] == curr_mex) {
  		curr_mex++;
  	}
  }

  if(curr_mex == n) {
  	cout << "No\n";
  	return;
  }


  int a = -1, b = 0;
  for(int i = 0; i < n; i++) {
  	if(v[i] == curr_mex + 1) {
  		a = i;
  		break;
  	}
  }

  for(int i = 0; i < n; i++) {
  	if(v[i] == curr_mex + 1) {
  		b = i;
  	}
  }

  if(a == -1) {
  	cout << "Yes\n";
  	return;
  }

  for(int i = a; i <= b; i++) {
  	v[i] = curr_mex;
  }

  int curr_mex2 = 0;
  v1 = v;
  sort(all(v1));
  for(int i = 0; i < n; i++) {
  	if(v1[i] == curr_mex2) {
  		curr_mex2++;
  	}
  }

  if(curr_mex2 == curr_mex + 1) {
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
