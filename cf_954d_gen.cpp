#include <bits/stdc++.h>
using namespace std;

#define N 100
#define K 100
#define T 5
#define X 100

// Generator for Graphs

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("inputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main()
{
	// init_code();

	srand(time(0));					  //IMPPPP....
	long long int t = rand() % T + 1; //Generate a random number between 1 and T.
	t = 1;
	// cout << t << endl;
	for (int tc = 0; tc < t; tc++)
	{
		long long int n = rand() % (N) + 1;
		long long int m = rand() % ((n * (n - 1) / 2)) + 1;
		long long int s = rand() % (n) + 1;
		long long int t = rand() % (n) + 1;

		map<pair<int, int>, int> mp;

		vector<pair<int, int>> res;
		for (int i = 0; i < m; i++)
		{

			long long int u = rand() % (n) + 1;
			long long int v = rand() % (n) + 1;
			if (u == v) {
				u++;
				continue;
			}

			if (u > v) swap(u, v);
			if (mp[ {u, v}] == 1) {
				i--;
				continue;
			}
			mp[ {u, v}] = 1;
			res.push_back({u, v});
		}

		cout << n << ' ' <<  m << ' ' << s << ' ' << t << '\n';
		for (auto it : res) {
			cout << it.first << " " << it.second << "\n";
		}
	}
}