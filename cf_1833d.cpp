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
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	// if (idx == 0) {
	// 	cout << "THIS\n";
	// 	return;
	// }


	// vector<int> temp, tempp[2];
	// for (int i = 0; i < idx; i++) {
	// 	tempp[0].push_back(v[i]);
	// }
	// for (int i = idx; i < n; i++) {
	// 	temp.push_back(v[i]);
	// }

	// tempp[1] = tempp[0];
	// reverse(all(tempp[0]));

	// pVec(tempp[0]); cout << '\n';

	// int flag = 0;
	// for (int i = 0; i < tempp[0].size(); i++) {
	// 	if (tempp[0][i] > tempp[1][i]) {
	// 		flag = 0;
	// 		break;
	// 	}
	// 	if (tempp[0][i] < tempp[1][i]) {
	// 		flag = 1;
	// 		break;
	// 	}
	// }

	// pVec(temp);
	// pVec(tempp[flag]);
	// cout << "\n";

	vector<int> ans;
	ans = v;
	reverse(all(ans));

	for (int i = 1; i < n; i++) {
		vector<int> temp1, temp2;
		for (int j = 0; j < i; j++) {
			temp1.push_back(v[j]);
		}
		for (int j = i; j < n; j++) {
			temp2.push_back(v[j]);
		}

		// pVec(temp1);
		// pVec(temp2); cout << "->\n";


		vector<int> tempp[2], tem[2], temm[2];
		tempp[0] = temp2;
		tempp[1] = temp1;
		reverse(all(tempp[0]));

		tem[0] = temp2;
		tem[1] = temp1;
		reverse(all(tem[1]));

		temm[0] = temp2;
		temm[1] = temp1;
		int num = temm[1][temm[1].size() - 1];
		temm[1].pop_back();
		// pVec(temp1);
		// pVec(temp2);
		// cout << '\n';
		// int flag = 0;
		vector<int> a, b, c;
		a = tempp[0];
		for (int j = 0; j < tempp[1].size(); j++) {
			a.push_back(tempp[1][j]);
		}

		b = (tem[0]);
		for (int j = 0; j < tem[1].size(); j++) {
			b.push_back(tem[1][j]);
		}

		c = (temm[0]);
		c.push_back(num);
		for (int j = 0; j < temm[1].size(); j++) {
			c.push_back(temm[1][j]);
		}

		// pVec(a);
		// pVec(b);
		// cout << "\n";

		int flag = 0;
		for (int j = 0; j < n; j++) {
			if (a[j] > b[j]) {
				flag = 0;
				break;
			}
			if (a[j] < b[j]) {
				flag = 1;
				break;
			}
		}


		if (flag == 0) {
			int flag1 = 0;
			for (int j = 0; j < n; j++) {
				if (a[j] > c[j]) {
					flag1 = 0;
					break;
				}
				if (a[j] < c[j]) {
					flag1 = 1;
					break;
				}
			}
			if (flag1 == 1) {
				a = c;
			}
		} else {
			int flag1 = 0;
			for (int j = 0; j < n; j++) {
				if (b[j] > c[j]) {
					flag1 = 0;
					break;
				}
				if (b[j] < c[j]) {
					flag1 = 1;
					break;
				}
			}
			if (flag1 == 1) {
				b = c;
			}
		}

		if (flag == 0) {
			int flag1 = 0;
			for (int j = 0; j < n; j++) {
				if (a[j] > ans[j]) {
					flag1 = 0;
					break;
				}
				if (a[j] < ans[j]) {
					flag1 = 1;
					break;
				}
			}
			if (flag1 == 0) {
				ans = a;
			}
		}
		else {
			int flag1 = 0;
			for (int j = 0; j < n; j++) {
				if (ans[j] > b[j]) {
					flag1 = 0;
					break;
				}
				if (ans[j] < b[j]) {
					flag1 = 1;
					break;
				}
			}
			if (flag1 == 1) {
				ans = b;
			}
		}
	}
	pVec(ans);
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