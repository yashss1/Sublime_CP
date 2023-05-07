#include <bits/stdc++.h>
using namespace std;

#define N 1000
#define Q 1000
#define X 10023
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
	// init_code();

	// for (int tc = 3; tc <= 4; tc++) {
	// 	string infile = "input" + to_string(tc) + ".txt";
	// 	string outfile = "input" + to_string(tc) + ".txt";
	// 	freopen(infile.c_str(), "r", stdin);
	// 	freopen(outfile.c_str(), "w", stdout);
	// 	int t;
	// 	cin >> t;
	// 	cout << t;
	// }
	srand(time(0));
	long long int t = rand() % T + 1; //Generate a random number between 1 and T.
	t = 1;
	// cout << t << endl;
	for (int tc = 0; tc < t; tc++)
	{
		long long int n = rand() % (N) + 1;
		long long int q = rand() % (Q) + 1;

		// n = 1000;
		// q = 1000;
		cout << n << " " << q << "\n";
		for (int i = 0; i < q; i++)
		{
			long long int l = rand() % (n) + 1;
			long long int r = rand() % (n - l + 1) + l;
			// l = 1, r = 1000;
			cout << l << " " << r << '\n';
		}
	}
	// }
}