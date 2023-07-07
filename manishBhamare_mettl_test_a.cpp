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
4
4 3
10000 1000 100 10
4 12
20 30 70 90
4 12
20 30 70 50
4 900
20 30 70 90

-> 10 150 100 10140
*/

void yash()
{
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<pair<double, int>> temp;
	for (int i = 0; i < n; i++) {
		int t = pow(2, i);
		temp.push_back({v[i] / (float)t, i});
	}

	vector<int> mnVector(n, temp[0].second);
	double mn = temp[0].first;
	for (int i = 1; i < n; i++) {
		if (temp[i].first < mn) {
			mn = temp[i].first;
			mnVector[i] = temp[i].second;
		}
		else {
			mnVector[i] = mnVector[i - 1];
		}
	}

	int ans = 0, res = INT_MAX, pw = n - 1;
	while (m > 0) {
		int t = pow(2ll, pw), fl = 0;
		if (t <= m) {
			int currMinPow = mnVector[pw];
			int multiples = (m / pow(2ll, currMinPow));
			m -= (multiples * pow(2ll, currMinPow));
			ans += (v[currMinPow] * multiples);
		} else {
			pw--;
			fl = 1;
		}


		if (m > 0) {
			res = min(res, ans + (v[mnVector[pw + fl]]));
		}
	}

	cout << min(res, ans) << '\n';
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

/*
Brute by Naman

int n, m;
vector<int> a;
int go(int ind, int cur) {
    if (cur >= m) {
        return 0;
    }
    if (ind < 0) {
        return 100000000;
    }
    int ans = 10000000;
    int c1 = go(ind - 1, cur);
    for (int i = 1; i <= (cur / (1 << ind)) + 1000; i++) {
        int c2 = i * a[ind] + go(ind - 1, cur + (1 << ind) * i);
        ans = min(ans, c2);
    }
    return min(ans, c1);
}

void yash()
{
    cin >> n >> m;
    a.clear();
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    cout << go(n - 1, 0) << endl;
}
*/