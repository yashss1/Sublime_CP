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

string s;
int n;
int go(int idx, int temp) {
	if(idx == n) {
		return 0;
	}
	return 0;	
}

void yash()
{
 	cin >> s;
 	n = s.size();

 	string s1 = s;
 	int ans = 0;
 	if(s[0] == '_') {
 		s1 = "^";
 		s1 += s;
 		ans++;
 	}
 	if(s1[s1.size() - 1] == '_') {
 		s1.push_back('^');
 		ans++;
 	}

 	s = s1;

 	vector<int> v;
 	int temp = 0;
 	for(int i = 0; i < s.size(); i++) {
 		if(s[i] == '_') {
 			temp++;
 		}	
 		else {
 			if(temp > 0)
 				v.push_back(temp);
 			temp = 0;
 		}
 	}
 	if(temp > 0) {
 		v.push_back(temp);
 	}


 	// pVec(v);
 	if(v.size() == 0) {
 		if(s.size() == 1) {
 			cout << "1\n";
 			return;
 		}
 	}
 	for(auto it: v) {
 		ans += (it - 1);
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