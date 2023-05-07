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
const int N = 1e5 + 7;

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

void yash()
{
	int n, m;
	cin >> n >> m;
	if (n == 1 || m == 1) {
		cout << "YES\n";
		return;
	}
	int ans = spf[n];
	if (ans > m) {
		cout << "YES\n";
		return;
	}
	cout << "NO\n";


}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	SPF();
	test
	yash();
	return 0;
}