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

#define PII pair<int, int>
class Compare {
public:
	bool operator()(PII below, PII above)
	{
		if (below.first < above.first) {
			return true;
		}
		else if (below.first == above.first
		         && below.second > above.second) {
			return true;
		}

		return false;
	}
};

void yash()
{
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	priority_queue<PII, vector<PII>, Compare> pq;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		pq.push({v[i], i});
	}

	vector<int> ans;
	while (!pq.empty()) {
		pair<int, int> it = pq.top(), it2;
		pq.pop();
		// cout << it.first << " " << it.second << '\n';
		if (!pq.empty()) {
			it2 = pq.top();
			int diff = it.first - it2.first;
			int t = diff / k;
			if (t == 0) t++;
			if (it.first - (t * k) > it2.first) {
				t++;
			}
			int rem = (it.first - (t * k));
			if (rem > 0) {
				pq.push({rem, it.second});
			} else {
				ans.push_back(it.second + 1);
			}
		}
		else {
			ans.push_back(it.second + 1);
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