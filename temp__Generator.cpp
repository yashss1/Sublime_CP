#include <bits/stdc++.h>
using namespace std;

#define N 500
#define K 100000
#define T 5
#define X 10000000

// Chef and Negative Arrays

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("as", "r", stdin);
	freopen("inputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main()
{
	init_code();

	srand(time(0));					  //IMPPPP....
	long long int t = rand() % T + 1; //Generate a random number between 1 and T.
	// cout << t << endl;
	t = 1;
	for (int tc = 0; tc < t; tc++)
	{
		long long int n = rand() % (N) + 1;

		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			long long int x = rand() % (X) + 1;
			v.push_back(x);
		}

		cout << n << "\n";
		for (auto it : v) {
			cout << it << " ";
		} cout << '\n';

		long long int k = rand() % (K) + 1;
		if (1) {
			k = rand() % (n) + n;
		}
		cout << k << '\n';
	}
}