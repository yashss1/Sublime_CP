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
  int n, x, y;
  cin >> n >> x >> y;

  int res = 0;
    if(x * 3 >= y){
        res = (n / 3) * y + (n % 3) * x;
        res = min(res, ((n/3)+1)*y);
    }else{
        res = n * x;
    }
    cout << res << "\n";

  return;
  int num_cabs;
    int total_cab_cost;
    int total_train_cost;


  if (n <= 3) {
        // Take a cab
        num_cabs = 1;
        total_cab_cost = y;
    } else {
        // Take the train
        num_cabs = ceil(n / 3.0); // Round up to nearest integer
        total_train_cost = n * x;
    }

    // Calculate and output the minimum cost
    int min_cost = min(num_cabs * y, total_train_cost);
    // cout << "Minimum cost: " << min_cost << " dollars" << endl;
    cout << min_cost << "\n";
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