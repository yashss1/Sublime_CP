// DP with Bitmask
// https://codeforces.com/contest/16/problem/E

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
const int N = 19;
void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n;
vector<vector<double>> v(N, vector<double>(N));
double dp[N][(1 << N)];

// 11101 -> 2nd fist is alive till end

double go(int mask, int curr_winner) {

	if((1 << curr_winner) & mask) {  	
		// killed the winner
		return 0;
	}

	if (mask == (((1 << n) - 1) ^ (1 << curr_winner))) { 
		// only winner is set to 0, else are 1
		return 1;
	}

	double &ans = dp[curr_winner][mask];
	if(ans > -1) {
		return ans;
	}

	double lose_probability[n];
	memset(lose_probability, 0.0, sizeof(lose_probability));

	int total_alive_here = 0;

	// this match is between fish1 & fish2
	for (int fish1 = 0; fish1 < n; fish1++) {
		if(((1 << fish1) & mask) == 0) {
			// fist1 alive
			for (int fish2 = 0; fish2 < fish1; fish2++) {
				if(((1 << fish2) & mask) == 0) {
					// fish2 alive
					lose_probability[fish1] += v[fish2][fish1];
					lose_probability[fish2] += v[fish1][fish2];
					total_alive_here++;
				}
			} 
		}
	}


	ans = 0;
	for(int fish = 0; fish < n; fish++) {
		if(((1 << fish) & mask) == 0) {
			// suppose this fish dies here
			ans += ((lose_probability[fish]) * go(mask ^ (1 << fish), curr_winner));
		}
	}
	ans /= total_alive_here;
 

	return ans;
}

void yash()
{
	cin >> n;
	rep(i, 0, n) {
		rep(j, 0, n) {
			cin >> v[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	
	for(int i = 0; i < n; i++) {
		cout << fixed << setprecision(6) << go(0, i) << " ";
	}
	cout << "\n";

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