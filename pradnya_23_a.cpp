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

string toBinary(int n)
{
  string r;
  while (n != 0) {r = (n % 2 == 0 ? "0" : "1") + r; n /= 2;}
  return r;
}

int solve(string s) {
	int n = s.size();
	vector<int> v;
	int temp = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == '0') {
			temp++;
		}
		else {
			if(temp > 0) {
				v.push_back(temp);
				temp = 0;
			}
		}
	}
	if(temp > 0) {
		v.push_back(temp);
	}

	if(v.size() == 0) {
		return 0;
	}
	sort(all(v), greater<int>());
	return v[0];
}

string brute(string s) {
	for(int i = s.size(); i >= 1; i--) {
		if(s[i - 1] == '1') {
			if(s[i] == '1') {
				s[i] = '0';
			}
			else {
				s[i] = '1';
			}
		}
	}
	return s;
}

void yash()
{
  int n;
  cin >> n; 
  vector<int> v(n);
  for(int i = 0; i < n; i++) {
  	cin >> v[i];
  }



  int res = v[0];

  int mx = INT_MAX;
  for(int i = 0; i < n; i++) {
  	string s = toBinary(v[i]);
  	 int flag = 1;
  for(int j = 0; j < s.size(); j++) {
  			if(s[j] == '0') {
  				flag = 0;
  			}
  }
  int ans = INT_MAX;
  if(flag == 1) {
  	ans = 0;
  }
  if(ans < mx) {
  		mx = ans;
  		res = v[i];
  	}
  	// cout << s << ' ';
  	// int curr = solve(s);
  	// // cout << curr << '\n';
  	// if(curr < mx) {
  	// 	mx = curr;
  	// 	ans = v[i];
  	// }
  	int j = 58, k = 0;
  	 ans = INT_MAX;
  	while(j--) {
  		// cout << s << '\n';
  		int flag = 1;
  		string temp = brute(s);
  		s = temp;
  		for(int j = 0; j < s.size(); j++) {
  			if(s[j] == '0') {
  				flag = 0;
  			}
  		}
  		if(flag == 1) {
  			ans = k;
  			break;
  		}
  		k++;
  	}
  	if(ans < mx) {
  		mx = ans;
  		res = v[i];
  	}
  }


  cout << res << '\n';

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