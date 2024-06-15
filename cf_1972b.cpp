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
	string s;
	cin >> s;
	int ans = 0;
	for (auto it : s) {
		if (it == 'U')ans++;
	}
	if (ans % 2 == 0) {
		cout << "No\n";
		return;
	}
	cout << "Yes\n";
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

int n, k;
vector<int> v;

int solve(int K) {
	int want = 0;
	for (int i = 0; i < n; i++) {
		want += max(0ll, K - v[i]);
	}
	if (want <= k) {
		return (k - want);
	}
	return -1;
}

void yash()
{

	cin >> n >> k;
	v.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int l = 0, r = 1e12, ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		int temp = solve(mid);
		if (temp != -1) {
			ans = (mid * n) - (n - 1);
			int curr = 0;
			priority_queue<int> pq;
			// cout << "T : " << temp << '\n';

			vector<int> tempp;
			for (int i = 0; i < n; i++) {
				tempp.push_back(v[i] - mid);
				pq.push(v[i] - mid);
			}
			// pVec(tempp);

			for (int i = n - 1; i >= 0; i--) {
				if (tempp[i] < 0 && temp > 0) {
					temp--;
				}
				curr++;
				if (temp <= 0) {
					for (int j = 0; j < i; j++) {
						if (tempp[j] > 0) {
							curr++;
						}
					}
					break;
				}
			}



			// while (!pq.empty()) {
			//     int top = pq.top();
			//     pq.pop();
			//     if (top > 0) curr++;
			//     else {
			//         if (top == 0) {
			//             if (temp - 1 < 0) {
			//                 break;
			//             }
			//             temp--;
			//             curr++;
			//         } else {
			//             if (temp + top < 0) {
			//                 break;
			//             }
			//             temp += top;
			//             curr++;
			//         }
			//     }
			// }
			// cout << mid << " " << ans << " " << curr << '\n';
			ans += curr;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
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