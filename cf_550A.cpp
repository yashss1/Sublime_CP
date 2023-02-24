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
	cin>>s;
	int n=s.length();
	vector<int>a,b;
	rep(i,0,n-1)
	{
		if(s[i]=='A' and s[i+1]=='B')
			a.pb(i);
		else if(s[i]=='B' and s[i+1]=='A')
			b.pb(i);
	}
	bool ans=true;
	if(a.size()==0 || b.size()==0)
	{
		ans=false;
		cout<<"NO"<<endl;
		return;	
	}
	if(abs(a[0]-b[b.size()-1]) < 2 and abs(b[0]-a[a.size()-1]) < 2)
		ans=false;
	if(ans)
		cout<<"YES";
	else
		cout<<"NO";
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