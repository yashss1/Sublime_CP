#include <bits/stdc++.h>
using namespace std;

#define N 1000
#define K 1000
#define T 5
#define X 100000000

// Chef and Negative Arrays

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("33.in", "w", stdout);
#endif // ONLINE_JUDGE
}

int main()
{
	init_code();

	srand(time(0));					  //IMPPPP....
	long long int t = rand() % T + 1; //Generate a random number between 1 and T.
	cout << t << endl;
	for (int tc = 0; tc < t; tc++)
	{
		long long int n = rand() % (N) + 1;
		n = 1000;

		vector<vector<int>> v;
		for (int i = 0; i < n; i++)
		{
			long long int k = rand() % (K) + 1;
			vector<int> temp;
			map<int, int> mp;
			k = 1000;
			for (int j = 0; j < k; j++)
			{
				long long int x = (rand() % X);
				long long int x1 = (rand() % X);
				x -= x1;
				if (mp[x]) {
					j--;
					continue;
				}
				mp[x] = 1;
				temp.push_back(x);
			}
			v.push_back(temp);
		}

		cout << n << "\n";
		for (int i = 0; i < n; i++) {
			cout << v[i].size() << ' ';
			for (auto it : v[i]) {
				cout << it << " ";
			}
			cout << "\n";
		}
	}
}