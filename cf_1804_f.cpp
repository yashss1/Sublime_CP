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
const int N = 26000;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n, m, a, b, p, q;
int ans = -1;
int P = 50001;
int t1 = 1;
int flag = 0;

void dfs(int i, int j, int dir, int t) {
	// cout << i << " " << j << '\n';
	// return;
	if(i == p && j == q) {
		t1 = 0;
		return;
	}
	if(t == 0){
		flag = 1;
		t1 = 0;
		return;
	}
	if(i == n || j == m || i == 0 || j == 0) {
		if(dir == 0) {
			if(i < n && j > 0) {
				goto end;
			}
		}
		if(dir == 1) {
			if(i > 0 && j > 0) {
				goto end;
			}
		}
		if(dir == 2) {
			if(i > 0 && j < m) {
				goto end;
			}
		}
		if(dir == 3) {
			if(i < n && j < m) {
				goto end;
			}
		}
		string temp = "";
		if(i == n) {
			temp += "U";
		}
		if(i == 0) {
			temp += "D";
		}
		if(j == m) {
			temp += "L";
		}
		if(j == 0) {
			temp += "R";
		}
		ans++;
		if(temp == "D") {
			dfs(i, j, (dir == 2 ? 3 : 0), t - 1);
			if(t1 == 0) return;
		}
		if(temp == "L") {
			dfs(i, j, (dir == 2 ? 1 : 0), t - 1);
			if(t1 == 0) return;
		}
		if(temp == "U") {
			dfs(i, j, (dir == 3 ? 2 : 1), t - 1);
			if(t1 == 0) return;
		}
		if(temp == "R") {
			dfs(i, j, (dir == 1 ? 2 : 3), t - 1);
			if(t1 == 0) return;
		}
		if(temp == "DL") {
			dfs(i, j, 0, t - 1);
			if(t1 == 0) return;
		}
		if(temp == "UL") {
			dfs(i, j, 1, t - 1);
			if(t1 == 0) return;
		}
		if(temp == "UR") {
			dfs(i, j, 2, t - 1);
			if(t1 == 0) return;
		}
		if(temp == "DR") {
			dfs(i, j, 3, t - 1);
			if(t1 == 0) return;
		}
	}

	end:

	if(dir == 0) {
		dfs(i + 1, j - 1, dir, t - 1);
		if(t1 == 0) return;
	}
	if(dir == 1) {
		dfs(i - 1, j - 1, dir, t - 1);
		if(t1 == 0) return;
	}
	if(dir == 2) {
		dfs(i - 1, j + 1, dir, t - 1);
		if(t1 == 0) return;
	}
	if(dir == 3) {
		dfs(i + 1, j + 1, dir, t - 1);
		if(t1 == 0) return;
	}


}

void yash()
{
  cin >> n >> m >> a >> b >> p >> q;
  // for(int i = 0; i < n + 2; i++) {
  // 	for(int j = 0; j < m + 2; j++) {
  // 		v[i][j] = -1;
  // 	}
  // }

  string s;
  cin >> s;


  ans = 0;
  int i = a, j = b;

  int dir = 0;
  if(s == "DL") {
	dir = 0;
  }
  if(s == "UL") {
	dir = 1;
  }
  if(s == "UR") {
	dir = 2;
  }
  if(s == "DR") {
	dir = 3;
  }

  dfs(i, j, dir, P);
  if(flag == 1) {
  	cout << "-1\n";return;
  }
  cout << ans << '\n';
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