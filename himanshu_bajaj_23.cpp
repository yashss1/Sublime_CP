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
Given n, do sum of digits of 2^N, and then do the sum of sum again, till the sum is single digit
print that single digit

6 -> 2^6 = 64 = 6 + 4 = 10 = 1 + 0 = 1
11 -> 5
*/

void yash()
{
	int n;
	cin >> n;

	int t = (n % 6);
	if (t == 0) {
		cout << "1\n";
	}
	else if (t == 1) {
		cout << "2\n";
	}
	else if (t == 2) {
		cout << "4\n";
	}
	else if (t == 3) {
		cout << "8\n";
	}
	else if (t == 4) {
		cout << "7\n";
	}
	else {
		cout << "5\n";
	}

	return;

	// pattern
	for (int i = 0; i < 100; i++) {
		int temp = pow(2, i);
		string s;
		while (1) {
			s = to_string(temp);
			if (s.size() == 1) {
				break;
			}
			int curr = 0;
			for (int i = 0; i < s.size(); i++) {
				curr += (s[i] - '0');
			}
			temp = curr;
		}

		cout << (i % 6) << " " << s << '\n';
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