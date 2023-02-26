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
  int d, m;
  cin >> d >> m; 

  // grps -> (1), (2, 3), (4, 5, 6, 7), (8, 9, 10, 11, 12, 13, 14, 15), ...
  // grps size -> 1, 2, 4, 8, ..

  // we have to choose only 1 from each grp. 
  // example, make 4size array from selecting elements from above 4grps. -> ways = 8*4*2*1

  vector<int> grps;
  int k = 0, curr = 0;
  while(curr < d) {
  	int temp = pow(2ll, k);
  	if(temp + curr <= d) {
  		grps.push_back(temp);
  		curr += temp;
  	} 
  	else {
  		grps.push_back(d - curr);
  		curr = d;
  	}
  	k++;
  }

  pVec(grps);


  int ans = 0, ans1 = 0;
  for(int i = 0; i < grps.size(); i++) {
  	for(int j = i + 1; j < grps.size(); j++) {
  		int res = grps[i] * grps[j];
  		cout << res << ' ';
  		ans += res;
  	}cout << '\n';
  } 
  cout << "\n\n";

  for(int i = 0; i < grps.size(); i++) {
  	for(int j = i + 1; j < grps.size(); j++) {
  		for(int k = j + 1; k < grps.size(); k++) {
  			int res = grps[i] * grps[j] * grps[k];
  			cout << res << ' ';
  			ans1 += res;
  		}cout << '\n';
  	}
  } 
  cout << "\n\n";
  cout << ans << ' ' << ans1 << '\n';


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