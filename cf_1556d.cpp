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
int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int askOR(int a, int b) {
	cout << "or " << a << " " << b << endl;
	int n;
	cin >> n;
	return n;
}
int askAND(int a, int b) {
	cout << "and " << a << " " << b << endl;
	int n;
	cin >> n;
	return n;
}
void answer(int n) {
	cout << "finish " << n << endl;
}

void yash()
{
	int n, k;
	cin >> n >> k;

	vector<int> ans(n, 0);
	int x = askOR(1, 2) + askAND(1, 2);
	int y = askOR(2, 3) + askAND(2, 3);
	int z = askOR(1, 3) + askAND(1, 3);

	int a = ((x - y) + z) / 2;
	int b = (x - a);
	int c = (z - a);

	ans[0] = a, ans[1] = b, ans[2] = c;

	for (int i = 3; i < n; i++) {
		ans[i] = askOR(1, i + 1) + askAND(1, i + 1) - ans[0];
	}

	sort(ans.begin(), ans.end());

	answer(ans[k - 1]);
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