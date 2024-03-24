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
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		pq.push(v[i]);
	}

	int flag = 0;

	vector<int> remainder;
	while (!pq.empty()) {
		int top = pq.top();
		if (top <= 0) {
			break;
		}
		pq.pop();
		for (auto it : remainder) {
			pq.push(it);
		} remainder.clear();

		top--;
		flag ^= 1;
		if (top > 0) {
			remainder.push_back(top);
		}
	}
	for (auto it : remainder) {
		pq.push(it);
	}

	vector<int> final;
	while (!pq.empty()) {
		final.push_back(pq.top());
		pq.pop();
	}
	// pVec(final);

	if (flag) {
		cout << "T\n";
		return;
	}
	cout << "HL\n";
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