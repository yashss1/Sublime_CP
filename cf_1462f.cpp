//YashS
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace std;
using namespace __gnu_pbds;

#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
int MOD = 1e9 + 7;
int N = 1e5 + 7;

// This less<int> is comparatar (Replace greater<int> for descending)
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

void yash()
{
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	pbds B;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		v.push_back({l, r});
	}

	// for curr i,
	// ans = total - {(left -> count of all r smaller than currL)
	// + (right -> count of all l greater than currR)}

	sort(all(v));
	vector<int> pref(n, 0), suff(n, 0);

	pbds A;
	for (int i = 0; i < n; i++) {
		int smallR = A.order_of_key(v[i].first);
		pref[i] = smallR;
		A.insert(v[i].second);
	}

	for (int i = n - 1; i >= 0; i--) {
		int bigL = B.order_of_key(v[i].second * -1);
		suff[i] = bigL;
		B.insert(v[i].first * -1);
	}

	int ans = n - 1;
	for (int i = 0; i < n; i++) {
		int leftOut = pref[i] + suff[i];
		ans = min(ans, leftOut);
	}

// 		for(int i = 0; i < n; i++) {
// 		    cout << i << " -> " << pref[i] << " " << suff[i] << "\n";
// 		}

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