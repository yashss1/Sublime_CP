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

void yash()
{
	int n = 100;
	int *p = &n;
	int *q = p;
	p++;
	*p = 102;
	int **pp = &p;

	cout << (p) << "\n";
	cout << (&n) << "\n";

	cout << (pp) << "\n";
	cout << (&p) << '\n';

	cout << (*(*(&p))) << '\n';

	cout << "\n";
	int *arr = (int *) malloc(sizeof(int) * 1);
	for (int i = 0; i < 6; i++) {
		// cin >> arr[i];
		cout << q[i] << '\n';
	}
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