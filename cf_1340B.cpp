//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<"";cout<<"\n"
const int MOD = 1e9 + 7;
const int N = 2e3 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n, K;
vector<string> v(N);
unordered_map<int, string> mp;
unordered_map<string, int> mpp;

int dp[N][N];

int go(int idx, int k) {
	if(idx == n) {
		return k == 0;
	}

	int &ans = dp[idx][k];
	if(ans != -1) {
		return ans;
	}

	ans = 0;
	for(int i = 9; i >= 0; i--) {
		string a = v[idx];
		string b = mp[i];

		int curr = 0, flag = 1;
		for(int j = 0; j < a.size(); j++) {
			if(a[j] == b[j]) continue;
			if(a[j] == '1' && b[j] == '0') {
				flag = 0;
				break;
			}
			if(a[j] == '0' && b[j] == '1') {
				curr++;
			}
		}

		if(curr <= k && flag == 1) {
			ans |= go(idx + 1, k - curr);
		}else {
			if(v[idx] != mp[i]) {
				continue;
			}
			ans |= go(idx + 1, k);
		}
	}

	return ans;
}

vector<int> res;
void trace(int idx, int k) {
	if(idx == n) {
		return;
	}

	int ans = dp[idx][k];

	int curr_ans = 0;
	for(int i = 9; i >= 0; i--) {
		string a = v[idx];
		string b = mp[i];

		int curr = 0, flag = 1;
		for(int j = 0; j < a.size(); j++) {
			if(a[j] == b[j]) continue;
			if(a[j] == '1' && b[j] == '0') {
				flag = 0;
				break;
			}
			if(a[j] == '0' && b[j] == '1') {
				curr++;
			}
		}

		if(curr <= k && flag == 1) {
			curr_ans |= go(idx + 1, k - curr);
			if(curr_ans == ans) {
				res.push_back(i);
				trace(idx + 1, k - curr);
				return;
			}
		}else {
			if(v[idx] != mp[i]) {
				continue;
			}
			curr_ans |= go(idx + 1, k);
			if(curr_ans == ans) {
				res.push_back(i);
				trace(idx + 1, k);
				return;
			}
		}
	}
}

void yash()
{
  cin >> n >> K;
  memset(dp, -1, sizeof(dp));
  for(int i = 0; i < n; i++) {
  	cin >> v[i];
  } 
  mp[0] = "1110111", mp[1] = "0010010", mp[2] = "1011101", mp[3] = "1011011", mp[4] = "0111010", mp[5] = "1101011", mp[6] = "1101111", mp[7] = "1010010", mp[8] = "1111111", mp[9] = "1111011";
  for(int i = 0; i <= 9; i++) {
  	mpp[mp[i]] = 1;
  }

  int ans = go(0, K);
  if(!ans) {
  	cout << "-1\n";
  	return;
  }

  trace(0, K);
  
  if(res.size() != n) {
  	cout << "-1\n";return;
  }

  pVec(res);
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