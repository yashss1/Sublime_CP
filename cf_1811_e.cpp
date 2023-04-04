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

string a, b;
int dp[2][2][20];

int go(int idx, int edgeBottom, int edgeTop) {
    if (idx == a.size()) {
        return 0;
    }
 
    int &ans = dp[edgeBottom][edgeTop][idx];
    if (ans != -1) {
        return ans;
    }
 
    ans = 0;
 
    for (int i = 0; i < 10; i++) {
        if (edgeBottom && i < a[idx] - '0')continue;
        if (edgeTop && i > b[idx] - '0')continue;
 
        ans += ((i == 4) ? 1 : 0) + go(idx + 1, edgeBottom && (i == a[idx] - '0'), edgeTop && (i == b[idx] - '0'));
    }
    return ans;
}

int solve2(int n) {
	a = to_string(0);
	b = to_string(n);
	reverse(all(a));
    while (a.size() < b.size()) {
        a += "0";
    }
    reverse(all(a));
    memset(dp, -1, sizeof(dp));

    int ans = 0;
 
    for (int i = 0; i < 10; i++) {
        if (i < a[0] - '0')continue;
        if (i > b[0] - '0')continue;
 
        int t = ((i == 4) ? 1 : 0) +  go(1, i == a[0] - '0', i == b[0] - '0');
        ans += t;
    }

    return ans;
}

int solve(int n) {
	int temp = 0;

	for(int i = 1; i <= n; i++) {
  		string s = to_string(i);
  		int flag = 1;
  		for(auto it: s) {
  			if(it == '4') {
  				flag = 0;
 	 		}
 	 	}
 	 	if(flag == 0) {
 	 		// cout << i << '\n';
 	 		temp++;
  		}
 	}
 	return temp;
}

// https://www.geeksforgeeks.org/count-numbers-from-1-to-n-that-have-4-as-a-a-digit/
vector<int> power(19, 0), A(30);
int countNumbersWith4(int n)
{
   if (n < 4)
      return 0;
   int d = log10l(n);

   // cout << d << '\n';
   d = max(d, 0ll);
   A[0] = 0, A[1] = 1;
   for (int i=2; i<=d; i++)
      A[i] = (int)(A[i-1]*9ll) + (int)ceil(power[i - 1]);

   int p = (int)ceil((int)power[d]);
 
   int msd = n/p;
   if (msd == 4)
      return (msd)*A[d] + (n%p) + 1ll;
   if (msd > 4)
      return (int)(msd-1ll)*A[d] + p + countNumbersWith4(n%p);
   return (int)(msd)*A[d] + countNumbersWith4(n%p);
}


void yash()
{
  int n;
  cin >> n; 

  // cout << 1e13 - countNumbersWith4(1e13) << "\n";
  // return;
  // for(int i = 1; i <= 100; i++) {
  // 	cout << i << " -> " << solve(i) << " " << solve2(i) << '\n';
  // }
  // return;

  int temp = 0;
  int l = 0, r = 1e14;
  while(l <= r) {
  	int mid = (l) + ((r - l) / 2);
  	if((mid - countNumbersWith4(mid)) >= n) {
  		r = mid - 1;
  		temp = mid;
  	}
  	else {
  		l = mid + 1;
  	}
  }
  
  cout << temp << '\n';
}

signed main()
{
  init_code();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  power[0] = 1;
  for(int i=1; i<19; i++){
    power[i] = power[i-1] * 10LL;
  }

  test
  yash();
  return 0;
}