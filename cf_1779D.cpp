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

  int mx = INT_MIN, flag = 0;
  for(int i = 0; i < n; i++) {
  	cin >> b[i];
  	if(a[i] != b[i]) {
  		mx = max(mx, b[i]);
  	}
  	if(a[i] - b[i] < 0) {
  		flag = 1;
  	}
  }

  b.push_back(mx);

  int m, part_of_mx = 1;
  cin >> m;
  vector<int> x(m);

  map<int, int> mp;
  for(int i = 0; i < m; i++) {
  	cin >> x[i];
  	mp[x[i]]++;
  }

  if(mx == INT_MIN) { //same
  	cout << "YES\n";
  	return;
  }

  if(flag == 1) {
  	cout << "NO\n";
  	return;
  }

  sort(all(x));
  stack<int> st;
  st.push(mx);

  // 3 2 1 2 1 3
  for(int i = 0; i < n; i++) {
  	int t = st.top();

  	if(b[i] > mx && i != n - 1) {
  		part_of_mx++;
  		continue;
  	}

  	if(t > b[i]) {
  		// cout << "add : " << b[i] << "| top : " << st.top() << '\n';
  		if(a[i] != b[i]) {
  			st.push(b[i]);
  		}
  		continue;
  	}

  	if(t < b[i]) {
  		while(!st.empty()) {
  			if(st.top() >= b[i] || st.top() == mx)break;
  			int t1 = st.top();
  			if(mp[t1] <= 0) {
  				cout << "NO\n";
  				return;
  			}
  			mp[t1]--;
  			// cout << "remove : " << t1 << '\n';
  			st.pop();
  		}
  	}
  }

  while(!st.empty()) {
  	if(mp[st.top()] < part_of_mx && st.top() == mx) {
  		cout << "NO\n";
  		return;
  	}
  	break;
  }

  cout << "YES\n";
  
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
