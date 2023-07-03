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

/*
4
3
2 4 6
1 1 1
5
16 7 3 4 11
7 5 6 13 12
7
17 18 18 20 20 4 6
19 9 12 15 7 17 12
5
20 3 14 13 10
3 15 4 19 13
*/

vector<int> bpf(N, 0);
void BPF() {
	bpf[1] = 1;
	for (int i = 2; i <= N; i++) {
		if (!bpf[i]) {
			for (int j = i; j <= N; j += i) {
				bpf[j] = i;
			}
		}
	}
}

void yash()
{
	BPF();
	int n;
	cin >> n;
	vector<int> v(n), cost(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int t = v[i], curr = 0;
		while (t) {
			curr++;
			if (t == bpf[t]) {
				break;
			}
			t = bpf[t];
		}
		ans += curr;
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