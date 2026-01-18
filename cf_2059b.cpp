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
	int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
 
    int want = n - (k - 1);
    if(v[want] != 1) {
        cout << 1 << '\n';
        return;
    }
    for(int i = 1; i < want; i++) {
        if(v[i] != 1) {
            cout << "1\n";
            return;
        }
    }
    if(want > 1) {
        cout << "2\n";
        return;
    }
 
    int temp = 2;
    for(int i = want + 2; i < n; i+=2) {
        if(v[i] != temp) {
            cout << temp << "\n";
            return;
        } 
        temp += 1;
    }
 
    cout << temp << '\n';
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