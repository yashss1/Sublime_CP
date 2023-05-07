#include <bits/stdc++.h>
using namespace std;

#define N 100000
#define Q 8
#define X 10
#define K 10
#define T 10

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("inputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main()
{
	init_code();

	// for (int i = 18; i <= 19; i++) {
	// 	string infile = to_string(i) + ".in";
	// 	string outfile = to_string(i) + ".in";
	// 	freopen(infile.c_str(), "r", stdin);
	// 	freopen(outfile.c_str(), "w", stdout);
	// 	int t;
	// 	cin >> t;
	// 	cout << t;
	// }

	long long int t = rand() % T + 1; //Generate a random number between 1 and T.
	t = 1;
	// cout << t << endl;
	for (int tc = 0; tc < t; tc++)
	{
		long long int n = rand() % (N) + 1;
		n = 6;

		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			long long int x = rand() % (X) + 1;
			long long t = rand() % (X) + 1;
			if (t % 2) {
				x *= -1;
			}
			v.push_back(x);
		}

		cout << n << "\n";
		for (auto it : v) {
			cout << it << " ";
		} cout << '\n';
		long long int q = rand() % (Q) + 1;
		q = 2;
		cout << q << '\n';
		for (int i = 0; i < q; i++) {
			long long int x = rand() % (n) + 1;
			cout << x << "\n";
		}
	}
	// }
}