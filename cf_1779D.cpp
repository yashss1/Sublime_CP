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
  }

  int m;
  cin >> m;
  vector<int> x(m);

  map<int, int> mp;
  for(int i = 0; i < m; i++) {
  	cin >> x[i];
  	mp[x[i]]++;
  }

  sort(all(x));
  stack<int> st;

  // 3 2 1 2 1 3
  for(int i = 0; i < n; i++) {
  	if(a[i] < b[i]) {
  		cout << "NO\n";
  		return;
  	}

  	if(st.empty()) {
  		if(a[i] != b[i]) {
  			st.push(b[i]);
  		}
  		continue;
  	}
  	int t = st.top();

  	if(t > b[i]) {
  		// cout << "add : " << b[i] << " ; top : " << st.top() << '\n';
  		if(a[i] != b[i]) {
  			st.push(b[i]);
  		}
  		continue;
  	}

  	if(t <= b[i]) {
  		while(!st.empty()) {
  			if(st.top() >= b[i])break;
  			int t1 = st.top();
  			if(mp[t1] <= 0) {
  				cout << "NO\n";
  				return;
  			}
  			mp[t1]--;
  			// cout << "remove : " << t1 << '\n';
  			st.pop();
  		}
  		if(a[i] != b[i] && (st.empty() || st.top() != b[i])) {
  			st.push(b[i]);
  		}	
  	// 	// cout << "TOP " << st.top() << '\n';
  	}
  }

  while(!st.empty()) {
  	// cout << st.top() << '\n';
  	// if(mp[st.top()] < part_of_mx && st.top() == mx) {
  	// 	cout << "NO\n";
  	// 	return;
  	// }
  	if(mp[st.top()] <= 0) {
  		cout << "NO\n";
  		return;
  	}
    mp[st.top()]--;
  	st.pop();
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
