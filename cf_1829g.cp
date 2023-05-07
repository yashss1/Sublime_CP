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
const int N = 1e6 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int n;
vector<int> sizes;
vector<int> valOfRow(N, 0);

void precompute() {
	int temp = 0, sz = 1;
	while (temp < N) {
		temp += sz;
		sizes.pb(temp);
		sz++;
	}

	for (int i = 1; i <= N; i++) {
		valOfRow[i] += (i * i) + valOfRow[i - 1];
	}
}

int go(int idx, int l, int r) {
	if (l == 0) l += 1;

	int res = (valOfRow[r] - valOfRow[l - 1]);

	if (idx == 0)
		return res;

	int x = min((r - idx), sizes[idx - 1]);
	int y = max((l - 1 - idx), sizes[idx - 1] - idx + 1);
	int ans = go(idx - 1, y, x);

	return ans + res;
}


void yash()
{
	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < sizes.size(); i++) {
		if (sizes[i] < n) {
			res++;
			continue;
		}
		break;
	}

	int ans = go(res, n, n);
	cout << ans << "\n";
}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	precompute();
	test
	yash();
	return 0;
}