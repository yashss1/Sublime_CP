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


void solve() {
	static int a = 10;
	a++;

	cout << a << '\n';
}

// use of static in class
class suyog {
public:
	static int z;
};
int suyog::z = 0;



void yash()
{
	solve();
	// solve();
	// solve();
	// solve();
	// solve();
	// solve();
	// solve();
	// solve();

	// a++;
	// cout << a << '\n';

	// cout << z << '\n';
	int b = ++++suyog::z;
	cout << b << '\n';

}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// test
	yash();
	return 0;
}