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
const int N = 5e6 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int spf[N + 1]; //Can go upto N = 1e7
void SPF() {
	spf[1] = 1;
	rep(i, 2, N) if (!spf[i]) for (int j = i; j <= N; j += i) if (!spf[j]) spf[j] = i;
}

int answer(int n) {
	int ans = 0;
	while (n > 1) {
		int t = spf[n];
		ans++;
		n /= t;
	}
	return ans;
}

vector<int> pref(N, 0);
void yash()
{
	int a, b;
	cin >> a >> b;
	int ans = pref[a] - pref[b];


	cout << ans << '\n';
}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	SPF();
	for (int i = 1; i < N; i++) {
		int num = i;
		pref[i] = pref[i - 1] + answer(num);
	}
	test
	yash();
	return 0;
}