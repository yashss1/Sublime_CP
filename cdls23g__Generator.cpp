//YashS
#include <bits/stdc++.h>
using namespace std;

#define N 100
#define K 1000
#define T 10
#define X 1000

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main()
{
	//init_code();
	srand(time(0));					  //IMPPPP....

	long long int t = rand() % T + 1; //Generate a random number between 1 and T.
	cout << t << endl;
	// t = 1;
	for (int tc = 0; tc < t; tc++)
	{
		long long int n = (rand() % (N)) + 1; // 1 to N
		cout << n << '\n';

		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			long long int x = (rand() % (X)) + 1;
			v[i] = x;
		}

		for (auto it : v) {
			cout << it << " ";
		} cout << '\n';
	}
}