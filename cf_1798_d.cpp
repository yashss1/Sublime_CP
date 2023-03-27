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
  int mx = INT_MIN, mn = INT_MAX;
  vector<int> pos, neg;
  for(int i = 0; i < n; i++) {
  	cin >> v[i];
  	mx = max(mx, v[i]);
  	mn = min(mn, v[i]);
  	if(v[i] > 0) {
  		pos.push_back(v[i]);
  	}
  	else {
  		neg.push_back(v[i]);
  	}
  }

  int t = mx - mn;
  // cout << t << "\n";

  int p = 0, q = 0;
  int curr_sum = 0;
  vector<int> res;
  int flag = 0;
  while(p < pos.size() && q < neg.size()) {
    if(abs(curr_sum + neg[q]) < t) {
      res.push_back(neg[q]);
      curr_sum += neg[q];
      q++;
      continue;
    }
  	if(abs(curr_sum + pos[p]) < t) {
  		curr_sum += pos[p];
  		res.push_back(pos[p]);
  		p++;
  		continue;
  	}
  	flag = 1;
  }
  while(q < neg.size()) {
    if(abs(curr_sum + neg[q]) < t) {
      res.push_back(neg[q]);
      curr_sum += neg[q];
      q++;
      continue;
    }
    flag = 1;
  }

  while(p < pos.size()) {
  	if(abs(curr_sum + pos[p]) < t) {
  		curr_sum += pos[p];
  		res.push_back(pos[p]);
  		p++;
  		continue;
  	}
  	flag = 1;
  }
  if(flag == 1) {
    cout << "No\n";
    return;
  }

  cout << "Yes\n";
  pVec(res);
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