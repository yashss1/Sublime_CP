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

string a, b;
int n, m;
vector<int> pref, suff;

bool solve(int k) {

	// not cheking perfect pref and suff in this loop
	for(int i = 1; i < n - k; i++) { 
		int done_till = pref[i - 1], done_from = suff[i + k];
		if(done_till + done_from >= m) {
			return true;
		}
		// cout << done_till << " " << done_from << '\n';
	}

	// remove complete suffix of length k
	string temp1 = a.substr(0, n - k), temp2;
	reverse(a.begin(), a.end());
	// remove complete prefix of length k
	temp2 = a.substr(0, n - k);
	reverse(a.begin(), a.end());
	reverse(temp2.begin(), temp2.end());

	// cout << temp1 << " " << temp2 << '\n';
	int p = 0;
	for(int i = 0; i < temp1.size(); i++) {
		if(temp1[i] == b[p]) {
			p++;
		}
	}
	if(p == m) {
		return true;
	}

	p = 0;
	for(int i = 0; i < temp2.size(); i++) {
		if(temp2[i] == b[p]) {
			p++;
		}
	}
	if(p == m) {
		return true;
	}


	return false;
}



void yash()
{
  cin >> a >> b;
  n = a.size(), m = b.size();
  pref.assign(n, 0); suff.assign(n, 0);


  int p = 0, k = 0;
  for(int i = 0; i < n && p < m; i++) {
  	if(a[i] == b[p]) {
  		p++;
  	}
  	pref[i] = p;
  }

  p = m - 1, k = 0;
  for(int i = n - 1; i >= 0 && p >= 0; i--) {
  	if(a[i] == b[p]) {
  		p--;
  		k++;
  	}
  	suff[i] = k;
  }

  // pVec(pref);
  // pVec(suff);

  // solve(3);
  // return;

  int ans = 0;
  int l = 0, r = n;
  while(l <= r) {
  	int mid = (l + r) / 2;
  	if(solve(mid)) {
  		l = mid + 1;
  		ans = mid;
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
  // test
  yash();
  return 0;
}