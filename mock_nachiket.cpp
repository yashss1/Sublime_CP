// // go(node, rem_k) {
// // 	rem_k == 0 && node == n2 return 1
// // 	rem_k <=0 return 0


// // 	all children of node
// // 		ans += go(child, rem_k - 1)


// // 	return ans;
// // }


// //YashS
// https://www.codechef.com/problems/CCWI1901
// #include <bits/stdc++.h>
// using namespace std;
// #define test              int T;cin>>T;while(T--)
// #define int               long long
// #define pb                push_back
// #define all(x)            (x).begin(),(x).end()
// #define rep(i,a,b)        for(int i=a;i<b;i++)
// #define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
// const int MOD = 1e9 + 7;
// const int N = 1e5 + 7;

// void init_code() {
// #ifndef ONLINE_JUDGE
//   freopen("inputf.txt", "r", stdin);
//   freopen("outputf.txt", "w", stdout);
// #endif // ONLINE_JUDGE
// }

// int mod_add(int a, int b, int mod) {
// 	a %= mod;
// 	b %= mod;
// 	return ((a + b) % mod);
// }

// int n, m;
// vector<vector<int>> adj;
// int n1, n2;

// int dp[502][602];

// int go(int node, int rem_k) {
// 	if(rem_k == 0 && node == n2) {
// 		return 1;
// 	} 
// 	if(rem_k == 0) {
// 		return 0;
// 	}

// 	int &ans = dp[rem_k][node];
// 	if(ans != -1) {
// 		return ans;
// 	}

// 	ans = 0;
// 	for(auto it: adj[node]) {
// 		ans = mod_add(ans, go(it, rem_k - 1), MOD);
// 	}

// 	return ans;
// }


// void yash()
// {
//   cin >> n >> m;
//   adj.resize(n + 1);

//   for(int i = 0; i < m; i++) {
//   	char c;
//   	int u, v;
//   	cin >> c >> u >> v;
//   	if(c == 'D') {
//   		adj[u].push_back(v);
//   	} else {
//   		adj[u].push_back(v);
//   		adj[v].push_back(u);
//   	}
//   } 

//   cin >> n1 >> n2;

//   memset(dp, -1, sizeof(dp));

//   int q;
//   cin >> q;
//   while(q--) {
//   	int k;
//   	cin >> k;

//   	int ans = go(n1, k);
//   	cout << ans << '\n';
//   }

// }

// signed main()
// {
//   init_code();
//   ios_base::sync_with_stdio(false);
//   cin.tie(0);
//   cout.tie(0);
//   // test
//   yash();
//   return 0;
// }

//YashS
// https://www.hackerrank.com/contests/the-return-of-ab-yeh-kar-ke-dikhao/challenges/subsetsum-1
/*
10 15 1551
1456 1742 897 1143 580 440 271 12 352 459
*/

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
  int n, ll, rr;
  cin >> n >> ll >> rr; 
  vector<int> v(n);
  for(int i = 0; i < n; i++) {
  	cin >> v[i];
  }

  vector<int> a, b;
  for(int i = 0; i < n / 2; i++) {
  	a.push_back(v[i]);
  }
  for(int i = n / 2; i < n; i++) {
  	b.push_back(v[i]);
  }

  // pVec(a);
  // pVec(b);

  int p = a.size();
  int q = b.size();
  vector<int> A, B;

  for(int mask = 0 ; mask < (1<<p); mask++) {
    int sum = 0;
    for (int i = 0; i < p; i++) if (mask >> i & 1) sum += a[i];
    A.push_back(sum);
  }

  for(int mask = 0 ; mask < (1<<q); mask++) {
    int sum = 0;
    for (int i = 0; i < q; i++) if (mask >> i & 1) sum += b[i];
    B.push_back(sum);
  }


  sort(B.begin(), B.end());
  sort(A.begin(), A.end());

  // pVec(A);
  // pVec(B);

  int ans = 0;
  for(auto it: A) {
  	int num = it;
  	int l1 = ll - num, r1 = rr - num;
  	int l = 0, r = B.size() - 1;

  	int idx1 = -1, idx2 = -1;

  	while (l <= r) {
  		int mid = (l + r) / 2;

  		if(B[mid] >= l1) {
  			idx1 = mid;
  			r = mid - 1;
  		}
  		else {
  			l = mid + 1;
  		}

  	}

  	l = 0, r = B.size() - 1;
  	while (l <= r) {
  		int mid = (l + r) / 2;

  		if(B[mid] <= r1) {
  			idx2 = mid;
  			l = mid + 1;
  		}
  		else {
  			r = mid - 1;
  		}
  	}

  	if(idx2 < idx1) {
  		continue;
  	}
  	if(idx1 == idx2 && idx1 == -1)continue;

  	// cout << it << " " << idx1 << " " << idx2 << "\n";
  	ans += (idx2 - idx1 + 1);
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