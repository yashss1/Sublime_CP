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
	string s;
	cin >> s;
	int n = s.size();

	int temp = 0;
	vector<int> v;
	s += s;
	int flag = 0, flag1 = 0;
 	for(int i = 0; i < s.size(); i++) {
 		if(s[i] == '1') flag = 1;
		if(s[i] == '0') flag1 = 1;

 		if(s[i] == '1') {
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

 	sort(all(v), greater<int>());

 	if(flag1 == 0) {
 		cout << n * n << '\n';
 		return;
 	}
 	if(flag == 0) {
 		cout << "0\n";
 		return;
 	}

 	int ans = 0;
 	temp = 1;
 	for(int i = v[0]; i >= 1; i--) {
 		ans = max(ans, i * temp);
 		temp++;
 	}
 	cout << ans << "\n";

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