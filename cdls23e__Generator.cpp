#include <bits/stdc++.h>
using namespace std;

#define N 100000
#define Q 8
#define X 10023
#define K 10
#define T 10

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("3.in", "w", stdout);
#endif // ONLINE_JUDGE
}

int main()
{
	// init_code();

	for (int tc = 18; tc <= 20; tc++) {
		string infile = to_string(tc) + ".in";
		string outfile = to_string(tc) + ".in";
		freopen(infile.c_str(), "r", stdin);
		freopen(outfile.c_str(), "w", stdout);
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

			vector<int> v;
			for (int i = 0; i < n; i++)
			{
				v.push_back(i + 1);
			}

			long long int x = rand() % (N) + 1;
			unsigned seed = x;
			shuffle(v.begin(), v.end(), default_random_engine(seed));

			// sort(v.begin(), v.end());
			// reverse(v.begin(), v.end());

			cout << n << "\n";
			for (auto it : v) {
				cout << it << " ";
			} cout << '\n';
		}
	}
}