//YashS
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// This less<int> is comparatar (Replace greater<int> for descending)
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key


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

bool cmp(pair<int,int>&p1, pair<int,int>&p2){
if(p1.second != p2.second) return p1.second < p2.second;
    else{
      return p1.first>p2.first;
    }
}

void yash()
{
    int n, k;
    cin >> n >> k; 
    vector<int> a(n), b(n);
    vector<pair<int, int>> v;
    v.push_back({0, 0});
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        v.push_back({a[i], b[i]});
    }

    sort(v.begin(), v.end(), cmp);
    // for(auto it: v) {
    //     cout << it.first << " " << it.second << '\n';
    // }

    pbds A; 
    int count = 0, ansMax = 0;
    for(int i = v.size() - 1; i > 0; i--) {
        count++;
        A.insert(v[i].first);
        int start = v[i - 1].second + 1, end = v[i].second;
        // cout << i << " -> " << start << " " << end << '\n';
        if(end < start) {continue;}

        int l = start, r = end, ans = 0;
        while(l <= r) {
            int mid = (l + r) / 2;
            
            // number of ele smaller than mid are negative feedbacks
            int negFeeds = A.order_of_key(mid);
            if(negFeeds > k) {
                r = mid - 1;
            } else {
                ans = max(ans, (count * mid));
                l = mid + 1;
            }
        }
        ansMax = max(ansMax, ans);
    }
    
    cout << ansMax << '\n';
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