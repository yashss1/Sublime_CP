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
  for(int i = 0; i < n; i++) {
  	cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
  	cin >> b[i];
  }

  int idx1 = -1, idx2 = -1;
  for(int i = 0; i < n; i++) {
  	if(a[i] != b[i]) {
  		idx1 = i;
  		break;
  	}
  }
  for(int i = n - 1; i >= 0; i--) {
  	if(a[i] != b[i]) {
  		idx2 = i;
  		break;
  	}
  }

  if(idx1 == -1) {
  	cout << "not possible\n";
  	return;
  }


  int temp = b[idx1];
  for(int i = idx1 - 1; i >= 0; i--) {
  	if(a[i] > temp) {
  		break;
  	} 
  	temp = a[i];
  	idx1--;
  }
  temp = b[idx2];
  for(int i = idx2 + 1; i < n; i++) {
  	if(a[i] < temp) {
  		break;
  	} 
  	temp = a[i];
  	idx2++;
  }
  // if(a == b){
  	cout << idx1 + 1 << " " << idx2 + 1 << '\n';
  // }
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