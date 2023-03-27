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

string a, b, s;
int go(int idx, int edgeBottom, int edgeTop, int idx2) {
    if (idx == a.size()) {
        return 0;
    }
 
  	int ans = 0;
 
    for (int i = 0; i < 10; i++) {
        if (edgeBottom && i < a[idx] - '0')continue;
        if (edgeTop && i > b[idx] - '0')continue;
 		
 		if(idx2 < s.size() - 1) {
 			// cout << idx << " " << idx2 << " " << s[idx2] << " " << i << "|||\n";
 			ans += go(idx + 1, edgeBottom && (i == a[idx] - '0'), edgeTop && (i == b[idx] - '0'), (i == s[idx2] - '0') ? (idx2 + 1) : 0);
 		}
 		else {
 			// cout << idx << " " << idx2 << " " << s[idx2] << " " << i << "|\n";
 			ans += (i == s[idx2] - '0') + go(idx + 1, edgeBottom && (i == a[idx] - '0'), edgeTop && (i == b[idx] - '0'), 0);
 		}
    }
    return ans;
}
 
void yash()
{
    cin >> s >> a >> b;
    reverse(all(a));
    while (a.size() < b.size()) {
        a += "0";
    }
    reverse(all(a)); 

    cout << s << " " << a << " " << b << '\n';
 
    int ans = 0;
 
    for (int i = 0; i < 10; i++) {
        if (i < a[0] - '0')continue;
        if (i > b[0] - '0')continue;
 
        int temp = go(1, i == a[0] - '0', i == b[0] - '0', (i == s[0] - '0') ? (1) : 0);
        cout << i << " " << temp << '\n';
        ans += temp;
    }
    cout << ans << "\n";
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