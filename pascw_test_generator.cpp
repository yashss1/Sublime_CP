#include <bits/stdc++.h>
using namespace std;

#define N 100
#define K 100
#define T 100
#define Q 20
#define X 2

// PASC Women Lisa and Queries
void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("inputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main()
{
	init_code();
	srand(time(0));	
					  //IMPPPP....
	long long int t = rand() % T + 1; //Generate a random number between 1 and T.
	t = 1;
	// cout << t << endl;
	for (int tc = 0; tc < t; tc++)
	{
		long long int n = rand() % (N) + 1;
		long long int q = rand() % (Q) + 1;
		n = 500;
		q = 190;

		string s = "";

		// for string
		for (int i = 0; i < n; i++)
		{
			long long int x = (rand() % X);
			if(x == 1) {
				s.push_back('.');
			}else {
				s.push_back('@');
			}
		}


		vector<pair<int, int>> v;
		for(int i = 0; i < q; i++) {
			long long int l = rand() % (n) + 1;
			long long int r = rand() % (n) + l;
			r = min(r, n);
			v.push_back({l, r});
		}

		cout << s << "\n" << q << '\n';
		for(auto it: v) {
			cout << it.first << " " << it.second << '\n';
		}
	}
}