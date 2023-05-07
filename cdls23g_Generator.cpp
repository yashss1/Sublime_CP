#include <bits/stdc++.h>
using namespace std;

#define N 100000
#define Q 8
#define X 1000000000
#define K 10
#define T 10

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main()
{
	init_code();

	for (int tc = 20; tc <= 20; tc++) {
		string infile = to_string(tc) + ".in";
		string outfile = to_string(tc) + ".in";
		freopen(infile.c_str(), "r", stdin);
		freopen(outfile.c_str(), "w", stdout);
		// 	int t;
		// 	cin >> t;
		// 	cout << t;
		// }

		long long int t = rand() % T + 1; //Generate a random number between 1 and T.
		t = 10000;
		cout << t << endl;
		for (int tc = 0; tc < t; tc++)
		{
			long long int n = rand() % (N) + 1;
			n = 100;

			vector<vector<int>> v;
			for (int i = 0; i < n; i++)
			{
				long long int k = rand() % (N) + 1;
				k = 1;
				vector<int> temp;
				// temp.push_back(1e9);
				// temp.push_back(-1e9);
				for (int j = 0; j < k; j++) {
					long long int x = rand() % (X) + 1;
					x = 1e9;
					if (i % 2 == 0) {
					}
					else {
						x *= (-1);
					}
					temp.push_back(x);
				}
				v.push_back(temp);
			}


			cout << n << "\n";
			for (auto it : v) {
				cout << it.size() << " ";
				for (auto it1 : it) {
					cout << it1 << " ";
				}
				cout << '\n';
			}
		}
	}
}