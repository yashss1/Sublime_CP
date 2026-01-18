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

/*
2
3
2 6 4
3
3 3 6

Yes
No
*/

void yash()
{
	int n;
	cin >> n;
	vector<int> v(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}

	int flag = 1;

	if (sum % n != 0) {
		flag = 0;
	}

	int t = sum / n;

	vector<int> donar, receiver;
	for (int i = 0; i < n; i++) {
		if (v[i] > t) {
			int x = v[i] - t;
			donar.push_back(x);
			if ((x & (~(x - 1))) != x) {
				flag = 0;
			}
		} else if (v[i] < t) {
			int x = t - v[i];
			receiver.push_back(x);
			if ((x & (~(x - 1))) != x) {
				flag = 0;
			}
		}
	}

	sort(donar.begin(), donar.end());
	sort(receiver.begin(), receiver.end());



	if (flag == 1 && (donar == receiver)) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
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