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
  int n, k;
  cin >> n >> k; 
  vector<int> v(n);
  rep(i, 0, n){
    cin>> v[i];
    v[i] %= n;
  }

  sort(all(v));
  int ans = 0;
  // ans = v[n - 1];
  // v.pop_back();
  map<int,int> mp, mp1;

  // pVec(v);

  rep(i, 0, n){
    mp[v[i]]++;
    // cout << v[i] << " | " << mp1[v[i]] << " || ";
    if(mp1[v[i]]){
      mp1[v[i]] = min(mp1[v[i]], i + 1);
    }else{
      mp1[v[i]] = i + 1;
    }
    // cout << v[i] << " | " << mp1[v[i]] << "\n";

  }

  // pVec(v);



  int k1 = n;
  int taken = 0;
  for(int i = n - 1; i >= 0; i--){
    if(mp[i]>=1){
      // cout << i << " " << mp1[i] <<" " <<k1 << '\n';
      if(k1 >= mp1[i]){
        ans+=i;
        taken++;
        if(taken >= k){
          goto end;
        }
      }
      // cout << ans << " ans\n";
      int curr = mp[i] - 1;
      k1--;
      while(k1>i && curr > 0){
        // cout << k1 <<" " << i << " ||\n";
        ans+=i;
        taken++;
        k1--;
        curr--;
        if(taken >= k){
          goto end;
        }
      }
      mp[i] = 0;
      mp[i%(k1)] += 1;
      // cout << ans <<" nas\n";
    }
  }
  end:
  cout << ans <<"\n";


  // while(v.size() >= 1){
  //   vector<int> temp = v;
  //   int rem = temp.size();
  //   rep(i, 0, temp.size()){
  //     temp[i] %= rem;
  //   }
  //   sort(all(temp));
  //   pVec(temp);
  //   ans += temp[temp.size()-1];
  //   // cout << temp[temp.size() - 1] << " |\n";
  //   temp.pop_back();
  //   v = temp;
  // }

  // cout << ans << '\n';

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