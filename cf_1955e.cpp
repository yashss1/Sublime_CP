//YashS
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key


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
	int n;
	cin >> n;
	string s;
	cin >> s;


	int ans = 1;
	for (int k = 1; k <= n; k++) {
		pbds A;
		int flag = 1;
		for (int i = 0; i < n; i++) {
			int temp = A.size() - A.order_of_key((i - k + 1));

			if (s[i] == '0') {
				if (temp % 2 == 0) {
					A.insert(i);
				}
			}
			else {
				if (temp % 2 != 0) {
					A.insert(i);
				}
			}

			if (i + k >= n) {
				for (int j = i + 1; j < n; j++) {
					int temp = A.size() - A.order_of_key((j - k + 1));
					if ((s[j] == '0' && temp % 2 == 0) || (s[j] == '1' && temp % 2 == 1)) {
						flag = 0;
					}
				}
				break;
			}
		}
		if (flag == 1) {
			ans = max(ans, k);
		}
	}
	cout << ans << '\n';
}

signed main()
{
// 	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	test
	yash();
	return 0;
}