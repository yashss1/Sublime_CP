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

int gcd(int a, int b){if(b == 0)return a;return gcd(b, a % b);}

void yash()
{
  	int n, l, r;
  	cin >> n >> l >> r; 
  	vector<int> v(n);
  	for(int i = 0; i < n; i++) {
  		cin >> v[i];
  	}

  	map<int, int> mp, res;
  	mp[v[0]]++;
  	for(auto it: mp){
        res[it.first] += it.second;
    }
  	for(int i = 1; i < n; i++){
        map<int, int> temp;
        temp[v[i]]++;
        for(auto it: mp){
            temp[gcd(it.first, v[i])] += it.second;
        }

        for(auto it: temp){
            res[it.first] += it.second;
        }
      	mp = temp;
    }

    int ans = 0;
    for(auto it: res){
        if(it.first >= l && it.first <= r){
            ans += it.second;
        }
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