#include <bits/stdc++.h>
using namespace std;

#define N 20
#define K 10
#define T 5
#define X 100

// Generator for Tree

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("inputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

void shuffleVector(vector<pair<long long, long long>> &v) {
	auto rng = std::default_random_engine {};
	std::shuffle(std::begin(v), std::end(v), rng);
}

int main()
{
	init_code();

	srand(time(0));					  //IMPPPP....
	long long int t = rand() % T + 1; //Generate a random number between 1 and T.
	t = 1;
	// cout << t << endl;
	for (int tc = 0; tc < t; tc++)
	{
		long long int n = rand() % (N) + 2;
		vector<long long int> v;
		for (long long i = 0; i < n; i++) {
			long long int x = rand() % (X) + 1;
			v.push_back(x);
		}

		vector<pair<long long, long long>> res;
		for (long long i = 2; i <= n; ++i) {
			res.push_back({(int)(rand() % (i - 1) + 1), i});
		}
		shuffleVector(res);

		// randomize root
		long long int randomIncrementor = rand() % (n);
		for (auto &it : res) {
			it.first += randomIncrementor;
			it.second += randomIncrementor;
			it.first %= n;
			it.second %= n;
			if (it.first == 0) it.first = n;
			if (it.second == 0) it.second = n;
		}

		cout << n << '\n';
		for (auto it : v) {
			cout << it << " ";
		} cout << '\n';
		for (auto it : res) {
			cout << it.first << " " << it.second << "\n";
		}
	}
}