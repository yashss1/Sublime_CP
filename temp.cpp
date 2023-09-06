//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
int MOD = 1e9 + 7;
int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

void yash()
{
  int n, m;
  cin >> n >> m;
  vector<int> vec(n);

  for (auto &i : vec) {
    cin >> i;
  }

  map<int, int> currSize;
  currSize[0] = m;

  map<pair<int, int>, int> mp;
  mp[ {m - 0, 0}]++;


  multiset<int> multi;
  multi.insert(0); multi.insert(m);

  priority_queue<pair<int, int>> pq;
  pq.push({m, 0});

  for (int i = 0; i < n; i++) {
    auto iter = multi.lower_bound(vec[i]);
    iter--;

    int prev = (*iter);

    int sz = currSize[prev], naman = vec[i] - prev;
    int kl = (prev + sz) - vec[i];


    currSize[prev] = naman;
    currSize[vec[i]] = kl;

    mp[ {sz, prev}]--;

    multi.insert(vec[i]);

    pq.push({naman, prev});
    pq.push({kl, vec[i]});

    mp[ {naman, prev}]++;
    mp[ {kl, vec[i]}]++;

    while (!mp[ {pq.top().first, pq.top().second}]) {
      pq.pop();
    }

    cout << pq.top().first << " ";
  }
  cout << "\n";
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